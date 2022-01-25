// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ClassicArcadeGameModeBase.h"
#include "CanYouGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CLASSICARCADE_API ACanYouGameModeBase : public AClassicArcadeGameModeBase
{
	GENERATED_BODY()
	
public:
	UFUNCTION()
		void SpawnNextFloor(FVector Location);

	UFUNCTION()
		void SpawnNextFloorBackground(FVector Location);

	UFUNCTION()
		void SpawnNextObstacle(FVector Location);

	//UFUNCTION()
		//void SpawnNextObstacleWithGenerator(FVector Location);

	UFUNCTION()
		void SpawnNextGenerator(FVector Location);

	UFUNCTION()
		void SpawnAI();

	UFUNCTION()
		void SpawnPowerUp(TSubclassOf<APowerUps> PowerUpType);

	UFUNCTION()
		void SetPlayerCanMove(bool bDead);

	bool IsPlayerDead() const;

	virtual void PawnKilled(APawn* PawnKilled) override;

private:

	UPROPERTY(EditAnywhere)
		TSubclassOf<class AFloorBackground> BackgroundFloorType;
	UPROPERTY(EditAnywhere)
		TSubclassOf<class AFloor> FloorType;
	UPROPERTY(EditAnywhere)
		TSubclassOf<class AObstacleWithGenerator> ObstacleWithGeneratorType;
	UPROPERTY(EditAnywhere)
		TSubclassOf<class AObstacle> ObstacleType;
	UPROPERTY(EditAnywhere)
		TSubclassOf<class AObstacleDM> ObstacleDM;
	UPROPERTY(EditAnywhere)
		TSubclassOf<class AObstacleGenerator> Generator;
	UPROPERTY(EditAnywhere)
		TSubclassOf<class ABaseAI> AIType;
	class ABasePlayer* Player;
};
