#include "BoardView.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QKeyEvent>
#include <QMessageBox>
#include <QDebug>
BoardView::BoardView(QWidget *parent) :
    QWidget(parent)
{
    /**
      限制vector的个数为16个
      new QGridLayout(this) 加与不加的区别
      */

    /**
      Board
      */
    myBoard = new Board();
    myBoard->attachObserver(this); //! 注册观察者


    boardLayout = new QGridLayout;
    scoreLayout = new QHBoxLayout;
    mainLayout = new QVBoxLayout;

    resetButton = new QPushButton("reset");
    resetButton->setFocusPolicy(Qt::NoFocus);

    scoreView = new QLabel("Score:0");
    scoreView->setStyleSheet("QLabel{font-size:10px; \
                                     font-weight: bold;}");

    //! 设置布局 QGridLayout
    scoreLayout->addWidget(scoreView);
    scoreLayout->addWidget(resetButton);

    mainLayout->addLayout(boardLayout);
    mainLayout->addLayout(scoreLayout);

    this->setLayout(mainLayout);

    /**
      初始化棋盘
      */
    for (int i = 0; i < TileNum; i++){
        myTile *tmpTile;
        tmpTile = new myTile;
        boardTiles.push_back(tmpTile);
        boardLayout->addWidget(tmpTile->tile,i/4,i%4,1,1);
    }
    QObject::connect(this->resetButton,SIGNAL(clicked()),this,SLOT(resetView()));
    /**
      初始界面
      */
    update();
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
    case Qt::Key_Left: myBoard->move(Board::LEFT); break;
    case Qt::Key_Right: myBoard->move(Board::RIGHT); break;
    case Qt::Key_Up: myBoard->move(Board::UP); break;
    case Qt::Key_Down: myBoard->move(Board::DOWN); break;
    case Qt::Key_Space: resetView(); break;
//    default:;
    }
}

void BoardView::resetView()
{
    myBoard->reset();
}

void BoardView::update()
{
    for (int i = 0; i < TileNum; i++)
    {
        boardTiles[i]->setMyStyle(myBoard->Tiles[i]);
    }
    scoreView->setText("Score:"+QString::number(myBoard->getScore()));

}

void BoardView::update(QString message)
{
    int ret = QMessageBox::question(this,tr("GAME OVER"),
                                    tr("your score is %1.\nDo you want to reset?").arg(QString::number(myBoard->getScore())),
                                    QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes);
    if (ret == QMessageBox::Yes)
        resetView();
}

BoardView::~BoardView()
{
    for (int i = 0; i < TileNum; i++){
        delete boardTiles[i];
    }
}
