#ifndef OBSERVER_H
#define OBSERVER_H
#include <QString>
class Observer
{
public:
    Observer();
    virtual void update() = 0;
    virtual void update(QString) = 0;
};

#endif // OBSERVER_H
