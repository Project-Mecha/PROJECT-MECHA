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

	class IOnlineSubsystem* OnlineSubsystem;
	TSharedPtr<class IOnlineIdentity, ESPMode::ThreadSafe> IdentityPtr;
	TSharedPtr<class IOnlineSession, ESPMode::ThreadSafe> SessionPtr;

	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<UWorld> GameLevel;

public:
	void Login();
	void LoginCompleted(int NumOfPlayers, bool bWasSuccessful, const FUniqueNetId& UserId, const FString& Error);

	UFUNCTION(BlueprintCallable)
		void CreateSession();

	void SessionCreated(FName SessionName, bool bWasSuccessful);
};
