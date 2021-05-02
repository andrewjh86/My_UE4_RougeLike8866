// Fill out your copyright notice in the Description page of Project Settings.


#include "Melee/Bullet.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h" 
#include "Melee/Damage_INT.h"

// Sets default values
ABullet::ABullet()
{
	PrimaryActorTick.bCanEverTick = false;

	// Use a sphere as a simple collision representation
	BulletCollision = CreateDefaultSubobject<USphereComponent>(TEXT("Bullet Sphere Collision"));
	BulletCollision->InitSphereRadius(50.0f);
	BulletCollision->SetGenerateOverlapEvents(true);
	BulletCollision->SetCollisionProfileName("BlockAll");
	RootComponent = BulletCollision;
	BulletCollision->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	BulletCollision->CanCharacterStepUpOn = ECB_No;

	BulletMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bullet Mesh"));
	BulletMesh->SetupAttachment(BulletCollision);
	//BulletMesh->SetGenerateOverlapEvents(false);
	//BulletMesh->SetSimulatePhysics(false);
	BulletMesh->SetCollisionProfileName("NoCollision");
	//BulletMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	BulletMesh->CanCharacterStepUpOn = ECB_No;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->UpdatedComponent = BulletCollision;
	ProjectileMovement->InitialSpeed = 2000.F;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	// Die after 3 seconds by default
	InitialLifeSpan = 4.0f;

	//Debug
	BulletCollision->SetHiddenInGame(false);

}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	BulletCollision->OnComponentHit.AddDynamic(this, &ABullet::OnHit);

}


void ABullet::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	
	if (IDamage_INT* Damage_INT = Cast<IDamage_INT>(OtherActor))
	{
		
		Damage_INT->ApplyDamage( Damage,  StunDuration,  Hit.BoneName, ProjectileMovement->Velocity *Force, Stat);

	}



}

