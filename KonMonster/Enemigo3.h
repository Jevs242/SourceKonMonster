
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemigo3.generated.h"

UCLASS()
class TRABAJOFINALPVJA_API AEnemigo3 : public AActor
{
	GENERATED_BODY()

public:
	AEnemigo3();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBoxComponent* BoxCollision;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* PMesh;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;


	int Life = 0;

	UPROPERTY(EditAnywhere)
		int LifeMax = 100;
};
