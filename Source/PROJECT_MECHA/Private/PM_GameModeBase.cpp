// Fill out your copyright notice in the Description page of Project Settings.


#include "PM_GameModeBase.h"
#include "Character/PMPlayerController.h"

APM_GameModeBase::APM_GameModeBase()
{
	PlayerControllerClass = APMPlayerController::StaticClass();
}
