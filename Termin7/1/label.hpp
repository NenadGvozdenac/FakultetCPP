#ifndef LABEL_INCLUDED
#define LABEL_INCLUDED

#include "component.hpp"

class Label : public Component {

private:
    DinString text;
    static DinString typeName;

public:
    Label() {
        X = 0;
        Y = 0;
        text = "";
    }

    Label(int x, int y, DinString t) {
        X = x;
        Y = y;
        text = t;
    }

    DinString getTypeName() const {
        return typeName;
    }

    void printComponent() {
        cout << getTypeName() << endl;
        Component::printComponent();
        cout << "Text: " << text;
    }

    DinString getText() const {
        return text;
    }

    void setText(DinString s) {
        text = s;
    }
};

#endif