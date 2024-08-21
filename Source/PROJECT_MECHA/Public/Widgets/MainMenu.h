// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OnlineSessionSettings.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_MECHA_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	TObjectPtr<class UPROJECTMECHA_Gameinstance> GameInstance;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class ULobbyEntry> LobbyEntry_Class;

	int SelectedLobbyIndex = -1;
private:
	UPROPERTY(meta = (BindWidget))
	class UScrollBox* LobbyListScrollBox;

	UPROPERTY(meta = (BindWidget))
	class UButton* JoinSessionButton;

protected:
	UFUNCTION()
	void LobyEntrySelected(int SelectedLobby);

	UFUNCTION()
	void OnJoinSessesionClicked();

	void OnSessionSearchCompleted(const TArray<FOnlineSessionSearchResult>& SearchResults);
};
