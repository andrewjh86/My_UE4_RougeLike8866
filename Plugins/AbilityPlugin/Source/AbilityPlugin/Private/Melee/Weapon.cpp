// Fill out your copyright notice in the Description page of Project Settings.


#include "Melee/Weapon.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/KismetSystemLibrary.h" 


// Sets default values for this component's properties
AWeapon::AWeapon()
{
	PrimaryActorTick.bCanEverTick = false;

	RootTransform = CreateDefaultSubobject<USceneComponent>(TEXT("Root Transform Point"));
	SetRootComponent(RootTransform);
	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Weapon Mesh"));
	WeaponMesh->SetupAttachment(RootTransform);
	WeaponMesh->SetGenerateOverlapEvents(false);
	WeaponMesh->SetSimulatePhysics(false);
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	AttackTransform = CreateDefaultSubobject<USceneComponent>(TEXT("Attack Transform Point"));
	AttackTransform->SetupAttachment(WeaponMesh);

}


// Called when the game starts
void AWeapon::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
	
}


void AWeapon::Press() {

	UKismetSystemLibrary::DrawDebugSphere(GetWorld(), AttackTransform->GetComponentLocation(), 8.f, 16, FLinearColor::Red, 3.f, 1.0f);
	//TArray < TEnumAsByte < EObjectTypeQuery > >ObjectTypes = { UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Pawn) };
	//TArray<AActor*> ActorsToIgnore = { this };
	//TArray <  UPrimitiveComponent* > OutComponents;
	////UKismetSystemLibrary::SphereOverlapActors(GetWorld(), SpherePos, AttackDistance, ObjectTypes, nullptr, ActorsToIgnore, OutActors);
	//UKismetSystemLibrary::SphereOverlapComponents(GetWorld(), SpherePos, AttackDistance, ObjectTypes, nullptr, ActorsToIgnore, OutComponents);
	//for (auto& Hit : OutComponents)
	//{

	//}

 }

void AWeapon::Release() {

}

void AWeapon::Aim() {

}

void AWeapon::AimRelease() {

}

void AWeapon::WeaponNotifyStart() {

 }

void AWeapon::WeaponNotifyEnd() {

}



