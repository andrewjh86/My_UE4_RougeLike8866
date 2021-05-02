// Fill out your copyright notice in the Description page of Project Settings.


#include "Melee/Gun.h"
#include "TimerManager.h"
#include "Melee/Bullet.h"

//Previous class
#include "Kismet/GameplayStatics.h"

AGun::AGun() {
	
	
}

void AGun::Press() {

	if (LastPressTimeStamp + PressRate > GetWorld()->TimeSeconds) {
		return;
	}
	GetWorld()->GetTimerManager().SetTimer(Shoot_TimerHandle, this, &AGun::ShootGun, PressRate, true, 0.0F);

}

void AGun::Release() {
	GetWorld()->GetTimerManager().ClearTimer(Shoot_TimerHandle);

}

void AGun::ShootGun() {

	FActorSpawnParameters ActorSpawnParams;
	ActorSpawnParams.Owner = GetOwner();
	ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
	ABullet* ActiveBullet = GetWorld()->SpawnActor<ABullet>(ActiveSpawnBullet, AttackTransform->GetComponentTransform(), ActorSpawnParams);

	// try and play the sound if specified
	if (PressSound != nullptr)
	{
		UGameplayStatics::PlaySoundAtLocation(this, PressSound, AttackTransform->GetComponentLocation());
	}
	LastPressTimeStamp = GetWorld()->TimeSeconds;

}










