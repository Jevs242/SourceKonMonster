
#include "TrabajoFinalPVJACharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "KonPlayerController.h"
#include "TimerManager.h"
#include "PickUp.h"
#include "Gun.h"

#include "GameFramework/PawnMovementComponent.h"


ATrabajoFinalPVJACharacter::ATrabajoFinalPVJACharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true);
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->TargetArmLength = 500.f;
	CameraBoom->SocketOffset = FVector(0.f, 0.f, 75.f);
	CameraBoom->SetRelativeRotation(FRotator(0.f, 180.f, 0.f));

	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	SideViewCameraComponent->bUsePawnControlRotation = false;

	GetMovementComponent()->GetNavAgentPropertiesRef().bCanCrouch = true;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);
	GetCharacterMovement()->GravityScale = 2.f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;

}


void ATrabajoFinalPVJACharacter::BeginPlay()
{
	Super::BeginPlay();

	Gun = GetWorld()->SpawnActor<AGun>(GunClass);
	Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("Arma_r"));
	Gun->SetOwner(this);

	Municion = MaxMunicion;

	Health = MaxHealth;

	Resistence = MaxResistence;
}


bool ATrabajoFinalPVJACharacter::IsDead() const
{
	return Health <= 0;
}

float ATrabajoFinalPVJACharacter::GetHealthPercent() const
{
	return Health / MaxHealth;
}

float ATrabajoFinalPVJACharacter::GetResistencePercent() const
{
	return Resistence / MaxResistence;
}

float ATrabajoFinalPVJACharacter::GetMunicion() const
{
	return Municion;
}

float ATrabajoFinalPVJACharacter::GetMunicionTotal() const
{
	return MaxMunicion;
}

int ATrabajoFinalPVJACharacter::GetMoneda() const
{
	return Moneda;
}

bool ATrabajoFinalPVJACharacter::GetCrouch() const
{
	return bCrouch;
}



void ATrabajoFinalPVJACharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ATrabajoFinalPVJACharacter::JumpR);

	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &ATrabajoFinalPVJACharacter::CrouchP);

	PlayerInputComponent->BindAction("Fire", EInputEvent::IE_Pressed, this, &ATrabajoFinalPVJACharacter::Fire);

	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAxis("MoveRight", this, &ATrabajoFinalPVJACharacter::MoveRight);

	PlayerInputComponent->BindTouch(IE_Pressed, this, &ATrabajoFinalPVJACharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &ATrabajoFinalPVJACharacter::TouchStopped);
}


void ATrabajoFinalPVJACharacter::MoveRight(float Value)
{
	AddMovementInput(FVector(0.f, -1.f, 0.f), Value);
}

void ATrabajoFinalPVJACharacter::TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	Jump();
}

void ATrabajoFinalPVJACharacter::TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	StopJumping();
}


void ATrabajoFinalPVJACharacter::JumpR()
{
	if (FallCheck == true)
	{
		if (Resistence <= 0)
		{
			CharacterMovement->JumpZVelocity = 0;
		}
		else if (FallCheck && !Croc)
		{
			Resistence -= DownRecovery;
		}

		FallCheck = false;

		GetWorld()->GetTimerManager().SetTimer(FTimerRecovery, this, &ATrabajoFinalPVJACharacter::Recovery, TimeRecovery, false);
		GetWorld()->GetTimerManager().SetTimer(FTimeFall, this, &ATrabajoFinalPVJACharacter::Fall, TimeFall, false);
	}
}

void ATrabajoFinalPVJACharacter::Fast()
{
	CharacterMovement->MaxWalkSpeed = 1200;
	GetWorld()->GetTimerManager().SetTimer(FTimerFast, this, &ATrabajoFinalPVJACharacter::FastNormal, 5.0f, false);
}

void ATrabajoFinalPVJACharacter::FastNormal()
{
	CharacterMovement->MaxWalkSpeed = 600;
}

void ATrabajoFinalPVJACharacter::JumpS()
{

	CharacterMovement->JumpZVelocity = 2000;
	GetWorld()->GetTimerManager().SetTimer(FTimerJump, this, &ATrabajoFinalPVJACharacter::JumpN, 5.0f, false);
}

void ATrabajoFinalPVJACharacter::JumpN()
{

	CharacterMovement->JumpZVelocity = 1000;
	
}

void ATrabajoFinalPVJACharacter::LifeP()
{
	Health += 25;
	if (Health <= 100)
	{
		Health = 100;
	}
}

void ATrabajoFinalPVJACharacter::RecoveryP()
{
	Resistence += 25;
	if (Resistence <= 100)
	{
		Resistence = 100;
	}
}



void ATrabajoFinalPVJACharacter::Fall()
{
	FallCheck = true;
}

void ATrabajoFinalPVJACharacter::Recovery()
{
	if (Resistence < MaxResistence && FallCheck)
	{
		Resistence += RecoveryTick;
	}
	else if (Resistence > MaxResistence && FallCheck)
	{
		Resistence = MaxResistence;
		return;
	}
	if (Resistence >= RecoveryTick)
	{
		CharacterMovement->JumpZVelocity = 1000;
	}
	GetWorld()->GetTimerManager().SetTimer(FTimerRecovery, this, &ATrabajoFinalPVJACharacter::Recovery, 2.f, false);
}

void ATrabajoFinalPVJACharacter::CrouchP()
{

	if (FallCheck && !Croc)
	{
		Crouch();
		Croc = true;
	}
	else if (Croc)
	{
		UnCrouch();
		Croc = false;
	}
}

void ATrabajoFinalPVJACharacter::CrouchR()
{
	if (FallCheck)
	{
		UnCrouch();
		Croc = false;
	}
}

void ATrabajoFinalPVJACharacter::Gravity()
{
	if (GravityActive)
	{
		CharacterMovement->GravityScale = 2.0f;
	}
	else
	{
		CharacterMovement->GravityScale = -2.f;
	}
}

void ATrabajoFinalPVJACharacter::DoubleMonedaEnd()
{
	DoubleMoneda = false;
}

void ATrabajoFinalPVJACharacter::Fire()
{
	if (FallCheck)
	{
		Gun->PullTrigger();
	}

}

void ATrabajoFinalPVJACharacter::PickUp(int ID)
{
	switch (ID)
	{
	case 0:
		Fast();
		break;
	case 1:
		JumpS();
		break;
	case 2:
		LifeP();
		break;
	case 3:
		RecoveryP();
		break;
	case 4:
		DoubleMoneda = true;
		GetWorld()->GetTimerManager().SetTimer(FTimerDMoneda, this, &ATrabajoFinalPVJACharacter::DoubleMonedaEnd, 3.f, false);
		break;
	default:
		break;
	}
}
