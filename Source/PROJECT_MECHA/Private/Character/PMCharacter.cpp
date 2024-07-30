// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PMCharacter.h"

// Sets default values
APMCharacter::APMCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APMCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APMCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APMCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UAbilitySystemComponent* APMCharacter::GetAbilitySystemComponent() const
{
	return CharacterAbilitySystemComponent;
}

