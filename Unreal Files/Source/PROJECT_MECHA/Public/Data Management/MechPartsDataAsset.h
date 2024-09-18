// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data Management/PMBaseDataAsset.h"
#include "MechPartsDataAsset.generated.h"

//UENUM(BlueprintType)
//enum class EMechType : uint8
//{
//	SlimRobo,
//	Red
//};
//
//UENUM(BlueprintType)
//enum class EMechPart : uint8
//{
//	Head,
//	Torso,
//	ArmLeft,
//	ArmRight,
//	LeftLeg,
//	RightLeg
//};

UCLASS()
class PROJECT_MECHA_API UMechPartsDataAsset : public UPMBaseDataAsset
{
	GENERATED_BODY()
	
public:
	/*UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Props")
	EMechType MechType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Props")
	EMechPart MechPart;*/

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Props")
	TArray<TSoftObjectPtr<USkeletalMesh>> MechParts;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Props")
	TArray<TSoftObjectPtr<UMaterialInterface>> PartMaterials;

public:
	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("MechPart", GetFName());
	}
};
