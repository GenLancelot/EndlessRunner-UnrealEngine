// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloorBackground.generated.h"

UCLASS()
class CLASSICARCADE_API AFloorBackground : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloorBackground();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	
	
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Background;
};
