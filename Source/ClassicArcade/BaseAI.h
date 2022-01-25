// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "BaseAI.generated.h"

/**
 * 
 */
UCLASS()
class CLASSICARCADE_API ABaseAI : public ABasePawn
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaTime) override;
	virtual void Fire() override;
	bool GetCanAIShoot();
	bool GetCanAIMove();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

private:

	class ABasePlayer* PlayerPawn;

	FTimerHandle FireRateTimer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shooting", meta = (AllowPrivateAccess = "true"))
		float fFireRate = 2.0f;

	void CheckFireCondiotion();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shooting", meta = (AllowPrivateAccess = "true"))
	bool bCanShoot = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Moving", meta = (AllowPrivateAccess = "true"))
	bool bCanAIMove = true;
};
