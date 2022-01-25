// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstacleDM.h"
#include "DestructibleComponent.h"

// Sets default values
AObstacleDM::AObstacleDM()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UDestructibleComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AObstacleDM::BeginPlay()
{
	Super::BeginPlay();
	SetLifeSpan(15);
}

// Called every frame
void AObstacleDM::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

