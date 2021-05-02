// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DamageBall.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UStaticMeshComponent;
class ABaseCharacter;

UCLASS()
class ABILITYPLUGIN_API ADamageBall : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADamageBall();


protected:
	// Sets default values for this actor's properties

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Cosmetics)
		USphereComponent* CollisionComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Cosmetics)
		UStaticMeshComponent* BallMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Melee)
		float Damage = 20.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Melee)
		float Power = 1500.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Projectile, meta = (AllowPrivateAccess = "true"))
		UProjectileMovementComponent* ProjectileMovement;

	virtual void BeginPlay() override;

public:


	UFUNCTION()
		virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION(BlueprintPure, BlueprintCallable, Category = Melee)
		UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }


};
