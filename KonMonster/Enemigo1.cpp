#include "Enemigo1.h"
#include "Components/BoxComponent.h"

AEnemigo1::AEnemigo1()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	PMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PMesh"));

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));

	PMesh->SetupAttachment(RootComponent);
	BoxCollision->SetupAttachment(PMesh);

	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AEnemigo1::BeginOverlap);
}

void AEnemigo1::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();

	PMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
}

void AEnemigo1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	NewLocation = GetActorLocation();

	if (Dir)
	{

		if (NewLocation.Y < StartLocation.Y + Dist && Gira == false)
		{
			NewLocation.Y += Velocidad;
		}
		else
		{
			Gira = true;
			NewLocation.Y -= Velocidad;
			if (NewLocation.Y <= StartLocation.Y)
			{
				Gira = false;
			}
		}
	}
	else
	{
		if (NewLocation.Z < StartLocation.Z + Dist && Gira == false)
		{
			NewLocation.Z += Velocidad;
		}
		else
		{
			Gira = true;
			NewLocation.Z -= Velocidad;
			if (NewLocation.Z <= StartLocation.Z)
			{
				Gira = false;
			}
		}
	}
	SetActorLocation(NewLocation);
}

void AEnemigo1::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	ATrabajoFinalPVJACharacter* Player = Cast<ATrabajoFinalPVJACharacter>(OtherActor);
	if (Player && Damage)
	{
		Player->Health -= 25;
		Damage = false;
		GetWorld()->GetTimerManager().SetTimer(FTime, this, &AEnemigo1::DamageF, 0.3f, false);
	}
}

void AEnemigo1::DamageF()
{
	Damage = true;
}