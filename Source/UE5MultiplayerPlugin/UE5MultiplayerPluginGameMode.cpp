// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE5MultiplayerPluginGameMode.h"
#include "UE5MultiplayerPluginCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE5MultiplayerPluginGameMode::AUE5MultiplayerPluginGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
