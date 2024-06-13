
// SnakeGame project

#include "Game.h"
#include "Grid.h"

DEFINE_LOG_CATEGORY_STATIC(LogGame, All, All)

using namespace Snake;

Snake::Game::Game(const Settings& settings) : c_settings(settings)
{
    m_grid = MakeShared<Grid>(settings.gridDims);
}
