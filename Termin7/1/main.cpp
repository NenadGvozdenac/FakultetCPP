#include "CheckBox.hpp"
#include "label.hpp"

DinString CheckBox::typeName = "CheckBox";
DinString Label::typeName = "Label";

int main() {

    CheckBox c1, c2(2, 3, true);

    c1.printComponent();
    c2.printComponent();

    Label l, l1(2, 3, "Text neki idk");

    l.printComponent();
    l1.printComponent();

    return 0;
}