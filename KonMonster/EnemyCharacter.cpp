
#include "EnemyCharacter.h"
#include "EnemyAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Perception/PawnSensingComponent.h"
#include "Engine.h"

AEnemyCharacter::AEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));

	BoxCollision->SetupAttachment(RootComponent);

	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AEnemyCharacter::BeginOverlap2);
}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	Health = MaxHealth;
}



void AEnemyCharacter::BeginOverlap2(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ATrabajoFinalPVJACharacter* Player = Cast<ATrabajoFinalPVJACharacter>(OtherActor);
	if (Player)
	{
		Player->Health -= 25;
		return;
	}
}


void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

