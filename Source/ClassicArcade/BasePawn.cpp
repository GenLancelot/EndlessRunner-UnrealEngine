// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"
#include "Components/CapsuleComponent.h"
#include "ProjectileBase.h"
#include "ClassicArcadeGameModeBase.h"

// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Component"));
	SetRootComponent(Capsule);
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Component"));
	Mesh->SetupAttachment(Capsule);
	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Point"));
	ProjectileSpawnPoint->SetupAttachment(Mesh);
}



void ABasePawn::Fire()
{
	if (ProjectileClass)
	{
		FVector SpawnLocation = ProjectileSpawnPoint->GetComponentLocation();
		FRotator SpawnRotation = this->GetActorRotation();

		AProjectileBase* TempProjectile = GetWorld()->SpawnActor<AProjectileBase>(ProjectileClass, SpawnLocation, SpawnRotation);
		TempProjectile->SetOwner(this);
	}
}