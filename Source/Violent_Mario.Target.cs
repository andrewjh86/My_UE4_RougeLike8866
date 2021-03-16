// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class Violent_MarioTarget : TargetRules
{
	public Violent_MarioTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("Violent_Mario");
		//ExtraModuleNames.AddRange(new string[] { "Violent_Mario", "MyAbilitySystem" });
	}

}
