// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PROJECTMECHA_Gameinstance.h"
#include "PMCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UInputAction;
struct FInputActionValue;

UENUM(BlueprintType)
enum class EMechType : uint8
{
	SlimRobo,
	Red
};

USTRUCT(BlueprintType)
struct PROJECT_MECHA_API FMechPartsData : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	EMechType MechType;
	UPROPERTY(EditAnywhere)
	TArray<TObjectPtr<USkeletalMesh>> BodyParts;
	UPROPERTY(EditAnywhere)
	TArray<TObjectPtr<UMaterialInterface>> PartMaterials;
};

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

	FORCEINLINE float GetForwardSpeed() const { return FVector::DotProduct(GetVelocity(), GetActorForwardVector()); }

protected:
	//Inputs
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* BrakeAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAroundAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* TurnAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* SteeringAction;

	//Character Props
	TObjectPtr<UAnimInstance> AnimInstance;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Character|Props")
	TObjectPtr<UDataTable> PartsDataTable;

	FMechPartsData* PartData;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Character|Props")
	EMechType MechType;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Character|Props")
	TObjectPtr<UAnimationAsset> DeathAnimation;

	float MaxCameraLagDistance = 110.f;

	float CurrentSpeed;
	float MaxSpeed;
	float MaxSpeedReverse;
	float Acceleration;
	float Deceleration;
	float TurnRate;

	bool bIsDecelerating;
	bool bIsReversing = false;

protected:
	virtual void BeginPlay() override;

	void Move(const FInputActionValue& Value);

	void Brake(const FInputActionValue& Value);

	void LookAround(const FInputActionValue& Value);

	void TurnPlayer(const FInputActionValue& Value);
	
	void Steering(const FInputActionValue& Value);

	UFUNCTION(BlueprintCallable)
	TArray<USkeletalMesh*> GetBodyParts(FName PartName);

	UFUNCTION(BlueprintCallable)
	TArray<UMaterialInterface*> GetPartMaterials(FName PartName);

	UFUNCTION(BlueprintCallable)
	FMeshInfo CheckAndGetParts();
};
