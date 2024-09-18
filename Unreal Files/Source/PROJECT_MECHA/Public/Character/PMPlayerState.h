// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemComponent.h"
#include "Abilities/PMCharacterASC.h"
#include "AbilitySystemInterface.h"
#include "GameplayTagContainer.h"
#include "PMPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_MECHA_API APMPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	APMPlayerState();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	class UPMCharacterAttributeSet* GetAttributeSet() const;

	UFUNCTION(BlueprintCallable)
	bool IsAlive() const;

	UFUNCTION(BlueprintCallable)
	void ShowAbilityConfirmCancelText(bool bSHowText);

	//Getters
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetHealth() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetMaxHealth() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetMana() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetMaxMana() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	int32 GetAbilityLevel() const;

protected:
	UPROPERTY()
		class UPMCharacterASC* AbilitySystemComponent;

	UPROPERTY()
		class UPMCharacterAttributeSet* AttributeSet;

	FGameplayTag DeadTag;

	FDelegateHandle HealthChangedDelegateHandle;
	FDelegateHandle MaxHealthChangedDelegateHandle;
	FDelegateHandle ManaChangedDelegateHandle;
	FDelegateHandle MaxManaChangedDelegateHandle;
	FDelegateHandle LevelChangedDelegateHandle;

	virtual void BeginPlay() override;

	virtual void HealthChanged(const FOnAttributeChangeData& Data);
	virtual void MaxHealthChanged(const FOnAttributeChangeData& Data);
	virtual void ManaChanged(const FOnAttributeChangeData& Data);
	virtual void MaxManaChanged(const FOnAttributeChangeData& Data);
	virtual void LevelChanged(const FOnAttributeChangeData& Data);

	virtual void StunTagChanged(const FGameplayTag CallbackTag, int32 NewTag);

};
