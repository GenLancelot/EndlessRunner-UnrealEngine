// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Floor.generated.h"

UCLASS()
class CLASSICARCADE_API AFloor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
		USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* FloorUp;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* FloorDown;
	UPROPERTY(EditAnywhere)
		class UBoxComponent* BoxCollision;


	class ACanYouGameModeBase* GameMode;

	UFUNCTION()
		void OnOverlap(class UPrimitiveComponent* Comp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
