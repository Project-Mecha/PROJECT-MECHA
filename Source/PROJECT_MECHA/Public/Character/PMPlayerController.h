// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "PMPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_MECHA_API APMPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	/** Input Mapping Context to be used for player input */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* PMInputMappingContext;

protected:
	virtual void BeginPlay() override;

	virtual void OnPossess(APawn* NewPawn) override;
};
