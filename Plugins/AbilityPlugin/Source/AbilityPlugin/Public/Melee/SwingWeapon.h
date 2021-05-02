// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Melee/Weapon.h"
#include "SwingWeapon.generated.h"

/**
 *
 */

UCLASS()
class ABILITYPLUGIN_API ASwingWeapon : public AWeapon
{
	GENERATED_BODY()


public:
	virtual void Press() override;

	virtual void Release() override;

	virtual void WeaponNotifyStart() override;

	virtual void WeaponNotifyEnd() override;



protected:
	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Damage Property")
	//	EStat Stat;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage Property")
		float StunDuration = 0.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage Property")
		float Damage = 1.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage Property")
		float Force = 1.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage Property")
		float Weight = 1.f;

	//virtual void SwingTick();
};
