// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ClassicArcadeGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CLASSICARCADE_API AClassicArcadeGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void PawnKilled(APawn* PawnKilled);
};
