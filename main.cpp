#include "BoardView.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BoardView w;
    w.show();
    w.resize(600,480);
    return a.exec();
}
