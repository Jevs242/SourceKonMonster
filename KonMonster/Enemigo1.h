#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TrabajoFinalPVJACharacter.h"
#include "Enemigo1.generated.h"

UCLASS()
class TRABAJOFINALPVJA_API AEnemigo1 : public AActor
{
	GENERATED_BODY()

public:
	AEnemigo1();

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* PMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBoxComponent* BoxCollision;

	UFUNCTION()
		void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:

	virtual void BeginPlay() override;

public:
	void DamageF();


public:

	virtual void Tick(float DeltaTime) override;

	FVector NewLocation;
	FVector StartLocation;

	FTimerHandle FTime;

	UPROPERTY(EditAnywhere)
		bool Dir = true;

	UPROPERTY(EditAnywhere)
		int Dist = 1000;

	UPROPERTY(EditAnywhere)
		int Velocidad = 3;

	bool Gira = false;

	bool Damage = true;
};
