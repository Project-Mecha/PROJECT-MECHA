// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PM_LobbyGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_MECHA_API APM_LobbyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
protected:
	virtual void InitGameState() override;
};
