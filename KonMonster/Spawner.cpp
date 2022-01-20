
#include "Spawner.h"
#include "Components/StaticMeshComponent.h"
#include "PickUp.h"
#include "Enemigo2.h"
#include "TimerManager.h"

ASpawner::ASpawner()
{
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Spoint = CreateDefaultSubobject<USceneComponent>(TEXT("SpawnPoint"));

	Mesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	Spoint->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void ASpawner::BeginPlay()
{
	Super::BeginPlay();

	if (SpawnOpc)
	{
		SpawnEnemy();
	}
	else
	{
		SpawnPickUp();
	}

}

void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawner::SpawnEnemy()
{
	if (SpawnEnemigo != NULL)
	{
		FActorSpawnParameters SpawnParams;

		FVector SpawnLocation = Spoint->GetComponentLocation();
		FRotator Spawnrotation = FRotator::ZeroRotator;

		AEnemigo2* Enemy = GetWorld()->SpawnActor<AEnemigo2>
			(SpawnEnemigo, SpawnLocation, Spawnrotation, SpawnParams);
		SpawnEnemyTimer();
	}
}

void ASpawner::SpawnPickUp()
{
	if (SpawnObject != NULL)
	{
		FActorSpawnParameters SpawnParams;

		FVector SpawnLocation = Spoint->GetComponentLocation();
		FRotator Spawnrotation = FRotator::ZeroRotator;

		APickUp* PickUp = GetWorld()->SpawnActor<APickUp>
			(SpawnObject, SpawnLocation, Spawnrotation, SpawnParams);

		PickUp->WhatPickUp(FMath::RandRange(0, 4), this);
	}
}

void ASpawner::SpawnEnemyTimer()
{
	GetWorldTimerManager().SetTimer(FTimerEnemy, this, &ASpawner::SpawnEnemy, 5.0, false);
}

void ASpawner::SpawnPickUpTimer()
{
	GetWorldTimerManager().SetTimer(FTimerPickUp, this, &ASpawner::SpawnPickUp, 5.0, false);
}

