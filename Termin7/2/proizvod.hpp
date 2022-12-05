#ifndef PROIZVOD_INCLUDE
#define PROIZVOD_INCLUDE

#include "dinstring.cpp"
#include "list.hpp"

class Proizvod {

protected:
    int cena;
    DinString naziv;

public:
    Proizvod(int cena, const DinString& naziv) : cena(cena), naziv(naziv) {}
    Proizvod() : cena(0), naziv("") {}
    virtual void izracunajPopust() = 0;
    virtual void ispisi() {
        cout << "Cena:\t\t" << cena << endl << "Naziv:\t\t" << naziv << endl;
    }
    DinString getNaziv() const {
        return naziv;
    }
    int getCena() const {
        return cena;
    }
};

#endif