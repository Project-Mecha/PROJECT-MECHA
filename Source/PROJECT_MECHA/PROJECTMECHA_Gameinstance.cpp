// Fill out your copyright notice in the Description page of Project Settings.


#include "PROJECTMECHA_Gameinstance.h"
#include "OnlineSubsystem.h"
#include "Interfaces/OnlineIdentityInterface.h"

void UPROJECTMECHA_Gameinstance::Init()
{
	Super::Init();

	OnlineSubsystem = IOnlineSubsystem::Get();
	IdentityPtr = OnlineSubsystem->GetIdentityInterface();
	IdentityPtr->OnLoginCompleteDelegates->AddUObject(this, &UPROJECTMECHA_Gameinstance::LoginCompleted);
}

void UPROJECTMECHA_Gameinstance::LogIn()
{
	if (IdentityPtr)
	{
		FOnlineAccountCredentials AccountCredentials;
		AccountCredentials.Type = "accountportal";
		AccountCredentials.Id = "";
		AccountCredentials.Token = "";

		IdentityPtr->Login(0, AccountCredentials);
	}
}

void UPROJECTMECHA_Gameinstance::LoginCompleted(int NumOfPlayers, bool bWasSuccessful, const FUniqueNetId& UserId, const FString& Error)
{
	if (bWasSuccessful)
	{
		UE_LOG(LogTemp, Warning, TEXT("Success"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Error: %s"), *Error)
	}
}
