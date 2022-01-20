

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TrabajoFinalPVJACharacter.h"
#include "Cuerda.generated.h"

UCLASS()
class TRABAJOFINALPVJA_API ACuerda : public AActor
{
	GENERATED_BODY()

public:
	ACuerda();

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* PMesh;

	UPROPERTY(EditAnywhere)
		class UBoxComponent* Box;

	UFUNCTION()
		void BeginOverlap(class UPrimitiveComponent* Overlapped, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bfromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void EndOverlapedComponent(class UPrimitiveComponent* Overlaped, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

};
