// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CheckRelativePositionObject.generated.h"





UCLASS()
class GAMEPLAYMATH_API ACheckRelativePositionObject : public AActor
{
	GENERATED_BODY()


		enum class Context
		{
		Behind,
		InFront,
		Above,
		Below,
		};



public:	
	// Sets default values for this actor's properties
	ACheckRelativePositionObject();

	UFUNCTION(BlueprintCallable , Category = "Math")
	 void CheckRelativePosition(AActor* Target);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
