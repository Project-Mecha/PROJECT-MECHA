// Fill out your copyright notice in the Description page of Project Settings.


#include "PMAssetManager.h"

#include "AbilitySystemGlobals.h"

void UPMAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	UAbilitySystemGlobals::Get().InitGlobalData();
	UE_LOG(LogTemp, Warning, TEXT("Asset Initialized"))
}
