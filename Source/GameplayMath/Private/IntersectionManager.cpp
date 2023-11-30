// Fill out your copyright notice in the Description page of Project Settings.


#include "IntersectionManager.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AIntersectionManager::AIntersectionManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AIntersectionManager::BeginPlay()
{
	Super::BeginPlay();



	//CombinedRaduises = Cast<Ainte>(this->GetComponentByClass(UPlayerStats::StaticClass()));

}

// Called every frame
void AIntersectionManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (SphereA !=NULL && SphereB != NULL) {
	
		float distanceBetween = FVector::Dist(SphereA->GetActorLocation(), SphereB->GetActorLocation());


		if (distanceBetween < CombinedRadiuses) {
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Spheres Overlapping"));
		}
	}





}

