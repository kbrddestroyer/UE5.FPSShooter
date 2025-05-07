// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnhancedInputSubsystems.h"
#include "CPlayerController.generated.h"

// Used for quick setup of input actions
#define BIND_ACTION(ENHANCED_INPUT, NAME) \
	ENHANCED_INPUT->BindAction(IA##NAME, ETriggerEvent::Triggered, this, &ACPlayerController::##NAME)

UCLASS()
class FPSSHOOTERGAME_API ACPlayerController : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACPlayerController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Non API calls

protected:
	void Look(const FInputActionValue&);
	void Move(const FInputActionValue&);
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UInputAction* IAMove;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UInputAction* IALook;
};
