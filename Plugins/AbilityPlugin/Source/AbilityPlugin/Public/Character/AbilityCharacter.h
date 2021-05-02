// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Melee/StatEnum.h"
#include "Melee/Weapon_INT.h"
#include "Melee/Damage_INT.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilityCharacter.generated.h"

class AWeapon;

UCLASS()
class ABILITYPLUGIN_API AAbilityCharacter : public ACharacter, public IDamage_INT, public IWeapon_INT
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAbilityCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
		AWeapon* ActiveWeapon=nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
		TSubclassOf<AWeapon> DefaultWeaponSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
		FName WeaponSocketName = "";

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		virtual void SetupWeapon(TSubclassOf<AWeapon> WeaponSpawn);

	UFUNCTION(BlueprintCallable, Category = "Character Attribute")
		virtual void DeathHandle();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Attribute")
		EStat Stat=EStat::Normal;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Attribute")
		float Health = 1.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Attribute")
		float Strength = 1.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Attribute")
		float Weight = 1.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Attribute")
		float StunResistance = 1.f;


public:

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Character Attribute")
	virtual void ApplyDamage(float Damage, float StunDuration, FName HitBone, FVector HitForce, EStat HitStat) override;

	virtual AWeapon* GetWeapon()override { return ActiveWeapon; };

	//Gun->AttatchToComponetent(GetMesh(),FAttachmentTransformRules::KeepRelativeTransform,TEXT("Socket"));
};
