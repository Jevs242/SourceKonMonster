// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"

#include "DoorComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TRABAJOFINALPVJA_API UDoorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UDoorComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenDoor(float DeltaTime);
	void CloseDoor(float DeltaTime);
	float TotalMassOfActors();
	void FindAudioComponent();
	void FindpressurePlate();

	bool OpenDoorSound = false;
	bool CloseDoorSound = true;

private:

	float InitialYaw;
	float CurrentYaw;

	UPROPERTY(EditAnywhere)
		float TargetYaw = 1.f;

	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate = nullptr;

	UPROPERTY(EditAnywhere)
		float MassToOpenDoors = 50.f;

	float DoorLastOpened = 0.f;

	UPROPERTY(EditAnywhere)
		float DoorCloseDelay = 2.f;

	UPROPERTY(EditAnywhere)
		float DoorOpenSpeed = 1.0f;

	UPROPERTY(EditAnywhere)
		float DoorCloseSpeed = 2.0f;

	UPROPERTY()
		UAudioComponent* AudioComponent = nullptr;

};
