// Copyright Epic Games, Inc. All Rights Reserved.

#include "Violent_MarioGameMode.h"
#include "Violent_MarioCharacter.h"
#include "UObject/ConstructorHelpers.h"

AViolent_MarioGameMode::AViolent_MarioGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
