// Fill out your copyright notice in the Description page of Project Settings.


#include "PROJECTMECHA_Gameinstance.h"
#include "OnlineSubsystem.h"
#include "Interfaces/OnlineIdentityInterface.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "OnlineSessionSettings.h"

void UPROJECTMECHA_Gameinstance::Init()
{
	Super::Init();

	OnlineSubsystem = IOnlineSubsystem::Get();

	IdentityPtr = OnlineSubsystem->GetIdentityInterface();
	IdentityPtr->OnLoginCompleteDelegates->AddUObject(this, &UPROJECTMECHA_Gameinstance::LoginCompleted);

	SessionPtr = OnlineSubsystem->GetSessionInterface();
	SessionPtr->OnCreateSessionCompleteDelegates.AddUObject(this, &UPROJECTMECHA_Gameinstance::SessionCreated);
}

void UPROJECTMECHA_Gameinstance::Login()
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
		UE_LOG(LogTemp, Warning, TEXT("Login Success"))

		GetWorld()->ServerTravel("MainMenu");
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Login Error: %s"), *Error)
	}
}

void UPROJECTMECHA_Gameinstance::CreateSession()
{
	if (SessionPtr)
	{
		FOnlineSessionSettings SessionSettings;
		SessionSettings.bAllowInvites = true;
		SessionSettings.bAllowJoinInProgress = true;
		SessionSettings.bIsDedicated = false;
		SessionSettings.bIsLANMatch = false;
		SessionSettings.bShouldAdvertise = true;
		SessionSettings.bUseLobbiesIfAvailable = true;
		SessionSettings.bUsesPresence = true;
		SessionSettings.bAllowJoinViaPresence = true;
		SessionSettings.NumPublicConnections = true;

		SessionSettings.Set("Lobby1", EOnlineDataAdvertisementType::ViaOnlineServiceAndPing);

		SessionPtr->CreateSession(0, FName("GameSession"), SessionSettings);
	}
}

void UPROJECTMECHA_Gameinstance::SessionCreated(FName SessionName, bool bWasSuccessful)
{
	if (bWasSuccessful)
	{
		UE_LOG(LogTemp, Warning, TEXT("Create Session Success"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Session creation failed"))
	}

	if (!GameLevel.IsValid())
	{
		GameLevel.LoadSynchronous();
	}
	if (GameLevel.IsValid())
	{
		const FName LevelName = FName(*FPackageName::ObjectPathToPackageName(GameLevel.ToString()));
		GetWorld()->ServerTravel(LevelName.ToString() + "?listen");
	}
}
