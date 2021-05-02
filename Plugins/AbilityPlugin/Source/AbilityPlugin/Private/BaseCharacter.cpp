// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "Attribute/CharacterAttributeComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetSystemLibrary.h" 


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
	Destroy();
}

//void ABaseCharacter::ApplyDamage_Implementation(float NewDamage, UPrimitiveComponent* HitComp);
//{
//	CharacterAttributeComponent->ApplyDamage(NewDamage);
//}
//
//void ABaseCharacter::StunCharacter_Implementation(float NewStun)
//{
//	StunCharacter_BP(NewStun);
//}
//
//void ABaseCharacter::ApplyForce_Implementation(FVector NewForce)
//{
//	ApplyForce_BP(NewForce);
//	GetCharacterMovement()->Launch(NewForce);
//}
//
//void ABaseCharacter::ApplyAll_Implementation(float NewDamage, UPrimitiveComponent* HitComp, float NewStun, FVector NewForce);
//{
//	ApplyDamage_Implementation(NewDamage);
//	StunCharacter_Implementation(NewStun);
//	ApplyForce_Implementation(NewForce);
//}
//
//
//
//void ABaseCharacter::Attack() {
//	FVector SpherePos = GetActorForwardVector() * AttackDistance + GetActorLocation();
//	UKismetSystemLibrary::DrawDebugSphere(GetWorld(), SpherePos, AttackDistance, 16, FLinearColor::Black, 3.f, 1.0f);
//	TArray < TEnumAsByte < EObjectTypeQuery > >ObjectTypes = { UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Pawn) };
//	TArray<AActor*> ActorsToIgnore = { this };
//	TArray <  AActor* > OutActors;
//	UKismetSystemLibrary::SphereOverlapActors(GetWorld(), SpherePos, AttackDistance, ObjectTypes, nullptr, ActorsToIgnore, OutActors);
//
//	for (auto& HitActor : OutActors)
//	{
//		if (ICharacterInterface* CharacterInterface = Cast<ICharacterInterface>(HitActor))
//		{
//
//
//			//CharacterInterface->Execute_ApplyAll(HitActor, Damage, 1.f, GetActorForwardVector() * Power);
//		}
//	}
//}

