// Fill out your copyright notice in the Description page of Project Settings.


#include "IntersectionSphere.h"



// Sets default values
AIntersectionSphere::AIntersectionSphere()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AIntersectionSphere::BeginPlay()
{
	Super::BeginPlay();
	

}

// Called every frame
void AIntersectionSphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawDebugSphere(GetWorld(),GetActorLocation(), radius,128, FColor (100,255,100,255) );
}

