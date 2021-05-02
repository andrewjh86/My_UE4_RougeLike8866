// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Melee/StatEnum.h"
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CharacterInterface.generated.h"

class UPrimitiveComponent;

// This class does not need to be modified.
UINTERFACE(BlueprintType)
class UCharacterInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */

class ABILITYPLUGIN_API ICharacterInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Events")
		 void ApplyDamage(float NewDamage, UPrimitiveComponent* HitComp);
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Events")
		 void StunCharacter(float NewStun);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Events")
		 void ApplyForce(FVector NewForce);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Events")
		 void ApplyAll(float HitDamage, UPrimitiveComponent* HitComp, float HitStun,FVector HitForce);


};

/*
#include "Character/CharacterInterface.h"
*/