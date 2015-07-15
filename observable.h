#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include <vector>
#include <QObject>
class Observer;
class Observable: public QObject
{
    Q_OBJECT
public:
    Observable();
    void detachObserver(Observer *observer);
    void attachObserver(Observer *observer);
    void notifyObservers();
    void notifyObservers(QString);
private:
    std::vector<Observer*> observers;
};

#endif // OBSERVABLE_H
