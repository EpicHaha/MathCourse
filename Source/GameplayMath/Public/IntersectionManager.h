// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IntersectionSphere.h"
#include "GameFramework/Actor.h"
#include "IntersectionManager.generated.h"


UCLASS()
class GAMEPLAYMATH_API AIntersectionManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AIntersectionManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
		AActor* SphereA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
		AActor* SphereB;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	float CombinedRadiuses;
};
