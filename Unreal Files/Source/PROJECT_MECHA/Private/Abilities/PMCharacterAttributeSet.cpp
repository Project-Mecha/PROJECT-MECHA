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
	DOREPLIFETIME_CONDITION_NOTIFY(UPMCharacterAttributeSet, Level, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UPMCharacterAttributeSet, AttackPower, COND_None, REPNOTIFY_Always)

}

void UPMCharacterAttributeSet::OnRep_Level(const FGameplayAttributeData& OldLevel)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UPMCharacterAttributeSet, Health, OldLevel);
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

void UPMCharacterAttributeSet::OnRep_AttackPower(const FGameplayAttributeData& OldAttackPower)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UPMCharacterAttributeSet, AttackPower, OldAttackPower);
}
