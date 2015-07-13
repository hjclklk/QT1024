#include "BoardView.h"
#include <QKeyEvent>
#include <QDebug>
BoardView::BoardView(QWidget *parent) :
    QWidget(parent)
{
    /**
      限制vector的个数为16个
      new QGridLayout(this) 加与不加的区别
      */

    /**
      Game
      Board
      */
    myGame = new Game(this);
    myBoard = myGame->getBoard();

    //! 设置布局 QGridLayout
    boardLayout = new QGridLayout;
    this->setLayout(boardLayout);

    /**
      初始化棋盘
      */
    for (int i = 0; i < TileNum; i++){
        myTile *tmpTile;
        tmpTile = new myTile;
        boardTiles.push_back(tmpTile);
        boardLayout->addWidget(tmpTile->tile,i/4,i%4,1,1);
    }
    /**
      */
    updateUI();
}

myTile* BoardView::getMyTile(int row, int col)
{
    return boardTiles.at(row*4+col);
}

myTile* BoardView::getMyTile(int num)
{
    return boardTiles.at(num);
}

void BoardView::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()){
    case Qt::Key_Left: myGame->move(Board::LEFT); break;
    case Qt::Key_Right: myGame->move(Board::RIGHT); break;
    case Qt::Key_Up: myGame->move(Board::UP); break;
    case Qt::Key_Down: myGame->move(Board::DOWN); break;
//    default:;
    }
}

void BoardView::updateUI()
{
    qDebug() << myBoard;
    for (int i = 0; i < TileNum; i++)
    {
        qDebug() << myBoard->Tiles[i];
        boardTiles[i]->setMyStyle(myBoard->Tiles[i]);
    }
}

BoardView::~BoardView()
{
    for (int i = 0; i < TileNum; i++){
        delete boardTiles[i];
    }
}
