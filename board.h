#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "BoardView.h"

class Board
{
    static const int TileNum = 16;
    static const int SideLength = 4;
public:
    enum Direction{
        UP,DOWN,RIGHT,LEFT
    };
//    int test;
    friend class BoardView;
    Board(BoardView* view);
    void move(Direction direction);
private:
    bool moveUp(int row, int col);
    bool moveDown(int row, int col);
    bool moveRight(int row, int col);
    bool moveLeft(int row, int col);
    //! 将棋盘转为初始的样子
    void init();
    //! 生成随机的格子
    void generateRandomTile();
    void generateRandomTileDouble();
    BoardView* gameView;
    std::vector<int> Tiles;
};

#endif // BOARD_H
