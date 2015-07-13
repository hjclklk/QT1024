#include "game.h"
#include <QDebug>
Game::Game(BoardView *view):
    gameView(view)
{
    myBoard = new Board(view);
    score = 0;
}

void Game::move(int direction)
{

    myBoard->move((Board::Direction)direction);
}

Board* Game::getBoard()
{
    return myBoard;
}
