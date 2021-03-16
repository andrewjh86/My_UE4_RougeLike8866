// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Violent_Mario : ModuleRules
{
	public Violent_Mario(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
