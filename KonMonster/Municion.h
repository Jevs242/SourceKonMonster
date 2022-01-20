
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Municion.generated.h"

UCLASS()
class TRABAJOFINALPVJA_API AMunicion : public AActor
{
	GENERATED_BODY()

public:
	AMunicion();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBoxComponent* BoxCollision;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* PMesh;

	UFUNCTION()
		void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	virtual void BeginPlay() override;


public:
	virtual void Tick(float DeltaTime) override;

};
