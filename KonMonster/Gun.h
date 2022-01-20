
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TrabajoFinalPVJACharacter.h"
#include "Gun.generated.h"

UCLASS()
class TRABAJOFINALPVJA_API AGun : public AActor
{
	GENERATED_BODY()

public:
	AGun();

	void PullTrigger();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	class ATrabajoFinalPVJACharacter* Character;

private:

	UPROPERTY(EditAnywhere)
		class USceneComponent* Spoint;

	UPROPERTY(VisibleAnywhere)
		USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
		USkeletalMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
		UParticleSystem* MuzzleFlash;

	UPROPERTY(EditAnywhere)
		USoundBase* MuzzleSound;

	UPROPERTY(EditAnywhere)
		UParticleSystem* ImpactEffect;

	UPROPERTY(EditAnywhere)
		USoundBase* ImpactSound;

	UPROPERTY(EditAnywhere)
		float MaxRange = 1000;

	UPROPERTY(EditAnywhere)
		float Damage = 10;

	bool bGun = true;



	AController* GetOwnerController() const;
};
