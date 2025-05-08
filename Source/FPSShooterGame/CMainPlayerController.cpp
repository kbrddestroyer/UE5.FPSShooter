// Fill out your copyright notice in the Description page of Project Settings.


#include "CMainPlayerController.h"
#include <cassert>

void ACMainPlayerController::BeginPlay()
{
	ULocalPlayer* localPlayer = GetLocalPlayer();
	assert(localPlayer);

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(localPlayer))
	{
		Subsystem->AddMappingContext(inputMappingContext, 0);
	}
}