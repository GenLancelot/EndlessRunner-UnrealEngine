// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlayer.h"
#include "CanYouGameModeBase.h"
#include "PowerUps.h"
#include "Components/CapsuleComponent.h"
#include "PlayerControllerBase.h"
#include "Components/WidgetComponent.h"
#include "Camera/CameraComponent.h"

void ABasePlayer::BeginPlay()
{
	Super::BeginPlay();
	GameMode = (ACanYouGameModeBase*)GetWorld()->GetAuthGameMode();
	PlayerController = Cast<APlayerControllerBase>(GetWorld()->GetFirstPlayerController());
	Capsule->OnComponentBeginOverlap.AddDynamic(this, &ABasePlayer::OnOverlapBegin);
	
}
void ABasePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	fPoints+=0.1f;
	bool bSpawnAI = false;
	if((int)fPoints % 10 == 0 && fPoints > 1.0f)
		bSpawnAI = FMath::RandRange(0, (int)fPoints) % 17 == 0 && FMath::RandRange(0, (int)fPoints) % 13 == 0;
	if (bSpawnAI)
		GameMode->SpawnAI();

}
void ABasePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Up"), this, &ABasePlayer::Up);
	PlayerInputComponent->BindAxis(TEXT("Right"), this, &ABasePlayer::Right);
	PlayerInputComponent->BindAction(TEXT("Shoot"), IE_Pressed, this, &ABasePlayer::Fire);

}

void ABasePlayer::Up(float AxisValue)
{
	AddActorLocalOffset(GetActorRightVector() * AxisValue * fMoveSpeed * GetWorld()->DeltaTimeSeconds, true);
}

void ABasePlayer::Right(float AxisValue)
{
	AxisValue = 1.f;
	AddActorLocalOffset(GetActorForwardVector() * fMoveForwardSpeed * GetWorld()->DeltaTimeSeconds, true);
}

void ABasePlayer::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	if (OtherComp->ComponentHasTag("Wall"))
	{
		//TODO uncomment
		UE_LOG(LogTemp, Warning, TEXT("Collision with: %s"), *OtherComp->GetName());
		//DisableInput(PlayerController);
		//PlayerController->SetPause(true);
	}
	//TODO add tags after create powerUps
	if (OtherActor->ActorHasTag("PowerUps.Bullet") || OtherActor->ActorHasTag("PowerUps.SpeedUp") ||
		OtherActor->ActorHasTag("PowerUps.Shield") || OtherActor->ActorHasTag("PowerUps.Bomb") ||
		OtherActor->ActorHasTag("PowerUps.Money") || OtherActor->ActorHasTag("PowerUps.PowerUp") ||
		OtherActor->ActorHasTag("PowerUps.ExtraLife") || OtherActor->ActorHasTag("PowerUps.ExtraPoints") ||
		OtherActor->ActorHasTag("PowerUps.SuperSpeed")) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Collision with: %s"), *OtherActor->GetName());
		Cast<APowerUps>(OtherActor)->Take();
	}

}

void ABasePlayer::ApplySpeedUp()
{
	UE_LOG(LogTemp, Error, TEXT("Speeeeeeeeeeeedy"));
	fMoveSpeed += fAddSpeed;
	FTimerHandle UnusedHandle;
	GetWorldTimerManager().SetTimer(UnusedHandle, [this]() {fMoveSpeed -= fAddSpeed;}, fPowerUpTime, false);
}

void ABasePlayer::ApplySuperSpeedUp()
{
	UE_LOG(LogTemp, Error, TEXT("Super Speeeeeeeeeeeedy"));
	fMoveSpeed += fAddSpeed;
	fMoveForwardSpeed += fAddSpeed;
	FTimerHandle UnusedHandle;
	GetWorldTimerManager().SetTimer(UnusedHandle, [this]() {fMoveSpeed -= fAddSpeed; fMoveForwardSpeed -= fAddSpeed; }, fPowerUpTime, false);
}

void ABasePlayer::TakeBullet()
{
	UE_LOG(LogTemp, Error, TEXT("Take Bullet"));
	nBulletCounts++;
}

void ABasePlayer::AddShield()
{
	UE_LOG(LogTemp, Error, TEXT("Shield Add"));
	bShieldActive = true;
	FTimerHandle UnusedHandle;
	GetWorldTimerManager().SetTimer(UnusedHandle, [this]() {bShieldActive = false; }, fPowerUpTime, false);
}

void ABasePlayer::TakeBomb()
{
	UE_LOG(LogTemp, Error, TEXT("Take Bomb"));
	bHaveBomb = true;
}

float ABasePlayer::GetPoints()
{
	return fPoints;
}