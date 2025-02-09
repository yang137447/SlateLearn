// Copyright Epic Games, Inc. All Rights Reserved.

#include "SlateLearnGameMode.h"
#include "SlateLearnCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASlateLearnGameMode::ASlateLearnGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
