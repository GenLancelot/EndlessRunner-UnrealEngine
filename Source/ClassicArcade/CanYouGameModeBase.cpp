// Fill out your copyright notice in the Description page of Project Settings.


#include "CanYouGameModeBase.h"
#include "Floor.h"
#include "FloorBackground.h"
#include "Obstacle.h"
#include "ObstacleDM.h"
#include "ObstacleWithGenerator.h"
#include "PlayerControllerBase.h"
#include "BaseAI.h"
#include "BasePlayer.h"
#include "PowerUps.h"
#include "Kismet/GameplayStatics.h"
#include "ObstacleGenerator.h"
#include <Runtime/Engine/Public/EngineUtils.h> // TODO check is necessery


void ACanYouGameModeBase::PawnKilled(APawn* PawnKilled)
{
	Super::PawnKilled(PawnKilled);
	SetPlayerCanMove(true);
	Player = Cast<ABasePlayer>(UGameplayStatics::GetPlayerPawn(this, 0));
}


void ACanYouGameModeBase::SpawnNextFloor(FVector Location)
{
	Location.X += 1000.f;
	Location.Y = 410.f;
	Location.Z = 100.f;
	FRotator Rotation = FRotator(0.f, 0.f, -90.f);
	if (FloorType){
		AFloor* NewFloor = GetWorld()->SpawnActor<AFloor>(FloorType, Location, Rotation);
	}
	
}

void ACanYouGameModeBase::SpawnNextFloorBackground(FVector Location)
{
	Location.X += 990.f;
	Location.Y = 0.f;
	Location.Z = 0.f;
	FRotator Rotation = FRotator(0.f, 0.f, 0.f);
	if (BackgroundFloorType) {
		AFloorBackground* NewFloorBg = GetWorld()->SpawnActor<AFloorBackground>(BackgroundFloorType, Location, Rotation);
	}
	
}

/*void ACanYouGameModeBase::SpawnNextObstacle(FVector Location)
{
	Location.X += 1600.f;
	Location.Y = 0.f;
	Location.Z = 50.f;
	FRotator Rotation = FRotator(0.f, 0.f, -90.f);
	if (ObstacleType) {
		AObstacle* Obstacle1 = GetWorld()->SpawnActor<AObstacle>(ObstacleType, Location, Rotation);
	}
	Location.X += 1600.f;
	if (ObstacleType) {
		AObstacle* Obstacle2 = GetWorld()->SpawnActor<AObstacle>(ObstacleType, Location, Rotation);
	}
}*/

void ACanYouGameModeBase::SpawnNextObstacle(FVector Location)
{
	Location.X += 1600.f;
	Location.Z = 50.f;
	FRotator Rotation = FRotator(0.f, 0.f, -90.f);
	if (ObstacleDM) {
		for (int i = 1; i <= 3; i++)
		{
			float fScaleDown = FMath::RandRange(0.1f, 7.3f);
			float fScaleUp = 7.3f - fScaleDown;
			FVector Scale(1.f, 1.f, fScaleDown);
			Location.Y = -430.f + fScaleDown * 50.f;
			AObstacleDM* Obstacle1 = GetWorld()->SpawnActor<AObstacleDM>(ObstacleDM, Location, Rotation);
			Obstacle1->SetActorRelativeScale3D(Scale);
			Scale = FVector(1.f, 1.f, fScaleUp);
			Location.Y += 465.f;
			AObstacleDM* Obstacle2 = GetWorld()->SpawnActor<AObstacleDM>(ObstacleDM, Location, Rotation);
			Obstacle2->SetActorRelativeScale3D(Scale);
			Location.X += 800.f;
		}
		
	}
}
/*
void ACanYouGameModeBase::SpawnNextObstacleWithGenerator(FVector Location)
{
	Location.X += 2400.f;
	Location.Y = 0.f;
	Location.Z = 50.f;
	FRotator Rotation = FRotator(0.f, 0.f, -90.f);
	if (ObstacleWithGeneratorType) {
		AObstacleWithGenerator* ObstacleWithGen = GetWorld()->SpawnActor<AObstacleWithGenerator>(ObstacleWithGeneratorType, Location, Rotation);
	}
}
*/
void ACanYouGameModeBase::SpawnNextGenerator(FVector Location)
{
	Location.X += 2400.f;
	Location.Y = 0.f;
	Location.Z = 70.f;
	FRotator Rotation = FRotator(0.f, 0.f, 0.f);
	if (Generator) {
		AObstacleGenerator* Gen = GetWorld()->SpawnActor<AObstacleGenerator>(Generator, Location, Rotation);
	}
}

void ACanYouGameModeBase::SpawnAI()
{
	FVector Location = UGameplayStatics::GetPlayerPawn(this, 0)->GetActorLocation();
	Location.X += 3000.f;
	//TODO

		//check is something at this location
		//probably must be controller type
		//TODO check is work
	//calculate Location
		//check is wall here
			//check is overlapping with wall(add tag to wall)
	int32 nAICount = 0;
	for (ABaseAI* AI : TActorRange<ABaseAI>(GetWorld()))
	{
		nAICount++;
		if (AI->GetActorLocation() == Location) return;
	}
	if (nAICount >= 5) return;
	for (AObstacle* Wall : TActorRange<AObstacle>(GetWorld()))
	{
		if (Wall->GetActorLocation() == Location) return;
	}
	for (AObstacleWithGenerator* Wall : TActorRange<AObstacleWithGenerator>(GetWorld()))
	{
		if (Wall->GetActorLocation() == Location) return;
	}
		//random start height - maybe calculate
	float fLocationMax = 360.f;
	float fLocationMin = -360.f;
	Location.Y = FMath::RandRange(fLocationMin, fLocationMax);
	//set proper rotation
		//front to player
	FRotator Rotation(0.f,0.f,0.f);
	if (AIType) {
		ABaseAI* AI = GetWorld()->SpawnActor<ABaseAI>(AIType, Location, Rotation);
	}

}

void ACanYouGameModeBase::SpawnPowerUp(TSubclassOf<APowerUps> PowerUpType)
{
	//TODO
	//calculate Location
		//check is wall here
		//check is opponent here
		//random height
	//add spawn conditions
		//from easiest -> Bullets, ExtraPoints, Money, Bomb, Shield(niesmiertelnosc), SpeedUp(gora-dol), SuperSpeed, Diamond, ExtraLife(can have only one)
	FVector Location(0.f, 0.f, 0.f);
	FRotator Rotation(0.f, 0.f, 0.f);
	if (PowerUpType) {
		APowerUps* PowerUp = GetWorld()->SpawnActor<APowerUps>(PowerUpType, Location, Rotation);
	}

}

void ACanYouGameModeBase::SetPlayerCanMove(bool bDead)
{
	APlayerControllerBase* PlayerController = Cast<APlayerControllerBase>(UGameplayStatics::GetPlayerController(this, 0));
	if (PlayerController == nullptr) return;
	if (bDead)
		PlayerController->SetPlayerEnabledState(false);

	return;
	
}

bool ACanYouGameModeBase::IsPlayerDead() const
{
	return true;
}