// Fill out your copyright notice in the Description page of Project Settings.


#include "InterpolationShowcase.h"

// Sets default values
AInterpolationShowcase::AInterpolationShowcase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



}

// Called when the game starts or when spawned
void AInterpolationShowcase::BeginPlay()
{
	Super::BeginPlay();
	StartingPosition = GetActorLocation();
}

// Called every frame
void AInterpolationShowcase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

