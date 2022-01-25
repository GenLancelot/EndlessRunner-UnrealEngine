// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObstacleWithGenerator.generated.h"

UCLASS()
class CLASSICARCADE_API AObstacleWithGenerator : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AObstacleWithGenerator();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
		USceneComponent* SceneRoot;
	UPROPERTY(VisibleAnywhere)
		USceneComponent* SceneUp;
	UPROPERTY(VisibleAnywhere)
		USceneComponent* SceneDown;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* MeshUp;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* MeshDown;
	UPROPERTY(EditAnywhere)
		class UBoxComponent* BoxCollisionUp;
	UPROPERTY(EditAnywhere)
		UBoxComponent* BoxCollisionDown;
	UPROPERTY(EditAnywhere)
		UBoxComponent* BoxGenerator;
	class ACanYouGameModeBase* GameMode;

	UFUNCTION()
		void OnOverlap(class UPrimitiveComponent* Comp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	float CalculateLocation(float X, float Y) const;
};
