
#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TrabajoFinalPVJACharacter.h"
#include "EnemyAIController.generated.h"


UCLASS()
class TRABAJOFINALPVJA_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()


protected:


	virtual void BeginPlay() override;

public:
	AEnemyAIController();

	virtual void Tick(float DeltaTime) override;

private:

};
