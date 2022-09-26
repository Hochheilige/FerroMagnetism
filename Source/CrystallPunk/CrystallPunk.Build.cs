// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class CrystallPunk : ModuleRules
{
	public CrystallPunk(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		PublicIncludePaths.Add("CrystallPunk/Contract");
		PublicIncludePaths.Add("CrystallPunk/Implementation");

		PublicIncludePaths.Add("CrystallPunk/Implementation/Utils/Log");
		PublicIncludePaths.Add("CrystallPunk/Implementation/Utils/Assert");
		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
