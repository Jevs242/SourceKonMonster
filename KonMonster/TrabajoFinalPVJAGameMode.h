// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TrabajoFinalPVJAGameMode.generated.h"

UCLASS(minimalapi)
class ATrabajoFinalPVJAGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATrabajoFinalPVJAGameMode();

public:
	virtual void PawnKilled(APawn* PawnKilled);

private:
	void EndGame(bool bIsPlayerWinner);
};




