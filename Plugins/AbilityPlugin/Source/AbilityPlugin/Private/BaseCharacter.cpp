// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "Attribute/CharacterAttributeComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CharacterAttributeComponent = CreateDefaultSubobject< UCharacterAttributeComponent>(TEXT("CharacterAttributeComponent"));
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	CharacterAttributeComponent->OnDeath.BindUObject(this, &ABaseCharacter::DeathHandle);
}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void ABaseCharacter::DeathHandle() {


 }

void ABaseCharacter::ApplyDamage_Implementation(float NewDamage)
{
	CharacterAttributeComponent->ApplyDamage(NewDamage);
 }

 void ABaseCharacter::StunCharacter_Implementation(float NewStun)
 {
	 
 }

 void ABaseCharacter::ApplyForce_Implementation(FVector NewForce)
 {
	 GetCharacterMovement()->Launch(NewForce);
 }

 void ABaseCharacter::ApplyAll_Implementation(float NewDamage, float NewStun, FVector NewForce)
 {
	 ApplyDamage_Implementation(NewDamage);
	 ApplyForce_Implementation(NewForce);
 }

