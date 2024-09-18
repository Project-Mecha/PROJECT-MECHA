// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Interfaces/OnlineIdentityInterface.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"
#include "PROJECTMECHA_Gameinstance.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnSessionSearchCompleted, const TArray<FOnlineSessionSearchResult>&);

USTRUCT(BlueprintType)
struct PROJECT_MECHA_API FMeshInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMesh* Head = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMesh* Torso = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMesh* ArmLeft = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMesh* ArmRight = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMesh* LegLeft = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMesh* LegRight = nullptr;

	bool operator!=(const FMeshInfo& RHS) const
	{
		return !(this->Head == RHS.Head && this->Torso == RHS.Torso && this->ArmLeft == RHS.ArmLeft && this->ArmRight == RHS.ArmRight && this->LegLeft == RHS.LegLeft && this->LegRight == RHS.LegRight);
	}
};


UCLASS()
class PROJECT_MECHA_API UPROJECTMECHA_Gameinstance : public UGameInstance
{
	GENERATED_BODY()

protected:
	virtual void Init() override;

	void LoginCompleted(int NumOfPlayers, bool bWasSuccessful, const FUniqueNetId& UserId, const FString& Error);
	void SessionCreated(FName SessionName, bool bWasSuccessful);

	void FindSessionCompleted(bool bWasSuccessful);
	void JoinSessionCompleted(FName SessionName, EOnJoinSessionCompleteResult::Type Result);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Props")
	FMeshInfo PlayerMeshInfo;

public:
	void Login();

	UFUNCTION(BlueprintCallable)
		void CreateSession(const FName& LobbyName);
		
	UFUNCTION(BlueprintCallable)
	void FindSession();

	void JoinLobbySessionByIndex(int Index);

	FORCEINLINE FName GetCurrentLobbyName() const { return CurrentLobbyName; }
	FString GetSessionName(const FOnlineSessionSearchResult& SearchResult) const;
	
	FOnSessionSearchCompleted onSearchResultCompleted;

private:
	class IOnlineSubsystem* OnlineSubsystem;
	TSharedPtr<class IOnlineIdentity, ESPMode::ThreadSafe> IdentityPtr;
	TSharedPtr<class IOnlineSession, ESPMode::ThreadSafe> SessionPtr;

	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<UWorld> GameLevel;
	
	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<UWorld> LobbyLevel;

	TSharedPtr<class FOnlineSessionSearch> SearchSettings;
	const FName SessionNameKey{ "SessionNameKey" };

	FName CurrentLobbyName;
};
