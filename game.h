#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "BoardView.h"

class BoardView;
class Board;

class Game
{
public:
    Game(BoardView* view);
    /**
     * @brief move
     * @param direction
     * 这边不能用 Board::Direction why 不懂
     */
    void move(int direction);
    Board* getBoard();
private:
    BoardView* gameView;
    Board* myBoard;
    unsigned int score;
};

#endif // GAME_H
