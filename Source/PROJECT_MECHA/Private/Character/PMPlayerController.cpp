// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PMPlayerController.h"
#include "Character/PMPlayerState.h"

void APMPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(PMInputMappingContext, 0);
	}
}

void APMPlayerController::OnPossess(APawn* NewPawn)
{
	Super::OnPossess(NewPawn);

	if (APMPlayerState* PMPlayerState = GetPlayerState<APMPlayerState>())
	{
		PMPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(PlayerState, NewPawn);
	}
	
}
