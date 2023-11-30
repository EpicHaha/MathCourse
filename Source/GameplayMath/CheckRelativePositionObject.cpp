// Fill out your copyright notice in the Description page of Project Settings.


#include "CheckRelativePositionObject.h"

// Sets default values
ACheckRelativePositionObject::ACheckRelativePositionObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACheckRelativePositionObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACheckRelativePositionObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void  ACheckRelativePositionObject::CheckRelativePosition(AActor* Target) {

	FVector SelfLocation = GetActorLocation();
	FVector TargetLocation = Target->GetActorLocation();
	FVector Direction = SelfLocation - TargetLocation;
	
	FVector	LocalSpaceLocation = Target->GetActorTransform().InverseTransformPosition(TargetLocation);
	
	
	if (LocalSpaceLocation.X > GetActorLocation().X) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("In front of Target!"));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Behind Target!!"));

	}

	if (LocalSpaceLocation.Z <  GetActorLocation().Z) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Below Target!"));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Above Target!!"));

	}




}