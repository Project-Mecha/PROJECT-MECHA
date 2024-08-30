// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PMQuickMatchWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_MECHA_API UPMQuickMatchWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;

protected:
	/** Controls the display of speed in Km/h or MPH */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Vehicle)
	bool bIsMPH = false;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* RemainingTime;

public:
	/** Called to update the speed display */
	void UpdateSpeed(float NewSpeed);

	/** Called to update the gear display */
	void UpdateGear(int32 NewGear);

protected:

	/** Implemented in Blueprint to display the new speed */
	UFUNCTION(BlueprintImplementableEvent, Category = Vehicle)
	void OnSpeedUpdate(float NewSpeed);

	/** Implemented in Blueprint to display the new gear */
	UFUNCTION(BlueprintImplementableEvent, Category = Vehicle)
	void OnGearUpdate(int32 NewGear);
};
