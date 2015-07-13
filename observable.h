#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include <vector>
class Observer;
class Observable
{
public:
    Observable();
    void detachObserver(Observer *);
    void attachObserver(Observer *observer);
    void notifyObservers();
private:
    std::vector<Observer*> observers;
};

#endif // OBSERVABLE_H
