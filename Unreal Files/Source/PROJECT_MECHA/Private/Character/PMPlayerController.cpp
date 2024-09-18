// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PMPlayerController.h"
#include "Character/PMPlayerState.h"
#include "Character/PMCharacter.h"
#include "Widgets/PMQuickMatchWidget.h"

void APMPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(PMInputMappingContext, 0);
	}

	QuickMatchUI = CreateWidget<UPMQuickMatchWidget>(this, QuickMatchUI_Class);

	//check(QuickMatchUI);

	QuickMatchUI->AddToViewport();
}

void APMPlayerController::OnPossess(APawn* NewPawn)
{
	Super::OnPossess(NewPawn);

	if (APMPlayerState* PMPlayerState = GetPlayerState<APMPlayerState>())
	{
		PMPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(PlayerState, NewPawn);
	}
	
	MainPlayer = CastChecked<APMCharacter>(NewPawn);
}

void APMPlayerController::Tick(float Delta)
{
	Super::Tick(Delta);

	if (IsValid(MainPlayer) && IsValid(QuickMatchUI))
	{
		QuickMatchUI->UpdateSpeed(MainPlayer->GetForwardSpeed());
		//QuickMatchUI->UpdateGear(MainPlayer->GetChaosVehicleMovement()->GetCurrentGear());
	}
}