#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/BoxComponent.h"
#include "TrabajoFinalPVJACharacter.h"
#include "Spawner.h"

#include "PickUp.generated.h"

UENUM(Blueprinttype)
namespace PickEnum
{
	enum Type
	{
		Speed,
		Jump,
		Life,
		Recovery,
		DoblePoints


	};
}
USTRUCT(BlueprintType)
struct FPickInfo
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere)
		UStaticMesh* ElMesh[5];

	UPROPERTY(EditAnywhere)
		TEnumAsByte<PickEnum::Type>EPickUp;


};

UCLASS()
class TRABAJOFINALPVJA_API APickUp : public AActor
{
	GENERATED_BODY()

public:
	APickUp();


protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		bool SpawnUsed = true;

public:
	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* PickupMesh;

	UPROPERTY(EditAnywhere)
		class UBoxComponent* Box;

	UFUNCTION()
		void PickUpOverlapped(class UPrimitiveComponent* Overlapped, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bfromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditAnywhere)
		FPickInfo PickupInfo;

	int PickID;
	void WhatPickUp(int ID, AActor* Spawn);

	class ASpawner* GoToSpawn;

	void Collission();

	FTimerHandle TimerCollision;
};
