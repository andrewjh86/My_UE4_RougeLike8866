// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class Violent_MarioEditorTarget : TargetRules
{
	public Violent_MarioEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("Violent_Mario");
		//ExtraModuleNames.AddRange(new string[] { "Violent_Mario", "MyAbilitySystem" });

	}
}
