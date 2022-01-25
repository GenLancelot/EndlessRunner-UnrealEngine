// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Shoot.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "AIController.h"
#include "BaseAI.h"

UBTTask_Shoot::UBTTask_Shoot()
{
	NodeName = TEXT("Shoot");

}

EBTNodeResult::Type UBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	AAIController* Controller = OwnerComp.GetAIOwner();
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (!PlayerPawn)
	{
		return EBTNodeResult::Failed;
	}
	if (!Controller) return EBTNodeResult::Failed;
	ABaseAI* AICharacter = Cast<ABaseAI>(Controller->GetPawn());
	if (!AICharacter) return EBTNodeResult::Failed;
	if (AICharacter->GetActorLocation().Y > PlayerPawn->GetActorLocation().Y - 5.5f &&
		AICharacter->GetActorLocation().Y < PlayerPawn->GetActorLocation().Y + 5.5f)
	{
		AICharacter->Fire();
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}