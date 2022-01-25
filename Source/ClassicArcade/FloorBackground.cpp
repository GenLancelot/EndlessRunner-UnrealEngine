// Fill out your copyright notice in the Description page of Project Settings.


#include "FloorBackground.h"
#include "Components/BoxComponent.h"

// Sets default values
AFloorBackground::AFloorBackground()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Background = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Background Mesh"));
	SetRootComponent(Background);

}

// Called when the game starts or when spawned
void AFloorBackground::BeginPlay()
{
	Super::BeginPlay();
	SetLifeSpan(10);
}

// Called every frame
void AFloorBackground::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
