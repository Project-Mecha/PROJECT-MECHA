// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/PMQuickMatchWidget.h"

void UPMQuickMatchWidget::NativeConstruct()
{
	Super::NativeConstruct();

}

void UPMQuickMatchWidget::UpdateSpeed(float NewSpeed)
{
	float FormattedSpeed = FMath::Abs(NewSpeed) * (bIsMPH ? 0.022f : 0.036f);

	OnSpeedUpdate(FormattedSpeed);
}

void UPMQuickMatchWidget::UpdateGear(int32 NewGear)
{
	OnGearUpdate(NewGear);
}