// Fill out your copyright notice in the Description page of Project Settings.


#include "PM_GameModeBase.h"
#include "Character/PMPlayerController.h"

APM_GameModeBase::APM_GameModeBase()
{
	PlayerControllerClass = APMPlayerController::StaticClass();
}

void APM_GameModeBase::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(CountDown_Handle, [&]()
		{
			if(TimeRemaining > 0)
				TimeRemaining--;
		}, 1.f, true);
}

void APM_GameModeBase::IncrementTime(float Seconds)
{
	if(TimeRemaining > 0)
		TimeRemaining += Seconds;
}
