// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PROJECT_MECHA : ModuleRules
{
	public PROJECT_MECHA(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "ChaosVehicles", "PhysicsCore", 
			"OnlineSubsystem", "OnlineSubsystemEOS" });

		PublicDependencyModuleNames.AddRange(new string[] { "GameplayAbilities", "GameplayTags", "GameplayTasks" });
    }
}
