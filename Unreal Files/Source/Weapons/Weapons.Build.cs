// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Weapons : ModuleRules
{
	public Weapons(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "ChaosVehicles", "PhysicsCore", 
			"OnlineSubsystem", "OnlineSubsystemEOS" });
	}
}
