#include "observable.h"
#include <iterator>
using namespace std;
Observable::Observable()
{
}

void Observable::attachObserver(Observer * observer)
{
    //! don't think a observer push into vector twice
    observers.push_back(observer);
}

void Observable::detachObserver(Observer * observer)
{
    observers.erase(observer);
}

void Observable::notifyObservers()
{
    for (vector<Observer*>::iterator i = observers.begin(); i != observers.end(); ++i)
        *i->update();
}
