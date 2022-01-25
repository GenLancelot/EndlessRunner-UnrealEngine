// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class CLASSICARCADE_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();
	virtual void Fire();
	UPROPERTY(EditAnywhere)
		class UCapsuleComponent* Capsule;

private:	
	UPROPERTY(EditAnywhere)
		bool bDead = false;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Mesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Compontntes", meta = (AllowPrivateAccess = "true"))
		USceneComponent* ProjectileSpawnPoint;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Projectile Type", meta = (AllowPrivateAccess = "true"));
		TSubclassOf<class AProjectileBase> ProjectileClass;
	
};
