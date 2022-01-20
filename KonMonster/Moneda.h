
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Moneda.generated.h"

UCLASS()
class TRABAJOFINALPVJA_API AMoneda : public AActor
{
	GENERATED_BODY()

public:
	AMoneda();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBoxComponent* BoxCollision;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* PMesh;

	UFUNCTION()
		void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditAnywhere)
	bool Final = false;

protected:
	virtual void BeginPlay() override;


public:
	virtual void Tick(float DeltaTime) override;
};
