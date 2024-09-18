// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "PROJECT_MECHA/PROJECT_MECHA.h"
#include "PMGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_MECHA_API UPMGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
public:
	UPMGameplayAbility();

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Ability)
	EPMAbilityInputID AbilityInputID = EPMAbilityInputID::None;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Ability)
	EPMAbilityInputID AbilityID = EPMAbilityInputID::None;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Ability)
	bool bActivateAbilityOnGranted = false;

	virtual void OnAvatarSet(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
};
