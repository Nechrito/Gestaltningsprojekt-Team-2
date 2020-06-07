

using UnrealBuildTool;
using System.Collections.Generic;

public class ChlorineTarget : TargetRules
{
	public ChlorineTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "Chlorine" } );
	}
}
