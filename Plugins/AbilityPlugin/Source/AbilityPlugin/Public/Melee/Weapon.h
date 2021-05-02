// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"


class USoundBase;
class UStaticMeshComponent;

UCLASS()
class ABILITYPLUGIN_API AWeapon : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	AWeapon();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	/**in seconds the pause between bullets*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
		float PressRate = 0.1f;

	UPROPERTY()
		float LastPressTimeStamp;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
		USoundBase* PressSound;

	UPROPERTY( EditAnywhere, BlueprintReadOnly, Category = "Mesh")
		UStaticMeshComponent* WeaponMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mesh")
		USceneComponent* AttackTransform;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mesh")
		USceneComponent* RootTransform;


public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Mesh")
		UStaticMeshComponent* GetMesh() { return WeaponMesh; };

	UFUNCTION(BlueprintCallable, Category = "Input")
		virtual void Press();

	UFUNCTION(BlueprintCallable, Category = "Input")
		virtual void Release();

	UFUNCTION(BlueprintCallable, Category = "Input")
		virtual void Aim();

	UFUNCTION(BlueprintCallable, Category = "Input")
		virtual void AimRelease();

	UFUNCTION(BlueprintCallable, Category = "Animation")
		virtual void WeaponNotifyStart();

	UFUNCTION(BlueprintCallable, Category = "Animation")
		virtual void WeaponNotifyEnd();

};
