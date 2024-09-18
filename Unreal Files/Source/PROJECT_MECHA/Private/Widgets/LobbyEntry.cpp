// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/LobbyEntry.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"

void ULobbyEntry::InitLobbyEntry(const FName& LobbyName, int EntryLobbyIndex)
{
	LobbyNameText->SetText(FText::FromName(LobbyName));
	LobbyIndex = EntryLobbyIndex;
}

void ULobbyEntry::LobbyButtonCLicked()
{
	onLobbyEntrySelected.Broadcast(LobbyIndex);
}

void ULobbyEntry::NativeConstruct()
{
	Super::NativeConstruct();

	LobbyButton->OnClicked.AddDynamic(this, &ULobbyEntry::LobbyButtonCLicked);
}
