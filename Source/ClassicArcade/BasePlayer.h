// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "BasePlayer.generated.h"

/**
 * 
 */
UCLASS()
class CLASSICARCADE_API ABasePlayer : public ABasePawn
{
	GENERATED_BODY()
	
public:
	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION(BlueprintCallable)
		void ApplySpeedUp();
	UFUNCTION(BlueprintCallable)
		void ApplySuperSpeedUp();
	UFUNCTION(BlueprintCallable)
		void TakeBullet();
	UFUNCTION(BlueprintCallable)
		void TakeBomb();
	UFUNCTION(BlueprintCallable)
		void AddShield();
	UFUNCTION(BlueprintCallable)
		float GetPoints();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = "Speed")
		float fMoveSpeed = 500.f;
	UPROPERTY(EditAnywhere, Category = "Speed")
		float fMoveForwardSpeed = 700.f;
	UPROPERTY(EditAnywhere, Category = "Speed")
		float fAddSpeed = 300.f;
	UPROPERTY(VisibleAnywhere)
		float fPoints = 0.f;
	UPROPERTY(VisibleAnywhere)
		int nBulletCounts = 0;
	UPROPERTY(VisibleAnywhere)
		bool bHaveBomb = false;
	UPROPERTY(EditAnywhere, Category = "PowerUpTime")
		float fPowerUpTime = 2.f;
	UPROPERTY(EditAnywhere, Category = "PowerUps")
		bool bShieldActive = false;
	void Up(float AxisValue);
	void Right(float AxisValue);
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	class ACanYouGameModeBase* GameMode;
	class APlayerControllerBase* PlayerController;
};
