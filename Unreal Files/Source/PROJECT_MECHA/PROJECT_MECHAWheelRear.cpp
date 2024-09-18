// Copyright Epic Games, Inc. All Rights Reserved.

#include "PROJECT_MECHAWheelRear.h"
#include "UObject/ConstructorHelpers.h"

UPROJECT_MECHAWheelRear::UPROJECT_MECHAWheelRear()
{
	AxleType = EAxleType::Rear;
	bAffectedByHandbrake = true;
	bAffectedByEngine = true;
}