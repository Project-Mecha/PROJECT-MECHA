// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PROJECTMECHA_Gameinstance.generated.h"


UCLASS()
class PROJECT_MECHA_API UPROJECTMECHA_Gameinstance : public UGameInstance
{
	GENERATED_BODY()
	
protected:
	virtual void Init() override;

	void LoginCompleted(int NumOfPlayers, bool bWasSuccessful, const FUniqueNetId& UserId, const FString& Error);
	void SessionCreated(FName SessionName, bool bWasSuccessful);

	void FindSessionCompleted(bool bWasSuccessful);
public:
	void Login();

	UFUNCTION(BlueprintCallable)
		void CreateSession();

	UFUNCTION()
	void FindSession();

private:
	class IOnlineSubsystem* OnlineSubsystem;
	TSharedPtr<class IOnlineIdentity, ESPMode::ThreadSafe> IdentityPtr;
	TSharedPtr<class IOnlineSession, ESPMode::ThreadSafe> SessionPtr;

	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<UWorld> GameLevel;

	TSharedPtr<class FOnlineSessionSearch> SearchSettings;
};
