// Fill out your copyright notice in the Description page of Project Settings.


#include "PM_GameModeBase.h"
#include "Character/PMPlayerController.h"
#include "Widgets/PMQuickMatchWidget.h"
#include "Kismet/GameplayStatics.h"

APM_GameModeBase::APM_GameModeBase()
{
	PlayerControllerClass = APMPlayerController::StaticClass();
}

void APM_GameModeBase::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(CountDown_Handle, [&]()
		{
			if (TimeRemaining > 0)
			{
				TimeRemaining--;

				if (TimeRemaining <= 3)
				{
					APMPlayerController* PlayerController = Cast<APMPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
					PlayerController->QuickMatchUI->onLittleTime.Broadcast();
				}
			}
			else
			{
				if (!bGameHasEnded)
				{
					LooseGame();
					bGameHasEnded = true;
				}
			}


			

		}, 1.f, true);
}

void APM_GameModeBase::IncrementTime(float Seconds)
{
	if (TimeRemaining > 0)
	{
		TimeRemaining += Seconds;

		APMPlayerController* PlayerController = Cast<APMPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
		PlayerController->QuickMatchUI->onTimeAdded.Broadcast();
	}
}

void APM_GameModeBase::LooseGame()
{
	APMPlayerController* PlayerController = Cast<APMPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	PlayerController->QuickMatchUI->onGameFinished.Broadcast("You Loose!");
}

void APM_GameModeBase::WinGame()
{
	if (!bGameHasEnded)
	{
		APMPlayerController* PlayerController = Cast<APMPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
		PlayerController->QuickMatchUI->onGameFinished.Broadcast("You Win!");
		bGameHasEnded = true;
	}
}