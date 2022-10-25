#include <iostream>
#include <cmath>
#include "polinom.hpp"

int main(int argn, char* argv[]) {

    Polinom* p = new Polinom();
    p->setKoeficijenti(new double[20]{1, 2, 3, 4, 5});
    p->setRed(5);

    std::cout << *p;

    return 0;
}