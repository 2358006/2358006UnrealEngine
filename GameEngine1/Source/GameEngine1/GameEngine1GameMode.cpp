// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameEngine1GameMode.h"
#include "GameEngine1Character.h"
#include "UObject/ConstructorHelpers.h"

AGameEngine1GameMode::AGameEngine1GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
