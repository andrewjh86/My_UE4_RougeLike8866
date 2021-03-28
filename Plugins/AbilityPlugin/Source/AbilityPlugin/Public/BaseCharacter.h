// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Character/CharacterInterface.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"


class UStaticMeshComponent;
class USceneComponent;
class UCharacterAttributeComponent;

UCLASS()
class ABILITYPLUGIN_API ABaseCharacter : public ACharacter, public ICharacterInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//UCharacterAttributeComponent* GetCharacterAttributeComponent() const override { return CharacterAttributeComponent; }

	UFUNCTION(BlueprintCallable, Category = Attribute)
		virtual void DeathHandle();

	void ApplyDamage_Implementation(float NewDamage);
	void StunCharacter_Implementation(float NewStun);
	void ApplyForce_Implementation(FVector NewForce);
	void ApplyAll_Implementation(float NewDamage, float NewStun, FVector NewForce);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Atribute)
		UCharacterAttributeComponent* CharacterAttributeComponent;





};

