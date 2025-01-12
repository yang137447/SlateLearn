// Copyright Epic Games, Inc. All Rights Reserved.

#include "MySlateCommands.h"

#define LOCTEXT_NAMESPACE "FMySlateModule"

void FMySlateCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "MySlate", "Bring up MySlate window", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
