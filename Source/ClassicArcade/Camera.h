// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "Camera.generated.h"

/**
 * 
 */
UCLASS()
class CLASSICARCADE_API ACamera : public ACameraActor
{
	GENERATED_BODY()
	
public:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
