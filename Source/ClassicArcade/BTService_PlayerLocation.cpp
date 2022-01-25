// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlayerLocation.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Pawn.h"
#include "BaseAI.h"
#include "BaseAIController.h"

UBTService_PlayerLocation::UBTService_PlayerLocation()
{
	NodeName = TEXT("Update PLayer Location");
}

void UBTService_PlayerLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	AAIController* Controller = OwnerComp.GetAIOwner();
	if (!Controller) return;
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (!PlayerPawn) return;
	ABaseAI* AI = Cast<ABaseAI>(Controller->GetPawn());
	FVector TargetLocation(AI->GetActorLocation().X, PlayerPawn->GetActorLocation().Y, AI->GetActorLocation().Z);
	//Controller->MoveToLocation(TargetLocation, 5.f);
	UE_LOG(LogTemp, Warning, TEXT("Target location: %s"), *TargetLocation.ToString());
	OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), TargetLocation);
	
}