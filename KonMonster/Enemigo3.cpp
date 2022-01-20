
#include "Enemigo3.h"
#include "Components/BoxComponent.h"

AEnemigo3::AEnemigo3()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	PMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PMesh"));

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));

	PMesh->SetupAttachment(RootComponent);
	BoxCollision->SetupAttachment(PMesh);

}

void AEnemigo3::BeginPlay()
{
	Super::BeginPlay();
	PMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Life = LifeMax;

}

void AEnemigo3::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
