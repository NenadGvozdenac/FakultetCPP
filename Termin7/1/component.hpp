#ifndef COMPONENT_INCLUDED
#define COMPONENT_INCLUDED

#include "list.hpp"
#include "dinstring.hpp"
#include "dinstring.cpp"

class Component {

protected:
    double X, Y;

public:
    double getX() { return X; }
    double getY() { return Y; }

    virtual void printComponent() {
        cout << "X: " << X << endl << "Y: " << Y << endl;
    }

    virtual DinString getTypeName() const = 0;
};

#endif