// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Melee/Weapon.h"
#include "Gun.generated.h"

class ABullet;
/**
 * Gun for shooting physical projectile.
 */
UCLASS()
class ABILITYPLUGIN_API AGun : public AWeapon
{
	GENERATED_BODY()

		AGun();

public:
	virtual void Press() override;

	virtual void Release() override;

	virtual void ShootGun();

protected:
	FTimerHandle Shoot_TimerHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bullet")
		TSubclassOf<ABullet> ActiveSpawnBullet;
};
