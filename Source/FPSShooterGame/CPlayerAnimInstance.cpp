// Fill out your copyright notice in the Description page of Project Settings.


#include "CPlayerAnimInstance.h"


void UCPlayerAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	owningPawn = TryGetPawnOwner();
}

void UCPlayerAnimInstance::NativeUpdateAnimation(float deltaSeconds)
{
	Super::NativeUpdateAnimation(deltaSeconds);

	if (!owningPawn)
		return;

	fSpeed = owningPawn->GetVelocity().Size();
	fRotationAngle = owningPawn->GetControlRotation().Yaw;
}
