// Fill out your copyright notice in the Description page of Project Settings.


#include "PMGameState.h"
#include "Net/UnrealNetwork.h"

void APMGameState::SetLobbyName(const FName& NewLobbyName)
{
	LobbyName = NewLobbyName;
}

void APMGameState::OnRep_LobbyNameChange()
{
	onLobbyNameChanged.Broadcast(LobbyName);
}

void APMGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(APMGameState, LobbyName, COND_None, REPNOTIFY_Always);
}
