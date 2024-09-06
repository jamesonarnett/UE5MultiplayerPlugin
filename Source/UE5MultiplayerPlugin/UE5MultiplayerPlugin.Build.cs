// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UE5MultiplayerPlugin : ModuleRules
{
	public UE5MultiplayerPlugin(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "UMG", "OnlineSubsystemSteam", "OnlineSubsystem" });
	}
}
