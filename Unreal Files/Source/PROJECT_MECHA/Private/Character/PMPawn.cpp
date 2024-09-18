// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PMPawn.h"

#include "Character/PMPlayerState.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Abilities/PMGameplayAbility.h"
#include "Abilities/PMCharacterASC.h"
#include "Abilities/PMCharacterAttributeSet.h"
#include "Net/UnrealNetwork.h"

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
	BackSpringArm->bEnableCameraLag = true;
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

float APMPawn::GetMaxMana()
{
	if (PlayerAttributeSet) return PlayerAttributeSet->GetMaxMana();
	return 1.0f;
}

void APMPawn::SetMana(float Mana)
{
	if (PlayerAttributeSet)
		PlayerAttributeSet->SetMana(Mana);
}

void APMPawn::SetHealth(float Health)
{
	if (PlayerAttributeSet)
		PlayerAttributeSet->SetHealth(Health);
}

float APMPawn::GetAttributeLevel()
{
	if (PlayerAttributeSet) return PlayerAttributeSet->GetLevel();
	return 1.0f;
}

void APMPawn::BeginPlay()
{
	Super::BeginPlay();

	SetReplicates(true);
	SetReplicateMovement(true);

	AnimInstance = this->GetMesh()->GetAnimInstance();

	StartingCameraBoomArmLength = GetBackCameraBoomLength();
	StartingCameraBoomLocation = BackSpringArm->GetRelativeLocation();
}

void APMPawn::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	InitializeStartingValues();

	AddStartupEffects();
	GiveAbilities();
}

void APMPawn::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	InitializeStartingValues();
}

void APMPawn::InitializeStartingValues()
{
	if (APMPlayerState* PS = GetPlayerState<APMPlayerState>())
	{
		UPMCharacterASC* PlayerAbilitySystemComponent = Cast<UPMCharacterASC>(PS->GetAbilitySystemComponent());

		PS->GetAbilitySystemComponent()->InitAbilityActorInfo(PS, this);

		AbilitySystemComponent = PlayerAbilitySystemComponent;
		PlayerAttributeSet = PS->GetAttributeSet();

		InitializeAttributes();

		PlayerAbilitySystemComponent->SetTagMapCount(DeadTag, 0);

		SetHealth(GetMaxHealth());
		SetMana(GetMaxMana());
	}
}

void APMPawn::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

}

void APMPawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// steering 
		EnhancedInputComponent->BindAction(SteeringAction, ETriggerEvent::Triggered, this, &APMPawn::Steering);
		EnhancedInputComponent->BindAction(SteeringAction, ETriggerEvent::Completed, this, &APMPawn::Steering);

		// throttle 
		EnhancedInputComponent->BindAction(ThrottleAction, ETriggerEvent::Triggered, this, &APMPawn::Throttle);
		EnhancedInputComponent->BindAction(ThrottleAction, ETriggerEvent::Completed, this, &APMPawn::Throttle);

		// break 
		EnhancedInputComponent->BindAction(BrakeAction, ETriggerEvent::Triggered, this, &APMPawn::Brake);
		EnhancedInputComponent->BindAction(BrakeAction, ETriggerEvent::Started, this, &APMPawn::StartBrake);
		EnhancedInputComponent->BindAction(BrakeAction, ETriggerEvent::Completed, this, &APMPawn::StopBrake);

		// handbrake 
		EnhancedInputComponent->BindAction(HandbrakeAction, ETriggerEvent::Started, this, &APMPawn::StartHandbrake);
		EnhancedInputComponent->BindAction(HandbrakeAction, ETriggerEvent::Completed, this, &APMPawn::StopHandbrake);

		// look around 
		EnhancedInputComponent->BindAction(LookAroundAction, ETriggerEvent::Triggered, this, &APMPawn::LookAround);

		// toggle camera 
		EnhancedInputComponent->BindAction(ToggleCameraAction, ETriggerEvent::Triggered, this, &APMPawn::ToggleCamera);
	}
}

void APMPawn::Tick(float Delta)
{
	Super::Tick(Delta);

	HandleCameraLagAndFOV(Delta);
}

void APMPawn::Steering(const FInputActionValue& Value)
{
	float SteeringValue = Value.Get<float>();

	ChaosVehicleMovement->SetSteeringInput(SteeringValue);
}

void APMPawn::Throttle(const FInputActionValue& Value)
{
	float ThrottleValue = Value.Get<float>();

	ChaosVehicleMovement->SetThrottleInput(ThrottleValue);
}

void APMPawn::Brake(const FInputActionValue& Value)
{
	// get the input magnitude for the brakes
	float BreakValue = Value.Get<float>();

	// add the input
	ChaosVehicleMovement->SetBrakeInput(BreakValue);
}

void APMPawn::StartBrake(const FInputActionValue& Value)
{

}

void APMPawn::StopBrake(const FInputActionValue& Value)
{
	ChaosVehicleMovement->SetBrakeInput(0.0f);
}

void APMPawn::StartHandbrake(const FInputActionValue& Value)
{
	ChaosVehicleMovement->SetHandbrakeInput(true);
}

void APMPawn::StopHandbrake(const FInputActionValue& Value)
{
	ChaosVehicleMovement->SetHandbrakeInput(false);
}

void APMPawn::LookAround(const FInputActionValue& Value)
{
	float LookValue = Value.Get<float>();

	BackSpringArm->AddLocalRotation(FRotator(0.f, LookValue, 0.f));
}

void APMPawn::ToggleCamera(const FInputActionValue& Value)
{
	bFrontCameraActive = !bFrontCameraActive;

	FrontCamera->SetActive(bFrontCameraActive);
	BackCamera->SetActive(!bFrontCameraActive);
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
	//check(AbilitySystemComponent);

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
	//check(AbilitySystemComponent);

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

void APMPawn::HandleCameraLagAndFOV(float DeltaTime)
{
	float VehicleSpeed = GetVehicleMovementComponent()->GetForwardSpeed();
	float MaxSpeed = 80.0f;

	float BaseLagDistance = 10.0f;
	float MaxLagDistance = 110.0f;

	float LagDistance = FMath::Lerp(BaseLagDistance, MaxLagDistance, VehicleSpeed / MaxSpeed);
	BackSpringArm->CameraLagMaxDistance = LagDistance;

	float NormalFOV = 90.f;
	float MaxFOV = 98.f;

	float CurrentFOV = BackCamera->FieldOfView;
	float TargetFOV = FMath::Clamp(FMath::Lerp(NormalFOV, MaxFOV, VehicleSpeed / MaxSpeed), NormalFOV, MaxFOV);
	BackCamera->FieldOfView = FMath::FInterpTo(CurrentFOV, TargetFOV, DeltaTime, 2.0f);
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