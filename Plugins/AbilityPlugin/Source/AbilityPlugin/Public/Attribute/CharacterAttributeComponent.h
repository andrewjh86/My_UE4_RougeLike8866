// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CharacterAttributeComponent.generated.h"



DECLARE_DELEGATE(FOnDeath);

/*
This is for handling character attributes.
On death delegate is triggered 
*/
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ABILITYPLUGIN_API UCharacterAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UCharacterAttributeComponent();

	UPROPERTY(EditAnywhere,Category = "Attributes_Dynamic")
		bool bDead = false;

	UPROPERTY(EditAnywhere, Category = "Attributes_Dynamic")
		bool bStun = false;

	UPROPERTY( BlueprintReadWrite, Category = "Attributes_Dynamic")
		float Health;

	UPROPERTY( BlueprintReadWrite, Category = "Attributes_Dynamic")
		float Stamina;


		FOnDeath OnDeath;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes_Static")
		float BaseHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes_Static")
		float BaseStamina;

	UFUNCTION()
		void IntitializeAttributesToBase();

public:
	//Stats:
	UPROPERTY(EditAnywhere, Category = "Attributes_Static")
		float Defense;




public:

	UFUNCTION(BlueprintCallable, Category = "Attributes_Static")
		void UpgradeHealth(float amount);

	UFUNCTION(BlueprintCallable, Category = "Attributes_Dynamic")
		void ApplyDamage(float amount);

	UFUNCTION(BlueprintCallable, Category = "Attributes_Static")
		void UpgradeStamina(float amount);

	UFUNCTION(BlueprintCallable, Category = "Attributes_Dynamic")
		void AddStamina(float amount);

	//
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

};

