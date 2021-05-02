// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/DamageBall.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h" 
#include "Character/CharacterInterface.h"

// Sets default values
ADamageBall::ADamageBall()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	CollisionComp->InitSphereRadius(50.0f);
	CollisionComp->SetCollisionProfileName("Projectile");
	RootComponent = CollisionComp;

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	BallMesh->SetupAttachment(CollisionComp);
	BallMesh->SetGenerateOverlapEvents(false);
	BallMesh->SetSimulatePhysics(false);
	BallMesh->SetCollisionProfileName("NoCollision");

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 2000.F;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	// Die after 3 seconds by default
	InitialLifeSpan = 4.0f;

	//Debug:
	CollisionComp->SetHiddenInGame(false);

}

//set gameplay settings
void ADamageBall::BeginPlay() {
	CollisionComp->OnComponentHit.AddDynamic(this, &ADamageBall::OnHit);		

}

void ADamageBall::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != nullptr))
	{
		if (ICharacterInterface* CharacterInterface = Cast<ICharacterInterface>(OtherActor))
		{
			//CharacterInterface->Execute_ApplyAll(OtherActor, Damage, 0.f, GetActorForwardVector() * Power);
			Destroy();
		}

	}
}

