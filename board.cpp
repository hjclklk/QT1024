#include "board.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <QDebug>

Board::Board(BoardView* view):
    gameView(view)
{
    srand((unsigned)time(NULL));
    init();
//    test = 2;
}

void Board::init()
{
    Tiles.resize(TileNum);
    for (int i = 0; i < TileNum; i++)
        Tiles.at(i) = 0;
    generateRandomTileDouble();
    //gameView->updateUI();
}

void Board::generateRandomTileDouble()
{
    generateRandomTile();
    generateRandomTile();
}

void Board::generateRandomTile()
{
    std::vector<int> randomList;
    for (int i = 0; i < TileNum; i++)
        if (Tiles.at(i) == 0)
        randomList.push_back(i);
    int size = randomList.size();
    if (size > 0){
        Tiles.at(randomList[rand() % size]) = 2;
    }
}


void Board::move(Direction direction)
{
    int i,j;
    bool moveOk = false; //! test move or not
    switch (direction)
    {
    case UP:
        for (i = 0; i < SideLength; i++)
            for (j = 0; j < SideLength; j++)
                moveOk |= moveUp(i,j);
        break;
    case DOWN:
        for (i = SideLength-1; i >= 0; i--)
            for (j = SideLength-1; j >= 0; j--)
                moveOk |= moveDown(i,j);
        break;
    case LEFT:
        for (i = 0; i < SideLength; i++)
            for (j = 0; j < SideLength; j++)
                moveOk |= moveLeft(i,j);
        break;
    case RIGHT:
        for (i = SideLength-1; i >= 0; i--)
            for (j = SideLength-1; j >= 0; j--)
                moveOk |= moveRight(i,j);
        break;
    }
    if (moveOk) {
        generateRandomTileDouble();
        gameView->updateUI();
    }
}

bool Board::moveUp(int row, int col)
{
    int ok = false;
    int num = row*4+col;
    if (Tiles.at(num) == 0)
        return false;
    while (row > 0){
        row--;
        int tempnum = row*4+col;
        if (Tiles[tempnum] == 0 || Tiles[tempnum] == Tiles[num]){
            Tiles[tempnum] += Tiles[num];
            Tiles[num] = 0;
            ok = true;
        }
        else
            return ok;
        num = tempnum;
    }
    return ok;
}

bool Board::moveDown(int row, int col)
{
    int ok = false;
    int num = row*4+col;
    if (Tiles.at(num) == 0)
        return false;
    while (row < SideLength - 1){
        row++;
        int tempnum = row*4+col;
        if (Tiles[tempnum] == 0 || Tiles[tempnum] == Tiles[num]){
            Tiles[tempnum] += Tiles[num];
            Tiles[num] = 0;
            ok = true;
        }
        else
            return ok;
        num = tempnum;
    }
    return ok;
}

bool Board::moveRight(int row, int col)
{
    int ok = false;
    int num = row*4+col;
    if (Tiles.at(num) == 0)
        return false;
    while (col < SideLength -1){
        col++;
        int tempnum = row*4+col;
        if (Tiles[tempnum] == 0 || Tiles[tempnum] == Tiles[num]){
            Tiles[tempnum] += Tiles[num];
            Tiles[num] = 0;
            ok = true;
        }
        else
            return ok;
        num = tempnum;
    }
    return ok;
}

bool Board::moveLeft(int row, int col)
{
    int ok = false;
    int num = row*4+col;
    if (Tiles.at(num) == 0)
        return false;
    while (col > 0){
        col--;
        int tempnum = row*4+col;
        if (Tiles[tempnum] == 0 || Tiles[tempnum] == Tiles[num]){
            Tiles[tempnum] += Tiles[num];
            Tiles[num] = 0;
            ok = true;
        }
        else
            return ok;
        num = tempnum;
    }
    return ok;
}
