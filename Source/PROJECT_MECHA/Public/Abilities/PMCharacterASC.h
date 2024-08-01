// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "PMCharacterASC.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_MECHA_API UPMCharacterASC : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public:
	bool bCharacterAbilitiesGiven = false;
	bool bAttributesInitialized = false;
	bool bStartupEffectsGiven = false;
};
