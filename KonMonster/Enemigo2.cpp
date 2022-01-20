#include "Enemigo2.h"

#include "Kismet/GameplayStatics.h"

AEnemigo2::AEnemigo2()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	PMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PMesh"));
	PMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));

	Radio = CreateDefaultSubobject<USphereComponent>(TEXT("CSphere"));
	Radio->SetSphereRadius(110.0f);

	PMesh->SetupAttachment(RootComponent);
	Radio->SetupAttachment(PMesh);
	BoxCollision->SetupAttachment(PMesh);

	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AEnemigo2::BeginOverlap);
	BoxCollision->OnComponentEndOverlap.AddDynamic(this, &AEnemigo2::EndOverlapedComponent);
}

void AEnemigo2::BeginPlay()
{
	Super::BeginPlay();

	Radio->OnComponentBeginOverlap.AddDynamic(this, &AEnemigo2::BeginOverlapRadio);
	Radio->OnComponentEndOverlap.AddDynamic(this, &AEnemigo2::EndOverlapedRadio);
	Jugador = Cast<ATrabajoFinalPVJACharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	Fall = true;

	SpeedDrop = Speed;

	if (SpeedDrop < 0)
	{
		SpeedDrop *= -1;
	}
}

void AEnemigo2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Stop == false)
	{
		NewLocation = GetActorLocation();

		NewLocation.Y += Dir * Speed;
		if (Fall)
			NewLocation.Z -= Dir * SpeedDrop;
		SetActorLocation(NewLocation);
	}
}

void AEnemigo2::BeginOverlap(UPrimitiveComponent* Overlaped, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ATrabajoFinalPVJACharacter* Player = Cast<ATrabajoFinalPVJACharacter>(OtherActor);
	if (Player && !Fall)
	{
		Stop = true;
	}

	if (GetActorLocation().Z > OtherActor->GetActorLocation().Z && !Player)
	{
		Fall = false;
	}
	else
	{
		Fall = true;
	}
}

void AEnemigo2::BeginOverlapRadio(UPrimitiveComponent* Overlaped, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	ATrabajoFinalPVJACharacter* Player = Cast<ATrabajoFinalPVJACharacter>(OtherActor);
	if (Player == OtherActor)
	{
		GetWorld()->GetTimerManager().SetTimer(FTime, this, &AEnemigo2::Bang, 0.3f, false);
		Range = true;
	}
	else
	{
		return;
	}
}

void AEnemigo2::EndOverlapedComponent(UPrimitiveComponent* Overlaped, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (GetActorLocation().Z > OtherActor->GetActorLocation().Z)
	{
		Fall = true;
	}
}

void AEnemigo2::EndOverlapedRadio(UPrimitiveComponent* Overlaped, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	ATrabajoFinalPVJACharacter* Player = Cast<ATrabajoFinalPVJACharacter>(OtherActor);
	if (Player == OtherActor)
	{
		Range = false;
	}
}

void AEnemigo2::Bang()
{
	if (Jugador && Range)
	{
		Jugador->Health -= Damage;
	}
	if (Sonidos != NULL)
	{
		UGameplayStatics::PlaySoundAtLocation(this, Sonidos, GetActorLocation());
	}
	if (Particulas != NULL)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Particulas, GetActorLocation(), FRotator::ZeroRotator);
	}
	Destroy();
}