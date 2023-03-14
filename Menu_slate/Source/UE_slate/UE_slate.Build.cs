// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UE_slate : ModuleRules
{
	public UE_slate(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });

        //˽������ģ��
        PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

    }
}
