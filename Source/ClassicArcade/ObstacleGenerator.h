// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObstacleGenerator.generated.h"

UCLASS()
class CLASSICARCADE_API AObstacleGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObstacleGenerator();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
		class UBoxComponent* Generator;
	class ACanYouGameModeBase* GameMode;
	UFUNCTION()
		void OnOverlap(class UPrimitiveComponent* Comp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
