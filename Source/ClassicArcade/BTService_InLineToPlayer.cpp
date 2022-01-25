// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_InLineToPlayer.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "BaseAI.h"

UBTService_InLineToPlayer::UBTService_InLineToPlayer()
{

	NodeName = TEXT("In Line To Player");
}

void UBTService_InLineToPlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	AAIController* Controller = OwnerComp.GetAIOwner();
	if (!Controller) return;
	ABaseAI* AICharacter = Cast<ABaseAI>(Controller->GetPawn());
	if (!AICharacter) return;
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (AICharacter->GetActorLocation().Y > PlayerPawn->GetActorLocation().Y - 5.5f &&
		AICharacter->GetActorLocation().Y < PlayerPawn->GetActorLocation().Y + 5.5f )
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsBool(GetSelectedBlackboardKey(), true);
	}
	else
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsBool(GetSelectedBlackboardKey(), false);
	}
}