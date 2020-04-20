// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "UEProject.h"
#include "GameFramework/GameModeBase.h"
#include "UEProjectGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class UEPROJECT_API AUEProjectGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	virtual void StartPlay() override;
};
