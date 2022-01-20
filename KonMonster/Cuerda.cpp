

#include "Cuerda.h"

#include "Components/BoxComponent.h"

ACuerda::ACuerda()
{
	PrimaryActorTick.bCanEverTick = true;

	PMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PMesh"));
	PMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));

	PMesh->SetupAttachment(RootComponent);
	Box->SetupAttachment(PMesh);


}

void ACuerda::BeginPlay()
{
	Super::BeginPlay();
	Box->OnComponentBeginOverlap.AddDynamic(this, &ACuerda::BeginOverlap);
	Box->OnComponentEndOverlap.AddDynamic(this, &ACuerda::EndOverlapedComponent);

}

void ACuerda::BeginOverlap(UPrimitiveComponent* Overlapped, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bfromSweep, const FHitResult& SweepResult)
{
	ATrabajoFinalPVJACharacter* Player = Cast<ATrabajoFinalPVJACharacter>(OtherActor);
	if (Player == OtherActor)
	{
		Player->GravityActive = false;
		Player->Gravity();
	}
}

void ACuerda::EndOverlapedComponent(UPrimitiveComponent* Overlaped, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	ATrabajoFinalPVJACharacter* Player = Cast<ATrabajoFinalPVJACharacter>(OtherActor);
	if (Player == OtherActor)
	{
		Player->GravityActive = true;
		Player->Gravity();

	}
}

void ACuerda::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

