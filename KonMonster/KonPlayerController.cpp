
#include "KonPlayerController.h"

#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"



void AKonPlayerController::BeginPlay()
{
	Super::BeginPlay();
	HUD = CreateWidget(this, HUDClass);
	if (HUD != nullptr)
	{
		HUD->AddToViewport();
	}
	Jugador = Cast<ATrabajoFinalPVJACharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}



void AKonPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);
}


void AKonPlayerController::Tick(float DeltaTime)
{
	Dead();
}


void AKonPlayerController::Dead()
{
	if (Jugador->Health <= 0)
	{
		//Jugador -> Destroy();

		HUD->RemoveFromViewport();

		APlayerController* const MyPlayer = Cast<APlayerController>(GEngine->GetFirstLocalPlayerController(GetWorld()));
		if (MyPlayer != NULL)
		{
			MyPlayer->SetPause(true);
			MyPlayer->bShowMouseCursor = true;
		}
		UUserWidget* MenuRestartScreen = CreateWidget(this, RestartScreenClass);
		if (MenuRestartScreen != nullptr)
		{
			MenuRestartScreen->AddToViewport();
		}

	}
	else if (Jugador->Final)
	{
		HUD->RemoveFromViewport();
		APlayerController* const MyPlayer = Cast<APlayerController>(GEngine->GetFirstLocalPlayerController(GetWorld()));
		if (MyPlayer != NULL)
		{
			MyPlayer->SetPause(true);
			MyPlayer->bShowMouseCursor = true;
		}
		UUserWidget* Win = CreateWidget(this, WinScreenClass);
		if (Win != nullptr)
		{
			Win->AddToViewport();
		}
	}
}
