// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PMCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
APMCharacter::APMCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

    this->GetCharacterMovement()->bOrientRotationToMovement = true;
    this->GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);
    this->GetCharacterMovement()->JumpZVelocity = 500.f;
    this->GetCharacterMovement()->AirControl = 0.3f;
    this->GetCharacterMovement()->MaxWalkSpeed = 2000.0f;
    this->GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
    this->GetCharacterMovement()->BrakingDecelerationWalking = 100.f;

    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    SpringArm->SetupAttachment(RootComponent);
    SpringArm->TargetArmLength = 300.0f;
    SpringArm->bUsePawnControlRotation = true;

    // Create a follow camera
    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
    FollowCamera->bUsePawnControlRotation = false;

    CurrentSpeed = 0.0f;
    ReverseSpeed = 0.f;
    MaxSpeed = 2000.0f;
    MinSpeedReverse = -500.0f;
    Acceleration = 20.0f;
    Deceleration = 10.0f;
    TurnRate = 45.0f;
}

void APMCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void APMCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if (bIsDecelerating)
    {
        if (CurrentSpeed > 0.0f)
        {
            CurrentSpeed -= Deceleration * DeltaTime;
            CurrentSpeed = FMath::Max(CurrentSpeed, 0.0f);
        }
        else if (ReverseSpeed < 0.0f)
        {
            ReverseSpeed += Deceleration * DeltaTime;
            ReverseSpeed = FMath::Min(ReverseSpeed, 0.0f);
        }

        if (CurrentSpeed > 0.0f)
        {
            AddMovementInput(GetActorForwardVector(), CurrentSpeed * DeltaTime);
        }
        else if (ReverseSpeed < 0.0f)
        {
            AddMovementInput(GetActorForwardVector(), ReverseSpeed * DeltaTime);
        }

        if (CurrentSpeed <= 0.0f && ReverseSpeed >= 0.0f)
        {
            bIsDecelerating = false;
        }
    }

    UE_LOG(LogTemp, Warning, TEXT("Reverse Speed: %f"), ReverseSpeed);

}

void APMCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
        EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APMCharacter::Move);
        EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Completed, this, &APMCharacter::Move);

        EnhancedInputComponent->BindAction(BrakeAction, ETriggerEvent::Triggered, this, &APMCharacter::Brake);
        EnhancedInputComponent->BindAction(BrakeAction, ETriggerEvent::Completed, this, &APMCharacter::Brake);

        EnhancedInputComponent->BindAction(LookAroundAction, ETriggerEvent::Triggered, this, &APMCharacter::LookAround);

        EnhancedInputComponent->BindAction(SteeringAction, ETriggerEvent::Triggered, this, &APMCharacter::Steering);
	}
}

void APMCharacter::Move(const FInputActionValue& Value)
{
	float MovementValue = Value.Get<float>();

    if (MovementValue > 0.0f)
    {
        CurrentSpeed += Acceleration * MovementValue * GetWorld()->GetDeltaSeconds();
        CurrentSpeed = FMath::Clamp(CurrentSpeed, 0.f, MaxSpeed);
        bIsDecelerating = false;
    }
    else if (MovementValue == 0 && CurrentSpeed > 0.0f && !bIsDecelerating)
    {
        bIsDecelerating = true;
    }

    AddMovementInput(GetActorForwardVector(), CurrentSpeed * GetWorld()->GetDeltaSeconds());
}

void APMCharacter::Brake(const FInputActionValue& Value)
{
    float MovementValue = Value.Get<float>();

    if (MovementValue > 0.0f && CurrentSpeed > 0.0f)
    {
        CurrentSpeed -= Deceleration * -MovementValue * GetWorld()->GetDeltaSeconds();
        CurrentSpeed = FMath::Max(CurrentSpeed, 0.0f);
    }
    else if (MovementValue > 0.0f && CurrentSpeed == 0.0f)
    {
        ReverseSpeed -= Acceleration * -MovementValue * GetWorld()->GetDeltaSeconds();
        ReverseSpeed = FMath::Clamp(ReverseSpeed, ReverseSpeed, 0.0f);
        bIsDecelerating = false;

        AddMovementInput(GetActorForwardVector(), ReverseSpeed * GetWorld()->GetDeltaSeconds());
    }
    else if (MovementValue == 0.0f && ReverseSpeed < 0.0f)
    {
        ReverseSpeed += Deceleration * GetWorld()->GetDeltaSeconds();
        ReverseSpeed = FMath::Min(ReverseSpeed, 0.0f);

        AddMovementInput(GetActorForwardVector(), ReverseSpeed * GetWorld()->GetDeltaSeconds());

        if (ReverseSpeed >= 0.0f)
        {
            bIsDecelerating = false;
        }
    }

}

void APMCharacter::LookAround(const FInputActionValue& Value)
{
    float LookValue = Value.Get<float>();

    SpringArm->AddLocalRotation(FRotator(0.f, LookValue, 0.f));
}

void APMCharacter::Steering(const FInputActionValue& Value)
{
    float TurnValue = Value.Get<float>();

    if (TurnValue != 0.0f)
    {
        FRotator NewRotation = GetActorRotation();
        NewRotation.Yaw += TurnValue * TurnRate * GetWorld()->GetDeltaSeconds();

        SetActorRotation(NewRotation);
    }
}

