
#include "PickUp.h"
#include "Components/StaticMeshComponent.h"


APickUp::APickUp()
{
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	PickupMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	PickupMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	Box->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	Box->OnComponentBeginOverlap.AddDynamic(this, &APickUp::PickUpOverlapped);
	Box->SetCollisionEnabled(ECollisionEnabled::NoCollision);


}

void APickUp::BeginPlay()
{
	Super::BeginPlay();

	PickupMesh->SetStaticMesh(PickupInfo.ElMesh[PickupInfo.EPickUp]);
	GetWorld()->GetTimerManager().SetTimer(TimerCollision, this, &APickUp::Collission, 1.0f, false);

}

void APickUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Collission();
}

void APickUp::PickUpOverlapped(UPrimitiveComponent* Overlapped, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bfromSweep, const FHitResult& SweepResult)
{
	ATrabajoFinalPVJACharacter* Player = Cast<ATrabajoFinalPVJACharacter>(OtherActor);
	if (Player)
	{

		if (SpawnUsed)
		{
			GoToSpawn->SpawnPickUpTimer();

			Player->PickUp(PickID);
		}
		else
		{
			Player->PickUp(PickupInfo.EPickUp);
		}

		Destroy();
	}
}

void APickUp::WhatPickUp(int ID, AActor* Spawn)
{
	GoToSpawn = Cast<ASpawner>(Spawn);
	PickID = ID;
	PickupMesh->SetStaticMesh(PickupInfo.ElMesh[ID]);
}

void APickUp::Collission()
{
	Box->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
}
