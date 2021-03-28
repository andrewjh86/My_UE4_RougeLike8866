// Fill out your copyright notice in the Description page of Project Settings.


#include "Attribute/CharacterAttributeComponent.h"



// Called when the game starts
void UCharacterAttributeComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	IntitializeAttributesToBase();
}




// Sets default values for this component's properties
UCharacterAttributeComponent::UCharacterAttributeComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}


void UCharacterAttributeComponent::UpgradeHealth(float amount)
{
	float Increase = BaseHealth / (BaseHealth + amount) * Health;
	BaseHealth += amount;
	ApplyDamage(-Increase);
}

void UCharacterAttributeComponent::ApplyDamage(float amount)
{
	Health = FMath::Clamp(Health - amount, 0.0f, BaseHealth);

	if (Health <= 0.0f)
	{
		bDead = true;
		OnDeath.ExecuteIfBound();
	}
}

void UCharacterAttributeComponent::UpgradeStamina(float amount)
{
	float Increase = BaseStamina / (BaseStamina + amount) * Stamina; 
	BaseStamina += amount;
	AddStamina(Increase);
}

void UCharacterAttributeComponent::AddStamina(float amount)
{
	Stamina = FMath::Clamp(Stamina + amount, 0.0f, BaseStamina);

}

void UCharacterAttributeComponent::IntitializeAttributesToBase() {
	Health = BaseHealth;
	Stamina = BaseStamina;


}

