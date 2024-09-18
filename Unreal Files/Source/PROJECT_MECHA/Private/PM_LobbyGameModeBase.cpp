// Fill out your copyright notice in the Description page of Project Settings.


#include "PM_LobbyGameModeBase.h"
#include "PMGameState.h"
#include "PROJECTMECHA_Gameinstance.h"


void APM_LobbyGameModeBase::InitGameState()
{
	Super::InitGameState();

	APMGameState* PMGameState = Cast<APMGameState>(GameState);
	UPROJECTMECHA_Gameinstance* GameInstance = GetGameInstance<UPROJECTMECHA_Gameinstance>();

	if (PMGameState && GameInstance)
	{
		PMGameState->SetLobbyName(GameInstance->GetCurrentLobbyName());
	}
}
