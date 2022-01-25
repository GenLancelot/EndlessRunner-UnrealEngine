// Fill out your copyright notice in the Description page of Project Settings.


#include "Camera.h"
#include "PlayerControllerBase.h"
#include "Kismet/GameplayStatics.h "


void ACamera::BeginPlay()
{
	APlayerControllerBase* PlayerController = Cast<APlayerControllerBase>(GetWorld()->GetFirstPlayerController());
	PlayerController->SetViewTarget(this);
}

void ACamera::Tick(float DeltaTime)
{
	UE_LOG(LogTemp, Warning, TEXT("Camera tick"));
	FVector NewLocation(UGameplayStatics::GetPlayerPawn(this, 0)->GetActorLocation().X, -40.f, 860.f);
	this->SetActorLocation(NewLocation);
}
