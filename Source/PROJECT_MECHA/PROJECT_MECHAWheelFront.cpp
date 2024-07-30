// Copyright Epic Games, Inc. All Rights Reserved.

#include "PROJECT_MECHAWheelFront.h"
#include "UObject/ConstructorHelpers.h"

UPROJECT_MECHAWheelFront::UPROJECT_MECHAWheelFront()
{
	AxleType = EAxleType::Front;
	bAffectedBySteering = true;
	MaxSteerAngle = 40.f;
}