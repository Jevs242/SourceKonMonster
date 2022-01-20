#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "TrabajoFinalPVJACharacter.h"

#include "Enemigo2.generated.h"

UCLASS()
class TRABAJOFINALPVJA_API AEnemigo2 : public AActor
{
	GENERATED_BODY()

public:
	AEnemigo2();

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* PMesh;

	UPROPERTY(EditAnywhere)
		class UBoxComponent* BoxCollision;

	UPROPERTY(VisibleAnywhere, Category = "Damage")
		class USphereComponent* Radio;

	UFUNCTION()
		void BeginOverlap(class UPrimitiveComponent* Overlaped, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void BeginOverlapRadio(class UPrimitiveComponent* Overlaped, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void EndOverlapedComponent(class UPrimitiveComponent* Overlaped, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
		void EndOverlapedRadio(class UPrimitiveComponent* Overlaped, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

protected:

	virtual void BeginPlay() override;

private:


public:

	virtual void Tick(float DeltaTime) override;

public:

	void Bang();

	FVector NewLocation;

	float Dir = 1;

	UPROPERTY(EditAnywhere)
		float Speed = 3;

	UPROPERTY(EditAnywhere)
		int Damage = 10;

	bool Stop = false;

	float SpeedDrop = 1;

	bool Fall = true;

	bool Range = false;

	bool Used = false;

	FTimerHandle FTime;

	ATrabajoFinalPVJACharacter* Jugador;

	UPROPERTY(EditAnywhere)
		USoundBase* Sonidos;

	UPROPERTY(EditAnywhere)
		UParticleSystem* Particulas;

};




