// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Obstacle.generated.h"

UCLASS()
class CLASSICARCADE_API AObstacle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObstacle();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
		USceneComponent* SceneUp;
	UPROPERTY(VisibleAnywhere)
		USceneComponent* SceneDown;
	UPROPERTY(VisibleAnywhere)
		USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere)
		class UDestructibleComponent* MeshUp;
	UPROPERTY(EditAnywhere)
		UDestructibleComponent* MeshDown;
	UPROPERTY(EditAnywhere)
		class UBoxComponent* BoxCollisionUp;
	UPROPERTY(EditAnywhere)
		UBoxComponent* BoxCollisionDown;
	float CalculateLocation(float X, float Y) const;
};
