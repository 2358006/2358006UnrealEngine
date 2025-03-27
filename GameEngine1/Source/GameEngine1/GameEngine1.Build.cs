// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GameEngine1 : ModuleRules
{
	public GameEngine1(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
