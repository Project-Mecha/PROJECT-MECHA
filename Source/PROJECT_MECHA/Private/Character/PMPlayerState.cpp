// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PMPlayerState.h"

#include "Abilities/PMCharacterAttributeSet.h"

APMPlayerState::APMPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UPMCharacterASC>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);

	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UPMCharacterAttributeSet>("Attributes");

	NetUpdateFrequency = 100.f;

	DeadTag = FGameplayTag::RequestGameplayTag(FName("State.Dead"));
}

void APMPlayerState::BeginPlay()
{
	Super::BeginPlay();

	if(AbilitySystemComponent)
	{
		HealthChangedDelegateHandle = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetHealthAttribute()).AddUObject(this, &APMPlayerState::HealthChanged);
		MaxHealthChangedDelegateHandle = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetMaxHealthAttribute()).AddUObject(this, &APMPlayerState::MaxHealthChanged);
		ManaChangedDelegateHandle = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetManaAttribute()).AddUObject(this, &APMPlayerState::ManaChanged);
		MaxManaChangedDelegateHandle = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetMaxManaAttribute()).AddUObject(this, &APMPlayerState::MaxManaChanged);
		LevelChangedDelegateHandle = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetLevelAttribute()).AddUObject(this, &APMPlayerState::LevelChanged);

		AbilitySystemComponent->RegisterGameplayTagEvent(FGameplayTag::RequestGameplayTag(FName("State.Debuff.Stun")), EGameplayTagEventType::NewOrRemoved).AddUObject(this, &APMPlayerState::StunTagChanged);
	}
}

UAbilitySystemComponent* APMPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UPMCharacterAttributeSet* APMPlayerState::GetAttributeSet() const
{
	return AttributeSet;
}

bool APMPlayerState::IsAlive() const
{
	return GetHealth() > 0.f;
}

void APMPlayerState::ShowAbilityConfirmCancelText(bool bSHowText)
{

}

float APMPlayerState::GetHealth() const
{
	return AttributeSet->GetHealth();
}

float APMPlayerState::GetMaxHealth() const
{
	return AttributeSet->GetMaxHealth();
}

float APMPlayerState::GetMana() const
{
	return AttributeSet->GetMana();
}

float APMPlayerState::GetMaxMana() const
{
	return AttributeSet->GetMaxMana();
}

int32 APMPlayerState::GetAbilityLevel() const
{
	return AttributeSet->GetLevel();
}

void APMPlayerState::HealthChanged(const FOnAttributeChangeData& Data)
{

}

void APMPlayerState::MaxHealthChanged(const FOnAttributeChangeData& Data)
{

}

void APMPlayerState::ManaChanged(const FOnAttributeChangeData& Data)
{

}

void APMPlayerState::MaxManaChanged(const FOnAttributeChangeData& Data)
{

}

void APMPlayerState::LevelChanged(const FOnAttributeChangeData& Data)
{

}

void APMPlayerState::StunTagChanged(const FGameplayTag CallbackTag, int32 NewCount)
{
	if(NewCount > 0)
	{
		FGameplayTagContainer AbilityTagsToCancel;
		AbilityTagsToCancel.AddTag(FGameplayTag::RequestGameplayTag(FName("Ability")));

		FGameplayTagContainer AbilityTagsToIgnore;
		AbilityTagsToIgnore.AddTag(FGameplayTag::RequestGameplayTag(FName("Ability.NotCanceledByStun")));

		AbilitySystemComponent->CancelAbilities(&AbilityTagsToCancel, &AbilityTagsToIgnore);
	}
}