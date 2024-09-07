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

    GetCharacterMovement()->bOrientRotationToMovement = false;
    GetCharacterMovement()->RotationRate = FRotator(0.0f, 100.0f, 0.0f);
    GetCharacterMovement()->JumpZVelocity = 500.f;
    GetCharacterMovement()->AirControl = 0.3f;
    GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
    GetCharacterMovement()->BrakingDecelerationWalking = 100.f;

    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    SpringArm->SetupAttachment(RootComponent);
    SpringArm->TargetArmLength = 300.0f;
    SpringArm->bUsePawnControlRotation = false;
    SpringArm->bInheritPitch = false;
    SpringArm->bInheritRoll = false;
    SpringArm->bEnableCameraRotationLag = true;
    SpringArm->bEnableCameraLag = true;
    SpringArm->CameraRotationLagSpeed = 2.0f;
    SpringArm->CameraLagMaxDistance = 50.0f;

    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
    FollowCamera->bUsePawnControlRotation = false;

    CurrentSpeed = 0.0f;
    MaxSpeed = 3000.0f;
    MaxSpeedReverse = -1000.0f;
    Acceleration = 3000.0f;
    Deceleration = 150.f;
    TurnRate = .6f;
    bIsDecelerating = false;

    GetCharacterMovement()->MaxWalkSpeed = MaxSpeed;
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
        float CharacterVelocity = GetCharacterMovement()->Velocity.Size();

        if (CharacterVelocity > 0.0f)
        {
            CharacterVelocity -= Deceleration * DeltaTime;
            CharacterVelocity = FMath::Max(CharacterVelocity, 0.0f);
        }
        else if (CharacterVelocity < 0.0f)
        {
            CharacterVelocity += Deceleration * DeltaTime;
            CharacterVelocity = FMath::Min(CharacterVelocity, 0.0f);
        }

        AddMovementInput(GetActorForwardVector(), CharacterVelocity / GetCharacterMovement()->MaxWalkSpeed);

        if (GetCharacterMovement()->Velocity.Size() <= 20.f)
        {
            bIsDecelerating = false;
            GetCharacterMovement()->Velocity = FVector::ZeroVector;
        }
    }

    UE_LOG(LogTemp, Warning, TEXT("Current Speed: %f"), GetCharacterMovement()->Velocity.Size());
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

        EnhancedInputComponent->BindAction(TurnAction, ETriggerEvent::Triggered, this, &APMCharacter::TurnPlayer);

        EnhancedInputComponent->BindAction(SteeringAction, ETriggerEvent::Triggered, this, &APMCharacter::Steering);
    }
}

void APMCharacter::Move(const FInputActionValue& Value)
{
    float MovementValue = Value.Get<float>();
    CurrentSpeed = GetCharacterMovement()->Velocity.Size();
    float AccelerationMultiplier = FMath::Clamp(1.0f - (CurrentSpeed / MaxSpeed), 0.1f, 1.0f);

    if (MovementValue > 0.0f)
    {
        if (CurrentSpeed < 0.0f)
        {
            CurrentSpeed += (Deceleration * 3.5f) * MovementValue * GetWorld()->GetDeltaSeconds();
        }
        else
        {
            CurrentSpeed += (Acceleration * AccelerationMultiplier) * MovementValue * GetWorld()->GetDeltaSeconds();
            CurrentSpeed = FMath::Clamp(CurrentSpeed, MaxSpeedReverse, MaxSpeed);
        }
        AddMovementInput(GetActorForwardVector(), CurrentSpeed / GetCharacterMovement()->MaxWalkSpeed);
        bIsDecelerating = false;
    }
    else if (MovementValue == 0 && CurrentSpeed != 0.0f && !bIsDecelerating)
    {
        bIsDecelerating = true;
    }

}

void APMCharacter::Brake(const FInputActionValue& Value)
{
    float MovementValue = Value.Get<float>();

    CurrentSpeed = GetForwardSpeed();

    if (MovementValue > 0.0f && CurrentSpeed > 0.0f)
    {
        CurrentSpeed = GetCharacterMovement()->Velocity.Size();
        CurrentSpeed -= (Deceleration * 2.f) * MovementValue * GetWorld()->GetDeltaSeconds();
        bIsDecelerating = false;

        AddMovementInput(GetActorForwardVector(), CurrentSpeed / GetCharacterMovement()->MaxWalkSpeed);
    }
    else if (MovementValue > 0.0f && CurrentSpeed <= 0.0f)
    {
        CurrentSpeed -= Acceleration * MovementValue * GetWorld()->GetDeltaSeconds();
        CurrentSpeed = FMath::Clamp(CurrentSpeed, MaxSpeedReverse, MaxSpeed);
        bIsDecelerating = false;

        AddMovementInput(GetActorForwardVector(), CurrentSpeed / GetCharacterMovement()->MaxWalkSpeed);

    }
    else if (MovementValue == 0.0f && CurrentSpeed != 0.0f && !bIsDecelerating)
    {
        bIsDecelerating = true;
    }
}

void APMCharacter::LookAround(const FInputActionValue& Value)
{
    FVector2D LookValue = Value.Get<FVector2D>();
    FRotator NewRotation = SpringArm->GetRelativeRotation();
    float NewPitch = FMath::Clamp(NewRotation.Pitch + LookValue.Y, -45.f, 45.f);
    float NewYaw = FMath::Clamp(NewRotation.Yaw + LookValue.X, -60.f, 60.f);
    SpringArm->SetRelativeRotation(FRotator(NewPitch, NewYaw, NewRotation.Roll));
}

void APMCharacter::TurnPlayer(const FInputActionValue& Value)
{
    float TurnValue = Value.Get<float>();
    AddControllerYawInput(TurnValue * TurnRate);
}

void APMCharacter::Steering(const FInputActionValue& Value)
{
    float SteerValue = Value.Get<float>();

    if (this->GetController())
    {
        const float YawValue = GetControlRotation().Yaw;
        const FRotator YawRotation = FRotator(0, YawValue, 0);
        const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
        float AbsoluteSpeed = GetCharacterMovement()->Velocity.Size();
        float ShiftingSpeedMultiplier = FMath::Clamp(AbsoluteSpeed / GetCharacterMovement()->MaxWalkSpeed, 0.0f, 0.35f);
        SteerValue *= ShiftingSpeedMultiplier;
        AddMovementInput(RightDirection, SteerValue);
    }
}
