// Fill out your copyright notice in the Description page of Project Settings.


#include "Melee/SwingWeapon.h"
#include "Kismet/GameplayStatics.h"


void ASwingWeapon::Press() {
	if (LastPressTimeStamp + PressRate > GetWorld()->TimeSeconds) {
		return;
	}
	LastPressTimeStamp = GetWorld()->TimeSeconds;

}

void ASwingWeapon::Release() {

}

void ASwingWeapon::WeaponNotifyStart() {

}

void ASwingWeapon::WeaponNotifyEnd() {

}
