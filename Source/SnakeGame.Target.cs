// SnakeGame project

using UnrealBuildTool;
using System.Collections.Generic;

public class SnakeGameTarget : TargetRules
{
    public SnakeGameTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;
        DefaultBuildSettings = BuildSettingsVersion.V5;

        ExtraModuleNames.AddRange(new string[] { "SnakeGame" });

        IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
    }
}
