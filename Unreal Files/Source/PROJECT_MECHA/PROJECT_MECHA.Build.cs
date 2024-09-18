// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class PROJECT_MECHA : ModuleRules
{
	public PROJECT_MECHA(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "ChaosVehicles", "PhysicsCore", 
			"OnlineSubsystem", "OnlineSubsystemEOS", "UMG", "ApplicationCore" });

		PublicDependencyModuleNames.AddRange(new string[] { "GameplayAbilities", "GameplayTags", "GameplayTasks" });

        if (Target.Platform == UnrealTargetPlatform.Win64) // Assuming 64-bit Windows
        {
            string AptosUiLogicPath = Path.Combine(ModuleDirectory, "../../../build/Release", "AptosUILogic.dll");
            string AptosLibPath = Path.Combine(ModuleDirectory, "../../../build/Release", "Aptos.dll");
            string AptosUiLogic_LPath = Path.Combine(ModuleDirectory, "../../../build/Release", "AptosUILogic.lib");
            string AptosLib_LPath = Path.Combine(ModuleDirectory, "../../../build/Release", "Aptos.lib");
            string destinationDirectory = Target.ProjectFile.Directory.FullName;
            string destinationBinaryDirectory = destinationDirectory + "/Binaries/Win64";

            File.Copy(AptosUiLogicPath, Path.Combine(destinationDirectory, "AptosUILogic.dll"), true);
            File.Copy(AptosLibPath, Path.Combine(destinationDirectory, "Aptos.dll"), true);
            File.Copy(AptosUiLogicPath, Path.Combine(destinationBinaryDirectory, "AptosUILogic.dll"), true);
            File.Copy(AptosLibPath, Path.Combine(destinationBinaryDirectory, "Aptos.dll"), true);
            File.Copy(AptosUiLogic_LPath, Path.Combine(destinationDirectory, "AptosUILogic.lib"), true);
            File.Copy(AptosLib_LPath, Path.Combine(destinationDirectory, "Aptos.lib"), true);

            PublicIncludePaths.AddRange(new string[] { Path.Combine(ModuleDirectory, "../../../") });
            PublicAdditionalLibraries.Add(Path.Combine(destinationDirectory, "Aptos.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(destinationDirectory, "AptosUILogic.lib"));
            PublicDelayLoadDLLs.Add(Path.Combine(destinationDirectory, "Aptos.dll"));
            PublicDelayLoadDLLs.Add(Path.Combine(destinationDirectory, "AptosUILogic.dll"));

        }

        PublicIncludePaths.AddRange(new string[] { "/usr/local/include/" });
        bEnableUndefinedIdentifierWarnings = false;
        CppStandard = CppStandardVersion.Cpp17;
    }
}
