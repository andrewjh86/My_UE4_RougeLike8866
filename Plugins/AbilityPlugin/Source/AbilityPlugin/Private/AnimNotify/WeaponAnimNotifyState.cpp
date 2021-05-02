// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotify/WeaponAnimNotifyState.h"
#include "Melee/Weapon_INT.h"
#include "Melee/Weapon.h"




void UWeaponAnimNotifyState::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration) {
	if (IWeapon_INT* Weapon_INT = Cast<IWeapon_INT>(MeshComp->GetOwner())) {
		Weapon_INT->GetWeapon()->WeaponNotifyStart();
	}

}

void UWeaponAnimNotifyState::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) {
	if (IWeapon_INT* Weapon_INT = Cast<IWeapon_INT>(MeshComp->GetOwner())) {
		Weapon_INT->GetWeapon()->WeaponNotifyEnd();
	}
}

