// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileBase.generated.h"

UCLASS()
class CLASSICARCADE_API AProjectileBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectileBase();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:

	//comp
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		class UProjectileMovementComponent* ProjectileMovement;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* ProjectileMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		UParticleSystemComponent* ParticleTrail;
	//var
	UPROPERTY(EditDefaultsOnly, Category = "Damage")
		TSubclassOf<UDamageType> DamageType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
		float fMovementSpeed = 1300.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage", meta = (AllowPrivateAccess = "true"))
		float fDamage = 50.f;
	UPROPERTY(EditAnywhere, Category = "Effects")
		UParticleSystem* HitParticle;
	UPROPERTY(EditAnywhere, Category = "Effects")
		USoundBase* HitSound;
	UPROPERTY(EditAnywhere, Category = "Effects")
		USoundBase* LaunchSound;
	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
