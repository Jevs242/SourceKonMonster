// Copyright Epic Games, Inc. All Rights Reserved.

#include "TrabajoFinalPVJAGameMode.h"
#include "TrabajoFinalPVJACharacter.h"
#include "UObject/ConstructorHelpers.h"

ATrabajoFinalPVJAGameMode::ATrabajoFinalPVJAGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

}

void ATrabajoFinalPVJAGameMode::PawnKilled(APawn* PawnKilled)
{

}

void ATrabajoFinalPVJAGameMode::EndGame(bool bIsPlayerWinner)
{


}
