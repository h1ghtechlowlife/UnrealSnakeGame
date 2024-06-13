// SnakeGame project

#if WITH_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Core/Grid.h"

DEFINE_SPEC(FSnakeGrid, "Snake",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter | EAutomationTestFlags::HighPriority)

// BEGIN_DEFINE_SPEC(FTestClassName, "Category", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter |
// EAutomationTestFlags::HighPriority)

// END_DEFINE_SPEC(FTestClassName)

void FSnakeGrid::Define()
{
    using namespace Snake;

    Describe("CoreGrid", [this]() {  //
        It("DimsMightIncludeWalls",
            [this]()
            {
                const Grid grid(Dim{12, 10});
                TestTrueExpr(grid.dim().width == 14);
                TestTrueExpr(grid.dim().height == 12);
            });
    });
}

#endif
