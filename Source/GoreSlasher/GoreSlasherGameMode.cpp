// Copyright Epic Games, Inc. All Rights Reserved.

#include "GoreSlasherGameMode.h"
#include "GoreSlasherCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGoreSlasherGameMode::AGoreSlasherGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
