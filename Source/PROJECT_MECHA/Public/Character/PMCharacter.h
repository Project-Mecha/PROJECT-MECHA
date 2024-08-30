// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PMCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UInputAction;
struct FInputActionValue;

UCLASS()
class PROJECT_MECHA_API APMCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Spring Arm for the camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm;

	/** Camera component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;

public:
	APMCharacter();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FORCEINLINE USpringArmComponent* GetpringArm() const { return SpringArm; }

	FORCEINLINE UCameraComponent* GetCamera() const { return FollowCamera; }

protected:
	//Inputs
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* BrakeAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAroundAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* SteeringAction;

	//Character Props
	TObjectPtr<UAnimInstance> AnimInstance;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Character|Props")
	TObjectPtr<UAnimationAsset> DeathAnimation;

	float MaxCameraLagDistance = 110.f;

	float CurrentSpeed;
	float ReverseSpeed;
	float MaxSpeed;
	float MinSpeedReverse;
	float Acceleration;
	float Deceleration;
	float TurnRate;

	bool bIsDecelerating;

protected:
	virtual void BeginPlay() override;

	void Move(const FInputActionValue& Value);

	void Brake(const FInputActionValue& Value);

	void LookAround(const FInputActionValue& Value);

	void Steering(const FInputActionValue& Value);
};
