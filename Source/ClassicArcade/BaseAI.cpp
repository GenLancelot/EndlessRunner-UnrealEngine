// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAI.h"
#include "BasePlayer.h"
#include "CanYouGameModeBase.h"
#include "Kismet/GameplayStatics.h"

void ABaseAI::BeginPlay()
{
	Super::BeginPlay();

	SetLifeSpan(10);

	GetWorld()->GetTimerManager().SetTimer(FireRateTimer, this, &ABaseAI::CheckFireCondiotion, fFireRate, true);

	PlayerPawn = Cast<ABasePlayer>(UGameplayStatics::GetPlayerPawn(this, 0));


}
void ABaseAI::Fire()
{
	Super::Fire();
}
void ABaseAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	
}

void ABaseAI::CheckFireCondiotion()
{
	if (!PlayerPawn)
	{
		return;
	}
	//TODO check is player dead
	ACanYouGameModeBase* GameMode = Cast<ACanYouGameModeBase>(GetWorld()->GetAuthGameMode());
	if (GameMode != nullptr)
		return;
	if (GameMode->IsPlayerDead())
		return;
	//TODO check is player in line of trace - moved to blackboard
}
bool ABaseAI::GetCanAIShoot()
{
	return bCanShoot;
}
bool ABaseAI::GetCanAIMove()
{
	return bCanAIMove;
}