// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Weapon_INT.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UWeapon_INT : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */

//#include "Melee/Weapon.h"
class AWeapon;

class ABILITYPLUGIN_API IWeapon_INT
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual AWeapon* GetWeapon() { return nullptr; };
};
