// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BaseAIController.generated.h"

/**
 * 
 */
UCLASS()
class CLASSICARCADE_API ABaseAIController : public AAIController
{
	GENERATED_BODY()
public:
	bool CanAIShoot();
protected:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditAnywhere)
		class UBehaviorTree* AIBehavior;
};
