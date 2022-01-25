// Fill out your copyright notice in the Description page of Project Settings.

#include "AIController.h"
#include "BaseAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BaseAI.h"

void ABaseAIController::BeginPlay()
{
	Super::BeginPlay();
	if(AIBehavior)
	{
		RunBehaviorTree(AIBehavior);
		APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		if (!PlayerPawn) return;
		ABaseAI* ThisAI = Cast<ABaseAI>(this->GetPawn());
		if (!ThisAI) return;
		FVector TargetLocation(ThisAI->GetActorLocation().X, PlayerPawn->GetActorLocation().Y, ThisAI->GetActorLocation().Z);
		GetBlackboardComponent()->SetValueAsBool(TEXT("CanAIMove"), ThisAI->GetCanAIMove());
		GetBlackboardComponent()->SetValueAsBool(TEXT("CanAIShoot"), ThisAI->GetCanAIShoot());
		GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocationHeight"), TargetLocation);

	}
}
void ABaseAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}
