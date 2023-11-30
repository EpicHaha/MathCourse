// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CollisionManager.generated.h"

UCLASS()
class GAMEPLAYMATH_API ACollisionManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACollisionManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent, Category = "BaseCharacter")
		void Collided();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
		AActor* SphereA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
		AActor* SphereB;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
		float CombinedRadiuses;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
		FVector direction;
};
