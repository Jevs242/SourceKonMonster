

#include "Municion.h"

#include "TrabajoFinalPVJACharacter.h"
#include "Components/BoxComponent.h"

AMunicion::AMunicion()
{
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	PMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PMesh"));
	PMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));

	PMesh->SetupAttachment(RootComponent);
	BoxCollision->SetupAttachment(PMesh);

	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AMunicion::BeginOverlap);
}

void AMunicion::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ATrabajoFinalPVJACharacter* Jugador = Cast<ATrabajoFinalPVJACharacter>(OtherActor);
	if (Jugador == OtherActor)
	{


		Jugador->Municion += 30;

		Destroy();
	}
}

void AMunicion::BeginPlay()
{
	Super::BeginPlay();

}

void AMunicion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

