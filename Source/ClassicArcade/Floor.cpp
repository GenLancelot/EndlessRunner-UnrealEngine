// Fill out your copyright notice in the Description page of Project Settings.


#include "Floor.h"
#include "Components/BoxComponent.h"
#include "CanYouGameModeBase.h"

// Sets default values
AFloor::AFloor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Root"));
	SetRootComponent(SceneRoot);
	FloorUp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Floor UP"));
	FloorUp->SetupAttachment(SceneRoot);
	FloorDown = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Floor DOWN"));
	FloorDown->SetupAttachment(SceneRoot);
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->SetupAttachment(SceneRoot);

	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AFloor::OnOverlap);
}

// Called when the game starts or when spawned
void AFloor::BeginPlay()
{
	Super::BeginPlay();
	GameMode = (ACanYouGameModeBase*)GetWorld()->GetAuthGameMode();
	SetLifeSpan(5);
}

// Called every frame
void AFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AFloor::OnOverlap(UPrimitiveComponent*, class AActor* OtherActor, UPrimitiveComponent*, int32, bool, const FHitResult&)
{
	//TODO check if actor has tag player, and add tag to player
	if (OtherActor && (OtherActor != this) && OtherActor->ActorHasTag("Player"))
	{
		GameMode->SpawnNextFloor(this->GetActorLocation());
		GameMode->SpawnNextFloorBackground(this->GetActorLocation());
	}
}
