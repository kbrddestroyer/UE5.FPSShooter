// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "CMainPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class FPSSHOOTERGAME_API ACMainPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	void BeginPlay() override;

public:
#pragma region VARIABLES
#pragma region INPUT
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UInputMappingContext* inputMappingContext;
#pragma endregion
#pragma endregion
};
