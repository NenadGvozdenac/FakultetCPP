#ifndef VOCE_INCLUDE
#define VOCE_INCLUDE

#include "proizvod.hpp"

class Voce : public Proizvod {

private:
    DinString zemljaPorekla;
    int rokTrajanja;

public:
    Voce(const DinString& zemljaPorekla, int rokTrajanja, int cena, const DinString& naziv) : zemljaPorekla(zemljaPorekla), rokTrajanja(rokTrajanja) {
        this->cena = cena;
        this->naziv = naziv;
    }

    void izracunajPopust() {
        if(rokTrajanja > 5) { 
            cena = 0.66 * cena;
        } else if(rokTrajanja > 1 && rokTrajanja < 5) {
            cena = 0.33 * cena;
        } else if(rokTrajanja == 0) {
            cena = 0;
        }
    }

    void ispisi() {
        cout << "\tVoce\t" << endl << "Zemlja Porekla:\t" << zemljaPorekla << endl << "Rok Trajanja:\t" << rokTrajanja << endl;
        Proizvod::ispisi();
    }

};

#endif