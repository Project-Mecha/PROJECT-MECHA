// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PM_GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_MECHA_API APM_GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	APM_GameModeBase();

protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Gameplay)
	float TimeRemaining = 0.f;

	FTimerHandle CountDown_Handle;

public:
	void IncrementTime(float);
};
