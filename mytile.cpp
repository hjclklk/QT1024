#include "mytile.h"
#include <QDebug>
int myTile::Number = 0;

myTile::myTile(QWidget* parent)
{
    tile = new QLabel;
    Number++;
    setInitail();
}

void myTile::setInitail()
{
    tile->setAlignment(Qt::AlignCenter);
    tile->setText(QString::number(Number));
    //tile->setMinimumSize(50,50);
    tile->setStyleSheet("QLabel{ background:rgb(150,150,150); \
                                 font-size:40px; \
                                 border-radius: 10px; \
                                 font-weight:bold; }");
}

void myTile::setMyStyle(int i)
{
    /**
      base style
      */
    tile->setText(QString::number(i));
    tile->setStyleSheet("QLabel{ background:rgb(204,192,179); \
                                 font-size:40px; \
                                 border-radius: 10px; \
                                 font-weight:bold; }");
    switch (i)
    {
    case 0:
        tile->clear();
        break;
    case 2:
        tile->setStyleSheet("QLabel{ background:rgb(238,228,218); \
                                     font-size:40px; \
                                     border-radius: 10px; \
                                     font-weight:bold; }");
        break;
    case 4:
        tile->setStyleSheet("QLabel{ background:rgb(237,224,200); \
                                     font-size:40px; \
                                     border-radius: 10px; \
                                     font-weight:bold; }");
        break;
    case 8:
        tile->setStyleSheet("QLabel{ background:rgb(242,177,121); \
                                      font-size:40px; \
                                      border-radius: 10px; \
                                      font-weight:bold; }");
    case 16:
        tile->setStyleSheet("QLabel{ background:rgb(245,150,100); \
                                      font-size:40px; \
                                      border-radius: 10px; \
                                      font-weight:bold; }");
        break;
    case 32:
        tile->setStyleSheet("QLabel{ background:rgb(245,125,95); \
                                   font-size:40px; \
                                   border-radius: 10px; \
                                   font-weight:bold; }");
        break;
    case 64:
        tile->setStyleSheet("QLabel{ background:rgb(245,95,60); \
                                   font-size:40px; \
                                   border-radius: 10px; \
                                   font-weight:bold; }");
        break;
    case 128:
        tile->setStyleSheet("QLabel{ background:rgb(237,207,114); \
                                    font-size:40px; \
                                    border-radius: 10px; \
                                    font-weight:bold; }");
        break;
    case 256:
        tile->setStyleSheet("QLabel{ background:rgb(237,204,97); \
                                    font-size:40px; \
                                    border-radius: 10px; \
                                    font-weight:bold; }");
        break;
    default:
        tile->setStyleSheet("QLabel{ background:rgb(237,204,97); \
                                    font-size:40px; \
                                    border-radius: 10px; \
                                    font-weight:bold; }");
        break;
    }
}
