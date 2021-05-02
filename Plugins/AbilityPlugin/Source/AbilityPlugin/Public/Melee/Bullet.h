// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Melee/StatEnum.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

class UProjectileMovementComponent;
class USphereComponent;
class UStaticMeshComponent;

UCLASS()
class ABILITYPLUGIN_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABullet();

	UFUNCTION()
		virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	//UFUNCTION()
 //virtual void	OnProjectileBounce(const FHitResult&, ImpactResult, const FVector&, ImpactVelocity );

	UFUNCTION(BlueprintPure, BlueprintCallable, Category = "Bullet Movement")
		UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Damage Property")
		EStat Stat = EStat::Normal;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Damage Property")
		float StunDuration = 0.f;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Damage Property")
		float Damage = 1.f;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Damage Property")
		float Force = 1.f;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Damage Property")
		float Weight = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "3D Cosmetic")
		USphereComponent* BulletCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "3D Cosmetic")
		UStaticMeshComponent* BulletMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Bullet Movement", meta = (AllowPrivateAccess = "true"))
		UProjectileMovementComponent* ProjectileMovement;



};
