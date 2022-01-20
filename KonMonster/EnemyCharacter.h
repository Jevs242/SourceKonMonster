
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class TRABAJOFINALPVJA_API AEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AEnemyCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBoxComponent* BoxCollision;


protected:
	virtual void BeginPlay() override;

	UFUNCTION()
		void BeginOverlap2(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	bool Vuelta = false;


public:
	virtual void Tick(float DeltaTime) override;

	int Health = 0;

	UPROPERTY(EditAnywhere)
		int MaxHealth = 100;

	class ATrabajoFinalPVJACharacter* Jugador;
private:

};
