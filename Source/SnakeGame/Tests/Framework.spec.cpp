// SnakeGame project

#if WITH_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Tests/Utils/TestUtils.h"
#include "Framework/SG_GameMode.h"
#include "Framework/SG_Pawn.h"
#include "Misc/PathViews.h"

BEGIN_DEFINE_SPEC(FSnakeFramework, "Snake",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter | EAutomationTestFlags::HighPriority)
UWorld* World;
END_DEFINE_SPEC(FSnakeFramework)

void FSnakeFramework::Define()
{
    using namespace LifeExe::Test;

    Describe("Framework", [this]() {  //
        It("GameMapShouldExist",
            [this]()
            {
                const TArray<FString> SnakeGameMaps = {"GameLevel"};

                TArray<FString> AllProjectMaps;
                IFileManager::Get().FindFilesRecursive(AllProjectMaps, *FPaths::ProjectContentDir(), TEXT("*.umap"), true, false);

                for (const auto& SnakeGameMap : SnakeGameMaps)
                {
                    const bool SnakeMapExists = AllProjectMaps.ContainsByPredicate(
                        [&](const FString& ProjectMap)
                        {
                            FStringView OutPath, OutName, OutExtension;
                            FPathViews::Split(FStringView(ProjectMap), OutPath, OutName, OutExtension);
                            return SnakeGameMap.Equals(FString(OutName));
                        });
                    TestTrueExpr(SnakeMapExists);
                }

                UE_LOG(LogTemp, Display, TEXT("------------------------"));
                for (const auto& MapName : AllProjectMaps)
                {
                    UE_LOG(LogTemp, Display, TEXT("Full path to disk: %s"), *MapName);

                    FStringView OutPath, OutName, OutExtension;
                    FPathViews::Split(FStringView(MapName), OutPath, OutName, OutExtension);
                    UE_LOG(LogTemp, Display, TEXT("Map name: %s"), *FString(OutName));
                }
                UE_LOG(LogTemp, Display, TEXT("++++++++++++++++++++++++"));
            });
    });

    Describe("Framework", [this]() {  //
        BeforeEach(
            [this]()
            {
                AutomationOpenMap("GameLevel");
                World = GetTestGameWorld();
            });

        It("ClassesMightBeSetupCorrectly",
            [this]()
            {
                TestNotNull("Snake game mode set up", Cast<ASG_GameMode>(World->GetAuthGameMode()));
                TestNotNull("Snake pawn set up", Cast<ASG_Pawn>(World->GetFirstPlayerController()->GetPawn()));
            });

        xIt("PawnLocationShouldBeAdjustedCorrectly", [this]() { unimplemented(); });
    });
}

#endif
