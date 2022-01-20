
#include "Gun.h"

#include "Enemigo3.h"
#include "EnemyCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

AGun::AGun()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);
	Spoint = CreateDefaultSubobject<USceneComponent>(TEXT("SpawnPoint"));
	Spoint->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);



}

void AGun::PullTrigger()
{
	FHitResult* Hitresult = new FHitResult();
	FVector StartTrace = Spoint->GetComponentLocation();
	FVector ForwardVector = Spoint->GetForwardVector();
	FVector EndTrace = (ForwardVector * 500.f) + StartTrace;

	//DrawDebugLine(GetWorld(), StartTrace, EndTrace, FColor::Red, true, 3.0f);
	if (Character->Municion > 0)
	{
		UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, Spoint, TEXT("MuzzleFlashSocket"));
		UGameplayStatics::SpawnSoundAttached(MuzzleSound, Spoint, TEXT("MuzzleFlashSocket"));
		//DrawDebugLine(GetWorld(), StartTrace, EndTrace, FColor::Red, true, 3.0f);
		if (GetWorld()->LineTraceSingleByChannel(*Hitresult, StartTrace, EndTrace, ECC_Visibility))
		{
			AEnemigo3* Hit = Cast<AEnemigo3>(Hitresult->GetActor());
			if (Hit)
			{
				Hit->Life -= Damage;

				if (Hit->Life <= 0)
				{
					Hit->Destroy();
				}
			}
			AEnemyCharacter* Hit2 = Cast<AEnemyCharacter>(Hitresult->GetActor());
			if (Hit2)
			{
				Hit2->Health -= Damage;

				if (Hit2->Health <= 0)
				{
					Hit2->Destroy();
				}

			}
		}
		Character->Municion--;
	}
	else
	{

	}
}

void AGun::BeginPlay()
{
	Super::BeginPlay();
	Character = Cast<ATrabajoFinalPVJACharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

}

void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

AController* AGun::GetOwnerController() const
{
	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	if (OwnerPawn == nullptr)
		return nullptr;
	return OwnerPawn->GetController();

}

