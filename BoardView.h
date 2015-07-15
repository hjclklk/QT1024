#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include <QWidget>
#include <vector>
#include "mytile.h"
#include <QGridLayout>
#include <QPushButton>
#include "observer.h"
#include "board.h"
class Board;

class BoardView : public QWidget,public Observer
{
    Q_OBJECT
static const int TileNum = 16;
public:
    explicit BoardView(QWidget *parent = 0);
    myTile* getMyTile(int num);
    myTile* getMyTile(int row, int col);
    void update();
    void update(QString message);
    ~BoardView();
protected:
    void keyPressEvent(QKeyEvent *event);
private slots:
    void resetView();
private:
    Board* myBoard;
    std::vector<myTile *> boardTiles;
    QLabel* scoreView;
    QPushButton* resetButton;
    QGridLayout* boardLayout;
    QHBoxLayout* scoreLayout;
    QVBoxLayout* mainLayout;
};

#endif // BOARDVIEW_H
