
#include "Moneda.h"


#include "TrabajoFinalPVJACharacter.h"
#include "Components/BoxComponent.h"

AMoneda::AMoneda()
{
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	PMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PMesh"));
	PMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));

	PMesh->SetupAttachment(RootComponent);
	BoxCollision->SetupAttachment(PMesh);

	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AMoneda::BeginOverlap);
}

void AMoneda::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ATrabajoFinalPVJACharacter* Jugador = Cast<ATrabajoFinalPVJACharacter>(OtherActor);
	if (Jugador == OtherActor)
	{
		if (Jugador->DoubleMoneda == true)
		{
			Jugador->Moneda += 2;
		}
		else
		{
			Jugador->Moneda++;
		}

		if (Final)
		{
			Jugador->Final=true;
		}
		Destroy();
	}

}

void AMoneda::BeginPlay()
{
	Super::BeginPlay();

}

void AMoneda::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);



}

