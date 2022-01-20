#pragma once

#include "CoreMinimal.h"

#include "KonPlayerController.h"
#include "GameFramework/Character.h"
#include "TrabajoFinalPVJACharacter.generated.h"

class AGun;

UCLASS(config = Game)
class ATrabajoFinalPVJACharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* SideViewCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

protected:

	virtual void BeginPlay() override;

	void JumpR();

	void Fast();

	void FastNormal();

	void JumpS();

	void JumpN();

	void LifeP();

	void RecoveryP();

	void TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location);

	void TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location);

	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

private:

	void Fall();

	void Recovery();

	void CrouchP();

	void CrouchR();

	void DoubleMonedaEnd();

	void Fire();

	void MoveRight(float Val);

public:
	ATrabajoFinalPVJACharacter();

	UFUNCTION(BlueprintPure)
		bool IsDead() const;

	UFUNCTION(BlueprintPure)
		float GetHealthPercent() const;

	UFUNCTION(BlueprintPure)
		float GetResistencePercent() const;

	UFUNCTION(BlueprintPure)
		float GetMunicion() const;

	UFUNCTION(BlueprintPure)
		float GetMunicionTotal() const;

	UFUNCTION(BlueprintPure)
		int GetMoneda() const;

	UFUNCTION(BlueprintPure)
		bool GetCrouch() const;

	void PickUp(int ID);

	void Gravity();

	class UCharacterMovementComponent* CharacterMovement = GetCharacterMovement();

	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }

	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

public:

	UPROPERTY(BlueprintReadWrite)
		int Municion;

	UPROPERTY(EditAnywhere)
		int MaxMunicion = 30;

	UPROPERTY(VisibleAnywhere)
		float Health;

	UPROPERTY(VisibleAnywhere)
		float Resistence;

	UPROPERTY(VisibleAnywhere)
		int Moneda = 0;

	UPROPERTY(VisibleAnywhere)
		float TimeRecovery = 2.f;

	UPROPERTY(VisibleAnywhere)
		float RecoveryTick = 25;

	UPROPERTY(VisibleAnywhere)
		float TimeFall = 1.05f;

	UPROPERTY(VisibleAnywhere)
		float DownRecovery = 15;

	bool bCrouch = false;

	bool Croc = false;

	bool DoubleMoneda = false;

	bool GravityActive = true;

	bool Final = false;


private:

	UPROPERTY(EditAnywhere)
		float MaxHealth = 100;

	UPROPERTY(EditAnywhere)
		float MaxResistence = 100;

	FTimerHandle FTimeFall;
	FTimerHandle FTimerRecovery;
	FTimerHandle FTimerFast;
	FTimerHandle FTimerJump;
	FTimerHandle FTimerDMoneda;

	bool FallCheck = true;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AGun> GunClass;

	UPROPERTY()
		AGun* Gun;


};
