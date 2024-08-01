// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PMPawn.h"

#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Abilities/PMGameplayAbility.h"
#include "Abilities/PMCharacterASC.h"
#include "Abilities/PMCharacterAttributeSet.h"
#include "ChaosWheeledVehicleMovementComponent.h"

APMPawn::APMPawn()
{
	// construct the front camera boom
	FrontSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Front Spring Arm"));
	FrontSpringArm->SetupAttachment(GetMesh());
	FrontSpringArm->TargetArmLength = 0.0f;
	FrontSpringArm->bDoCollisionTest = false;
	FrontSpringArm->bEnableCameraRotationLag = true;
	FrontSpringArm->CameraRotationLagSpeed = 15.0f;
	FrontSpringArm->SetRelativeLocation(FVector(30.0f, 0.0f, 120.0f));

	FrontCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Front Camera"));
	FrontCamera->SetupAttachment(FrontSpringArm);
	FrontCamera->bAutoActivate = false;

	// construct the back camera boom
	BackSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Back Spring Arm"));
	BackSpringArm->SetupAttachment(GetMesh());
	BackSpringArm->TargetArmLength = 650.0f;
	BackSpringArm->SocketOffset.Z = 150.0f;
	BackSpringArm->bDoCollisionTest = false;
	BackSpringArm->bInheritPitch = false;
	BackSpringArm->bInheritRoll = false;
	BackSpringArm->bEnableCameraRotationLag = true;
	BackSpringArm->CameraRotationLagSpeed = 2.0f;
	BackSpringArm->CameraLagMaxDistance = 50.0f;

	BackCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Back Camera"));
	BackCamera->SetupAttachment(BackSpringArm);

	GetMesh()->SetSimulatePhysics(true);
	GetMesh()->SetCollisionProfileName(FName("Vehicle"));

	// get the Chaos Wheeled movement component
	ChaosVehicleMovement = CastChecked<UChaosWheeledVehicleMovementComponent>(GetVehicleMovement());

	DeadTag = FGameplayTag::RequestGameplayTag(FName("State.Dead"));
	EffectRemoveOnDeathTag = FGameplayTag::RequestGameplayTag(FName("State.RemoveOnDeath"));
}

float APMPawn::GetHealth()
{
	if (PlayerAttributeSet) return PlayerAttributeSet->GetHealth();
	return 1.0f;
}

float APMPawn::GetMaxHealth()
{
	if (PlayerAttributeSet) return PlayerAttributeSet->GetMaxHealth();
	return 1.0f;
}

float APMPawn::GetAttributeLevel()
{
	if (PlayerAttributeSet) return PlayerAttributeSet->GetLevel();
	return 1.0f;
}

void APMPawn::BeginPlay()
{
	Super::BeginPlay();

	AnimInstance = this->GetMesh()->GetAnimInstance();
}

void APMPawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


}

void APMPawn::Tick(float Delta)
{
	Super::Tick(Delta);

}

void APMPawn::Steering(const FInputActionValue& Value)
{

}

void APMPawn::Throttle(const FInputActionValue& Value)
{
}

void APMPawn::StartHandbrake(const FInputActionValue& Value)
{
}

void APMPawn::StopHandbrake(const FInputActionValue& Value)
{
}

void APMPawn::LookAround(const FInputActionValue& Value)
{
}

void APMPawn::ToggleCamera(const FInputActionValue& Value)
{
}

void APMPawn::Die()
{
	RemoveAbilities();

	GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	ChaosVehicleMovement->StopMovementImmediately();
	//ChaosVehicleMovement->Velocity = FVector(0);

	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->CancelAllAbilities();

		FGameplayTagContainer EffectsTagsToRemove;
		EffectsTagsToRemove.AddTag(EffectRemoveOnDeathTag);

		int NumOfEffectsRemoved = AbilitySystemComponent->RemoveActiveEffectsWithTags(EffectsTagsToRemove);
		AbilitySystemComponent->AddLooseGameplayTag(DeadTag);
	}

	if (DeathAnimation)
		this->GetMesh()->PlayAnimation(DeathAnimation, false);
}

void APMPawn::FinishDying()
{
	Destroy();
}

void APMPawn::RemoveAbilities()
{
	if (!HasAuthority() || !AbilitySystemComponent || !AbilitySystemComponent->bCharacterAbilitiesGiven)
		return;

	TArray<FGameplayAbilitySpecHandle> AbilitiesToRemove;
	for (const FGameplayAbilitySpec& Spec : AbilitySystemComponent->GetActivatableAbilities())
	{
		if (Spec.SourceObject == this && DefaultPlayerAbilities.Contains(Spec.Ability->GetClass()))
			AbilitySystemComponent->ClearAbility(Spec.Handle);
	}

	AbilitySystemComponent->bCharacterAbilitiesGiven = false;
}

UAbilitySystemComponent* APMPawn::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void APMPawn::InitializeAttributes()
{
	check(AbilitySystemComponent);

	if (AbilitySystemComponent && DefaultAttributeEffect)
	{
		FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
		EffectContext.AddSourceObject(this);

		FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(DefaultAttributeEffect, GetAttributeLevel(), EffectContext);

		if (SpecHandle.IsValid())
		{
			FActiveGameplayEffectHandle GEHandle = AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
		}
	}

	AbilitySystemComponent->bAttributesInitialized = true;
}

void APMPawn::AddStartupEffects()
{
	check(AbilitySystemComponent);

	if (AbilitySystemComponent)
	{
		FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
		EffectContext.AddSourceObject(this);

		for (const TSubclassOf<UGameplayEffect>& Effect : StartupAttributeEffect)
		{
			AbilitySystemComponent->ApplyGameplayEffectToSelf(Effect.GetDefaultObject(), GetAttributeLevel(), EffectContext);

			/*FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(Effect, GetLevel(), EffectContext);

			if (SpecHandle.IsValid())
			{
				FActiveGameplayEffectHandle GEHandle = AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
			}*/
		}
	}

	AbilitySystemComponent->bStartupEffectsGiven = true;
}

void APMPawn::GiveAbilities()
{
	if (!HasAuthority() || !AbilitySystemComponent || !AbilitySystemComponent->bCharacterAbilitiesGiven)
		return;

	for (const TSubclassOf<UPMGameplayAbility>& StartupAbility : DefaultPlayerAbilities)
	{
		AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(StartupAbility, static_cast<int32>(StartupAbility.GetDefaultObject()->AbilityID), static_cast<int32>(StartupAbility.GetDefaultObject()->AbilityInputID), this));
	}

	AbilitySystemComponent->bCharacterAbilitiesGiven = true;
}
