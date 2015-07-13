#ifndef MYTILE_H
#define MYTILE_H
#include <QLabel>

class BoardView;
class myTile
{
    static int Number;
public:
    myTile(QWidget* parent = 0);
    void setMyStyle(int i);
    friend class BoardView;
private:
    void  setInitail();
    QLabel* tile;
};

#endif // MYTILE_H
