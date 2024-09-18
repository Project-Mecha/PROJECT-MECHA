// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Login.h"
#include "Components/Button.h"
#include "PROJECTMECHA_Gameinstance.h"


void ULogin::NativeConstruct()
{
	Super::NativeConstruct();

	GameInstance = GetGameInstance<UPROJECTMECHA_Gameinstance>();
	LoginButton->OnClicked.AddDynamic(this, &ULogin::LoginButtonClicked);
}

void ULogin::LoginButtonClicked()
{
	if (GameInstance)
		GameInstance->Login();
}
