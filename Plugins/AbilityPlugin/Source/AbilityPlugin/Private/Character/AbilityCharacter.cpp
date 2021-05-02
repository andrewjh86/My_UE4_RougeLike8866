// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AbilityCharacter.h"
#include "Melee/Weapon.h"
#include "Kismet/KismetSystemLibrary.h" 
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
AAbilityCharacter::AAbilityCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	

}

// Called when the game starts or when spawned
void AAbilityCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (DefaultWeaponSpawn != nullptr)
	{
		SetupWeapon(DefaultWeaponSpawn);
	}
}




// Called to bind functionality to input
void AAbilityCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AAbilityCharacter::ApplyDamage(float Damage, float StunDuration, FName HitBone, FVector HitForce, EStat HitStat) {
	Health = Health-Damage;
	if (Health <= 0) {
		DeathHandle();
	}
	
	GetCharacterMovement()->Launch(HitForce / Weight);
}

void AAbilityCharacter::SetupWeapon(TSubclassOf<AWeapon> WeaponSpawn) {
	UKismetSystemLibrary::DrawDebugSphere(GetWorld(), GetMesh()->GetSocketLocation(WeaponSocketName), 8.f, 16, FLinearColor::Red, 3.f, 1.0f);
	FActorSpawnParameters ActorSpawnParams;
	ActorSpawnParams.Owner = this;
	ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	AWeapon* Weapon= GetWorld()->SpawnActor<AWeapon>(WeaponSpawn, GetMesh()->GetSocketTransform(WeaponSocketName), ActorSpawnParams);
	Weapon->AttachToComponent(GetMesh(),FAttachmentTransformRules::SnapToTargetIncludingScale,WeaponSocketName);
	if (ActiveWeapon != nullptr) {
		ActiveWeapon->Destroy();
	}
	ActiveWeapon = Weapon;
	UE_LOG(LogTemp, Warning, TEXT("setup suss weapon"));
}

void AAbilityCharacter::DeathHandle() {

}

