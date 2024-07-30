// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Abilities/PMCharacterASC.h"
#include "Abilities/PMCharacterAttributeSet.h"
#include "PMCharacter.generated.h"

UCLASS()
class PROJECT_MECHA_API APMCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APMCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/**Ability System Component**/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities, meta = (AllowPrivateAccess = "true"))
	TWeakObjectPtr<UPMCharacterASC> CharacterAbilitySystemComponent;

	TWeakObjectPtr<UPMCharacterAttributeSet> CharacterAttributeSet;

	FGameplayTag DeadTag;
	FGameplayTag EffectRemoveDeadTag;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
};
