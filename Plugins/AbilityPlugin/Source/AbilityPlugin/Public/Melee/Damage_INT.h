// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Melee/StatEnum.h"
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Damage_INT.generated.h"

//enum EStat : uint8;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UDamage_INT : public UInterface
{
	GENERATED_BODY()
};

/**
 *
 */
class ABILITYPLUGIN_API IDamage_INT
{
	GENERATED_BODY()
		//#include "Melee/Damage_INT.h"

public:
	//UFUNCTION(Category = "DamageInterface")
	virtual void ApplyDamage(float Damage, float StunDuration, FName HitBone, FVector HitForce, EStat HitStat) {};
};
