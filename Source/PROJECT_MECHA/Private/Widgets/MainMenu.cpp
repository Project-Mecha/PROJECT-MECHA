// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/MainMenu.h"
#include "PROJECTMECHA_Gameinstance.h"
#include "Components/Button.h"
#include "Components/ScrollBox.h"
#include "Widgets/LobbyEntry.h"

void UMainMenu::NativeConstruct()
{
	Super::NativeConstruct();

	GameInstance = GetGameInstance<UPROJECTMECHA_Gameinstance>();
	
	GameInstance->onSearchResultCompleted.AddUObject(this, &UMainMenu::OnSessionSearchCompleted);

	JoinSessionButton->OnClicked.AddDynamic(this, &UMainMenu::OnJoinSessesionClicked);
	JoinSessionButton->SetIsEnabled(false);
}

void UMainMenu::LobyEntrySelected(int SelectedLobby)
{
	SelectedLobbyIndex = SelectedLobby;
	
	if(SelectedLobbyIndex > -1)
		JoinSessionButton->SetIsEnabled(true);
}

void UMainMenu::OnJoinSessesionClicked()
{
	if (GameInstance)
		GameInstance->JoinLobbySessionByIndex(SelectedLobbyIndex);
}

void UMainMenu::OnSessionSearchCompleted(const TArray<FOnlineSessionSearchResult>& SearchResults)
{
	LobbyListScrollBox->ClearChildren();
	int index = 0;

	for (const FOnlineSessionSearchResult& Result : SearchResults)
	{
		ULobbyEntry* LobbyEntry = CreateWidget<ULobbyEntry>(LobbyListScrollBox, LobbyEntry_Class);

		LobbyEntry->InitLobbyEntry(FName(GameInstance->GetSessionName(Result)), index);
		LobbyEntry->onLobbyEntrySelected.AddDynamic(this, &UMainMenu::LobyEntrySelected);

		LobbyListScrollBox->AddChild(LobbyEntry);

		++index;
	}
}
