// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehiclePawn.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "ChaosWheeledVehicleMovementComponent.h"
#include "GameplayTagContainer.h"
#include "PROJECT_MECHA/PROJECT_MECHA.h"
#include "PMPawn.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UInputAction;
struct FInputActionValue;

UCLASS()
class PROJECT_MECHA_API APMPawn : public AWheeledVehiclePawn, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
	/** Spring Arm for the front camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* FrontSpringArm;

	/** Front Camera component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FrontCamera;

	/** Spring Arm for the back camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* BackSpringArm;

	/** Back Camera component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* BackCamera;

	/** Cast pointer to the Chaos Vehicle movement component */
	TObjectPtr<UChaosWheeledVehicleMovementComponent> ChaosVehicleMovement;

public:
	APMPawn();

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	virtual void Tick(float Delta) override;

	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual void InitializeAttributes();
	virtual void AddStartupEffects();
	virtual void GiveAbilities();

	UFUNCTION(BlueprintCallable, Category = "Character|Camera")
	FORCEINLINE float GetBackCameraBoomLength() const { return BackSpringArm->TargetArmLength; }

	FORCEINLINE USpringArmComponent* GetFrontSpringArm() const { return FrontSpringArm; }
	
	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FrontCamera; }
	
	FORCEINLINE USpringArmComponent* GetBackSpringArm() const { return BackSpringArm; }
	
	FORCEINLINE UCameraComponent* GetBackCamera() const { return BackCamera; }
	
	FORCEINLINE const TObjectPtr<UChaosWheeledVehicleMovementComponent>& GetChaosVehicleMovement() const { return ChaosVehicleMovement; }

protected:
	/** Steering Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* SteeringAction;

	/** Throttle Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* ThrottleAction;

	/** Brake Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* BrakeAction;

	/** Handbrake Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* HandbrakeAction;

	/** Look Around Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* LookAroundAction;

	/** Toggle Camera Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* ToggleCameraAction;

	/** Keeps track of which camera is active */
	bool bFrontCameraActive = false;

	float StartingCameraBoomArmLength = 0.f;
	FVector StartingCameraBoomLocation = FVector();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character|Abilities", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UPMCharacterASC> AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character|Abilities", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UPMCharacterAttributeSet> PlayerAttributeSet;

	FGameplayTag DeadTag;
	FGameplayTag EffectRemoveOnDeathTag;

	//Gameplay effects and abilities
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Character|Abilities")
	TSubclassOf<class UGameplayEffect> DefaultAttributeEffect;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Character|Abilities")
	TArray<TSubclassOf<class UGameplayEffect>> StartupAttributeEffect;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Character|Abilities")
	TArray<TSubclassOf<class UPMGameplayAbility>> DefaultPlayerAbilities;

	//Character Props
	TObjectPtr<UAnimInstance> AnimInstance;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Character|Props")
	TObjectPtr<UAnimationAsset> DeathAnimation;

	float MaxCameraLagDistance = 110.f;
	

protected:
	virtual void BeginPlay();

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	void InitializeStartingValues();

	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;

	//INPUT
	/** Handles steering input */
	void Steering(const FInputActionValue& Value);

	/** Handles throttle input */
	void Throttle(const FInputActionValue& Value);

	/** Handles brake input */
	void Brake(const FInputActionValue& Value);

	/** Handles brake start/stop inputs */
	void StartBrake(const FInputActionValue& Value);
	void StopBrake(const FInputActionValue& Value);

	/** Handles handbrake start/stop inputs */
	void StartHandbrake(const FInputActionValue& Value);
	void StopHandbrake(const FInputActionValue& Value);

	/** Handles look around input */
	void LookAround(const FInputActionValue& Value);

	/** Handles toggle camera input */
	void ToggleCamera(const FInputActionValue& Value);


	//GETTERS
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetHealth();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetMaxHealth();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetMaxMana();

	void SetMana(float Health);

	void SetHealth(float Health);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetAttributeLevel();


	//GAMEPLAY
	void HandleCameraLagAndFOV(float DeltaTime);

	void Die();
	void FinishDying();

	void RemoveAbilities();
};
