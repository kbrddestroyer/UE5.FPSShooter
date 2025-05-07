// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CPlayerAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class FPSSHOOTERGAME_API UCPlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	void NativeInitializeAnimation() override;
	void NativeUpdateAnimation(float) override;
protected:
	APawn* owningPawn;
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float fSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float fRotationAngle;
};
