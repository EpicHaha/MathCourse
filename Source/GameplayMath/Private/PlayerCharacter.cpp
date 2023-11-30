// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleCollider"));
	CapsuleComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CapsuleComponent->SetCollisionObjectType(ECC_Pawn);
	CapsuleComponent->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
	CapsuleComponent->InitCapsuleSize(55.f, 96.f);
	CapsuleComponent->SetSimulatePhysics(true);

	// Hacky way to stop the capsule from inheriting collision rotation.
	constexpr float InertiaTensorScale = 10000.f;
	CapsuleComponent->BodyInstance.InertiaTensorScale = FVector(InertiaTensorScale, InertiaTensorScale, InertiaTensorScale);

	SetRootComponent(CapsuleComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(CapsuleComponent);
	CameraComponent->SetRelativeLocation(FVector(0, 0, 100.f));
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(canDash){
	Dash();
	}
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APlayerCharacter::Look_Implementation(const FVector2D Vector)
{
	// Rotate directly on the horizontal axis
	AddActorLocalRotation(
		FRotator(
			0.f,
			Vector.X,
			0.f)
	);

	// Clamp vertical axis
	CurrentLookRotation += Vector.Y;
	CurrentLookRotation = FMath::ClampAngle(
		CurrentLookRotation,
		-90.f,
		90.f
	);

	CameraComponent->SetWorldRotation(
		FRotator(
			CurrentLookRotation,
			GetActorRotation().Yaw,
			0.f)
	);
}

void APlayerCharacter::Move_Implementation(const FVector2D Vector)
{
	MoveVector.X = Vector.Y;
	MoveVector.Y = -Vector.X;
	MoveVector.Z = 0.f;

}


void APlayerCharacter::Dash()
{

	UE_LOG(LogTemp, Warning, TEXT("Dashing"));
	FHitResult* HitThis = NULL;

	FVector UpdatedPosition = FMath::Lerp(GetActorLocation(), CameraComponent->GetForwardVector()*1000, 0.1f);


	// this makes sure that the Lerping ends when nearing the end of the line
	DashDurationTempCounter++;
	DashDurationTempCounter = 0.1f / DashDurationTempCounter;
	DashDurationCounter += DashDurationTempCounter;


	if (DashDurationCounter > 2)
	{
		//when dash ends reset everything to be used for the next dash and apply momentum
		DashPosition = FVector(0, 0, 0);
		DashDurationTempCounter = 0;
		DashDurationCounter = 0;
		canDash = false;
	}

	this->SetActorRelativeLocation(UpdatedPosition, false, HitThis, ETeleportType::ResetPhysics);

}