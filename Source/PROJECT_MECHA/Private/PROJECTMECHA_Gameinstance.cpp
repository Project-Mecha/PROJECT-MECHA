// Fill out your copyright notice in the Description page of Project Settings.


#include "PROJECTMECHA_Gameinstance.h"


void UPROJECTMECHA_Gameinstance::Init()
{
	Super::Init();

	OnlineSubsystem = IOnlineSubsystem::Get();

	IdentityPtr = OnlineSubsystem->GetIdentityInterface();
	IdentityPtr->OnLoginCompleteDelegates->AddUObject(this, &UPROJECTMECHA_Gameinstance::LoginCompleted);

	SessionPtr = OnlineSubsystem->GetSessionInterface();
	SessionPtr->OnCreateSessionCompleteDelegates.AddUObject(this, &UPROJECTMECHA_Gameinstance::SessionCreated);
	SessionPtr->OnFindSessionsCompleteDelegates.AddUObject(this, &UPROJECTMECHA_Gameinstance::FindSessionCompleted);
	SessionPtr->OnJoinSessionCompleteDelegates.AddUObject(this, &UPROJECTMECHA_Gameinstance::JoinSessionCompleted);
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

void UPROJECTMECHA_Gameinstance::CreateSession(const FName& LobbyName)
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
		SessionSettings.NumPublicConnections = 10;       //Pay Attention

		SessionSettings.Set(SessionNameKey, LobbyName.ToString(), EOnlineDataAdvertisementType::ViaOnlineServiceAndPing);
		CurrentLobbyName = LobbyName;

		SessionPtr->CreateSession(0, LobbyName, SessionSettings);
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

	/*if (!GameLevel.IsValid())
	{
		GameLevel.LoadSynchronous();
	}
	if (GameLevel.IsValid())
	{
		const FName LevelName = FName(*FPackageName::ObjectPathToPackageName(GameLevel.ToString()));
		GetWorld()->ServerTravel(LevelName.ToString() + "?listen");
	}*/
	if (!LobbyLevel.IsValid())
	{
		LobbyLevel.LoadSynchronous();
	}
	if (LobbyLevel.IsValid())
	{
		const FName LevelName = FName(*FPackageName::ObjectPathToPackageName(LobbyLevel.ToString()));
		GetWorld()->ServerTravel(LevelName.ToString() + "?listen");
	}
}

void UPROJECTMECHA_Gameinstance::FindSessionCompleted(bool bWasSuccessful)
{
	if (bWasSuccessful)
	{
		if (SearchSettings->SearchResults.Num() > 0)
		{
			for (const FOnlineSessionSearchResult& results : SearchSettings->SearchResults)
			{
				FString LobbyName = GetSessionName(results);
				UE_LOG(LogTemp, Warning, TEXT("Found Session with %s"), *LobbyName);
			}
		}

		onSearchResultCompleted.Broadcast(SearchSettings->SearchResults);
	}
}

void UPROJECTMECHA_Gameinstance::JoinSessionCompleted(FName SessionName, EOnJoinSessionCompleteResult::Type Result)
{
	if (Result == EOnJoinSessionCompleteResult::Success)
	{
		FString TravelURL;
		SessionPtr->GetResolvedConnectString(SessionName, TravelURL);
		GetFirstLocalPlayerController(GetWorld())->ClientTravel(TravelURL, ETravelType::TRAVEL_Absolute);
	}
}

void UPROJECTMECHA_Gameinstance::FindSession()
{
	if (SessionPtr)
	{
		SearchSettings = MakeShareable(new FOnlineSessionSearch);

		SearchSettings->bIsLanQuery = false;
		SearchSettings->MaxSearchResults = 100;
		SearchSettings->QuerySettings.Set(FName("LOBBYSEARCH"), true, EOnlineComparisonOp::Equals);

		SessionPtr->FindSessions(0, SearchSettings.ToSharedRef());
	}
}

void UPROJECTMECHA_Gameinstance::JoinLobbySessionByIndex(int Index)
{
	UE_LOG(LogTemp, Warning, TEXT("Index is %d"), Index);

	if (Index >= 0 && Index < SearchSettings->SearchResults.Num())
	{
		const FOnlineSessionSearchResult& SearchResult = SearchSettings->SearchResults[Index];

		if(SessionPtr)
			SessionPtr->JoinSession(0, FName(GetSessionName(SearchResult)), SearchResult);
	}
}

FString UPROJECTMECHA_Gameinstance::GetSessionName(const FOnlineSessionSearchResult& SearchResult) const
{
	FString OutVal {"Name none"};
	
	if(SearchResult.Session.SessionSettings.Get(SessionNameKey, OutVal))
		return OutVal;

	return OutVal;
}
