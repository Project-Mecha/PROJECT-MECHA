// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/LobbyWidget.h"
#include "Components/TextBlock.h"
#include "PMGameState.h"
#include "Kismet/GameplayStatics.h"

void ULobbyWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (APMGameState* GameState = Cast<APMGameState>(UGameplayStatics::GetGameState(this)))
	{
		LobbyNameText->SetText(FText::FromName(GameState->GetLobbyName()));
		GameState->onLobbyNameChanged.AddDynamic(this, &ULobbyWidget::SetLobbyName);
	}
}

void ULobbyWidget::SetLobbyName(const FName& Name)
{
	LobbyNameText->SetText(FText::FromName(Name));
}
