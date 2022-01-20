#pragma once

#include "CoreMinimal.h"

#include "TrabajoFinalPVJACharacter.h"
#include "GameFramework/PlayerController.h"
#include "KonPlayerController.generated.h"

UCLASS()
class TRABAJOFINALPVJA_API AKonPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void GameHasEnded(AActor* EndGameFocus, bool bIsWinner) override;

	class ATrabajoFinalPVJACharacter* Jugador;

	void Dead();

	virtual void Tick(float DeltaTime) override;

	class URestartMenu* RestartMenu;

	class APlayerController* Player;
private:
	UPROPERTY(EditAnywhere)
		TSubclassOf<class UUserWidget> HUDClass;
	UPROPERTY(EditAnywhere)
		TSubclassOf<class UUserWidget> WinScreenClass;
	UPROPERTY(EditAnywhere)
		TSubclassOf<class UUserWidget> RestartScreenClass;

	UPROPERTY(EditAnywhere)
		float RestartDelay = 5.f;

	UPROPERTY(EditAnywhere)
		UUserWidget* HUD;

protected:
	virtual void BeginPlay() override;
};
