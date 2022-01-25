// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstacleGenerator.h"
#include "Components/BoxComponent.h"
#include "CanYouGameModeBase.h"

// Sets default values
AObstacleGenerator::AObstacleGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Generator = CreateDefaultSubobject<UBoxComponent>(TEXT("Generator"));
	RootComponent = Generator;
	Generator->OnComponentBeginOverlap.AddDynamic(this, &AObstacleGenerator::OnOverlap);
}

// Called when the game starts or when spawned
void AObstacleGenerator::BeginPlay()
{
	Super::BeginPlay();
	SetLifeSpan(15);
	GameMode = (ACanYouGameModeBase*)GetWorld()->GetAuthGameMode();
}

// Called every frame
void AObstacleGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AObstacleGenerator::OnOverlap(UPrimitiveComponent*, class AActor* OtherActor, UPrimitiveComponent*, int32, bool, const FHitResult&)
{
	if (OtherActor && (OtherActor != this) && OtherActor->ActorHasTag("Player"))
	{
		GameMode->SpawnNextObstacle(this->GetActorLocation());
		GameMode->SpawnNextGenerator(this->GetActorLocation());
	}
}