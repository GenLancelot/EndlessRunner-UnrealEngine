// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PowerUps.generated.h"


UENUM(BlueprintType)
enum class EPowerUpType : uint8 {
	Bullet,
	SpeedUp,
	Shield,
	SuperSpeed,
	Bomb,
	Money,
	Diamond,
	ExtraLife,
	ExtraPoints
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPowerUpTakenEvent, EPowerUpType, PowerUpType);

UCLASS()
class CLASSICARCADE_API APowerUps : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APowerUps();

	void Take();

	UPROPERTY(EditAnywhere)
		EPowerUpType PowerUpType;
	
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
		FPowerUpTakenEvent PowerUpTakenEvent;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	class USceneComponent* RootScene;
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* Mesh;

};
