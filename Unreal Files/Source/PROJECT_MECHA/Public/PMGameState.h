// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "PMGameState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLobbyNameChanged, const FName&, Name);

UCLASS()
class PROJECT_MECHA_API APMGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	FOnLobbyNameChanged onLobbyNameChanged;

	FORCEINLINE FName GetLobbyName() const { return LobbyName; }
	void SetLobbyName(const FName& NewLobbyName);

private:
	UPROPERTY(ReplicatedUsing = OnRep_LobbyNameChange)
	FName LobbyName;

	UFUNCTION()
	void OnRep_LobbyNameChange();

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;
};
