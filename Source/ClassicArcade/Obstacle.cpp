// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstacle.h"
#include "DestructibleComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
AObstacle::AObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Root"));
	SetRootComponent(SceneRoot);
	SceneUp = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Up"));
	SceneUp->SetupAttachment(SceneRoot);
	SceneDown = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Down"));
	SceneDown->SetupAttachment(SceneRoot);
	BoxCollisionUp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision Up"));
	BoxCollisionUp->SetupAttachment(SceneUp);
	MeshUp = CreateDefaultSubobject<UDestructibleComponent>(TEXT("Mesh Up"));
	MeshUp->SetupAttachment(BoxCollisionUp);
	BoxCollisionDown = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision Down"));
	BoxCollisionDown->SetupAttachment(SceneDown);
	MeshDown = CreateDefaultSubobject<UDestructibleComponent>(TEXT("Mesh Down"));
	MeshDown->SetupAttachment(BoxCollisionDown);

	BoxCollisionUp->SetRelativeLocation(FVector(0.f,0.f,50.f));
	BoxCollisionDown->SetRelativeLocation(FVector(0.f,0.f,50.f));
}

// Called when the game starts or when spawned
void AObstacle::BeginPlay()
{
	Super::BeginPlay();

	SetLifeSpan(10);
	SceneUp->SetRelativeLocation(FVector(0.f, 0.f, 100.f));
	SceneDown->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
	BoxCollisionDown->SetRelativeLocation(FVector(0.f, 0.f, -50.f));
	BoxCollisionUp->SetRelativeLocation(FVector(0.f, 0.f, 50.f));
	float fScaleDown = FMath::RandRange(0.f, 7.3f);
	float fScaleUp = 7.3f - fScaleDown;
	FVector Scale(1.f, 1.f, fScaleDown);
	SceneDown->SetRelativeScale3D(Scale);
	Scale = FVector(1.f, 1.f, fScaleUp);
	SceneUp->SetRelativeScale3D(Scale);
	FVector Location(this->GetActorLocation().X, CalculateLocation(fScaleDown, fScaleUp), this->GetActorLocation().Z);
	SceneRoot->SetWorldLocation(Location);
}

float AObstacle::CalculateLocation(float X, float Y) const
{
	return -X*3300.f/73+ Y*4000.f/73;
}

// Called every frame
void AObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

