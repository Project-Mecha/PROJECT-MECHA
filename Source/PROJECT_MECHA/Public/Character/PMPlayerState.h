// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
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
	int32 GetLevel() const;

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

	void HealthChanged(const FOnAttributeChangeData& Data) const;
	void MaxHealthChanged(const FOnAttributeChangeData& Data) const;
	void ManaChanged(const FOnAttributeChangeData& Data) const;
	void MaxManaChanged(const FOnAttributeChangeData& Data) const;
	void LevelChanged(const FOnAttributeChangeData& Data) const;

	void StunTagChanged(const FGameplayTag CallbackTag, int32 NewTag) const;

};
