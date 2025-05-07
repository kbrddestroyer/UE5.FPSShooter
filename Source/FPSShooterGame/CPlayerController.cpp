// Fill out your copyright notice in the Description page of Project Settings.


#include "CPlayerController.h"
#include "EnhancedInputComponent.h"

// Sets default values
ACPlayerController::ACPlayerController()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPlayerController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		BIND_ACTION(EnhancedInput, Move);
		BIND_ACTION(EnhancedInput, Look);
	}
}

void ACPlayerController::Move(const FInputActionValue& value)
{
	if (!Controller)
		return;

	FVector2D inputValue2D = value.Get<FVector2D>();

	if (inputValue2D == FVector2D::ZeroVector)
		return;

	const FRotator rotator = Controller->GetControlRotation();
	const FRotator yaw(0, rotator.Yaw, 0);

	const auto rotationMatrix = FRotationMatrix(yaw);

	const FVector forward = rotationMatrix.GetUnitAxis(EAxis::X);
	const FVector right = rotationMatrix.GetUnitAxis(EAxis::Y);

	AddMovementInput(forward, inputValue2D.Y);
	AddMovementInput(right, inputValue2D.X);
}

void ACPlayerController::Look(const FInputActionValue& value)
{

}
