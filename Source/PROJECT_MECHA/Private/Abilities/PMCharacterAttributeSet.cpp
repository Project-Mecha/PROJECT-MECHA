// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/PMCharacterAttributeSet.h"

#include "Net/UnrealNetwork.h"

UPMCharacterAttributeSet::UPMCharacterAttributeSet()
{

}

void UPMCharacterAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UPMCharacterAttributeSet, Health, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UPMCharacterAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UPMCharacterAttributeSet, Mana, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UPMCharacterAttributeSet, MaxMana, COND_None, REPNOTIFY_Always)
}

void UPMCharacterAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UPMCharacterAttributeSet, Health, OldHealth);
}

void UPMCharacterAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UPMCharacterAttributeSet, MaxHealth, OldMaxHealth);
}

void UPMCharacterAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UPMCharacterAttributeSet, Mana, OldMana);

}

void UPMCharacterAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UPMCharacterAttributeSet, MaxMana, OldMaxMana);
}
