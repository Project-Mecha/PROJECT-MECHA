// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LobbyEntry.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLobbyEntrySelected, int32, lobbyIndex);

UCLASS()
class PROJECT_MECHA_API ULobbyEntry : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void InitLobbyEntry(const FName& LobbyName, int EntryLobbyIndex);

	FOnLobbyEntrySelected onLobbyEntrySelected;

private:
	UPROPERTY(meta =(BindWidget))
	class UButton* LobbyButton;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* LobbyNameText;

	UFUNCTION()
	void LobbyButtonCLicked();

	int LobbyIndex = -1;

protected:
	virtual void NativeConstruct() override;
};
