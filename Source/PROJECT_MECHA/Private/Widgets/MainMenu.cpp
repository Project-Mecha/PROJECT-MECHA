// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/MainMenu.h"
#include "PROJECTMECHA_Gameinstance.h"
#include "Components/Button.h"

void UMainMenu::NativeConstruct()
{
	Super::NativeConstruct();

	GameInstance = GetGameInstance<UPROJECTMECHA_Gameinstance>();
	LoginButton->OnClicked.AddDynamic(this, &UMainMenu::LoginButtonClicked);
}

void UMainMenu::LoginButtonClicked()
{
	if (GameInstance)
		GameInstance->Login();
}
