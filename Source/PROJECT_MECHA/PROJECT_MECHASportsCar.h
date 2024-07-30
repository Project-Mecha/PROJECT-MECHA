// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PROJECT_MECHAPawn.h"
#include "PROJECT_MECHASportsCar.generated.h"

/**
 *  Sports car wheeled vehicle implementation
 */
UCLASS(abstract)
class PROJECT_MECHA_API APROJECT_MECHASportsCar : public APROJECT_MECHAPawn
{
	GENERATED_BODY()
	
public:

	APROJECT_MECHASportsCar();
};
