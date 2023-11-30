// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class GAMEPLAYMATH_API APlayerCharacter : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerCharacter();

	float CurrentLookRotation;

	FVector MoveVector;
private:

	FVector DashPosition;
	float DashDurationCounter;
	float DashDurationTempCounter;
	int DashDurationFrameCounter;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		UCameraComponent* CameraComponent;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		UCapsuleComponent* CapsuleComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float MoveSpeed = 1000.f;


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool canDash = false;

	void Look(const FVector2D Vector); 
	void Look_Implementation(const FVector2D Vector);
	void Move(const FVector2D Vector); 
	void Move_Implementation(const FVector2D Vector);

	void Dash();
};
