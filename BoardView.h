#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include <QWidget>
#include <vector>
#include "mytile.h"
#include <QGridLayout>
#include "game.h"
#include "observer.h"

class Game;
class Board;

class BoardView : public QWidget,public Observer
{
    Q_OBJECT
static const int TileNum = 16;
public:
    explicit BoardView(QWidget *parent = 0);
    myTile* getMyTile(int num);
    myTile* getMyTile(int row, int col);
    void updateUI();
    ~BoardView();
protected:
    void keyPressEvent(QKeyEvent *event);
private:
    Board* myBoard;
    Game* myGame;
    std::vector<myTile *> boardTiles;
    QGridLayout* boardLayout;
};

#endif // BOARDVIEW_H
