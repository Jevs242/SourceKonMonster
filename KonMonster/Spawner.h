#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

UCLASS()
class TRABAJOFINALPVJA_API ASpawner : public AActor
{
	GENERATED_BODY()

public:
	ASpawner();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
		class USceneComponent* Spoint; int PickID;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class APickUp> SpawnObject;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class AEnemigo2> SpawnEnemigo;

	void SpawnEnemy();

	void SpawnPickUp();

	void SpawnEnemyTimer();

	void SpawnPickUpTimer();

	FTimerHandle FTimerEnemy;
	FTimerHandle FTimerPickUp;

	UPROPERTY(EditAnywhere)
		bool SpawnOpc = false;
};
