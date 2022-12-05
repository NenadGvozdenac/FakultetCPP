#ifndef CHECKBOX_INCLUDED
#define CHECKBOX_INCLUDED

#include "component.hpp"

class CheckBox : public Component {

private:
    bool pressed;
    static DinString typeName;
public:
    CheckBox() {
        X = 0;
        Y = 0;
        pressed = false;
    }

    CheckBox(int x, int y, bool f) {
        X = x;
        Y = y;
        pressed = f;
    }

    DinString getTypeName() const {
        return typeName;
    }

    void printComponent() {
        cout << getTypeName() << endl;
        Component::printComponent();
        cout << "Pressed: " << pressed << endl;
    }

    bool getPressed() const {
        return pressed;
    }

    void setPressed(bool p) {
        pressed = p;
    }

};

#endif