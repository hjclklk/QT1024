#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "observable.h"
class Board: public Observable
{
    static const int TileNum = 16;
    static const int SideLength = 4;
public:
    enum Direction{
        UP,DOWN,RIGHT,LEFT
    };
    Board();
    friend class BoardView;
    void move(Direction direction);
    int getScore();

public slots:
    void reset();

private:
    bool moveUp(int row, int col);
    bool moveDown(int row, int col);
    bool moveRight(int row, int col);
    bool moveLeft(int row, int col);
    //! 将棋盘转为初始的样子
    void init();
    bool isGameOver();
    //! 生成随机的格子
    void generateRandomTile();
    void generateRandomTileDouble();
    std::vector<int> Tiles;
    int score;
};

#endif // BOARD_H
