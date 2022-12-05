#ifndef ODECA_INCLUDE
#define ODECA_INCLUDE

#include "voce.hpp"

enum VELICINA {XS, S, M, L, XL};
enum TIP {MAJICA, PANTALONE};

class Odeca : public Proizvod {

private:
    VELICINA velicina;
    TIP tip;
    static int ukupanBrojObjekataVelikeOdece;

public:
    Odeca(int cena, const DinString& naziv, VELICINA velicina, TIP tip) {
        this->cena = cena;
        this->naziv = naziv;
        this->velicina = velicina;
        this->tip = tip;

        if(velicina == L || velicina == XL) {
            ukupanBrojObjekataVelikeOdece++;
        }
    }

    void izracunajPopust() {
        if(velicina == XS && tip == MAJICA) {
            cena = 0.40 * cena;
        } else if(tip == MAJICA) {
            cena = 0.50 * cena;
        } else if(tip == PANTALONE) {
            cena = 0.66 * cena;
        }
    }

    DinString getVelicina() {
        switch(velicina) {
            case XS:
                return "XS";
            break;
            case S:
                return "S";
            break;
            case M:
                return "M";
            break;
            case L:
                return "L";
            break;
            default:
                return "XL";
        }
    }

    void ispisi() {
        cout << "\tOdeca\t" << endl << "Velicina:\t" << getVelicina() << endl << "Tip:\t\t" << (tip == MAJICA ? "Majica" : "Pantalone") << endl;
        Proizvod::ispisi();
    }

};

#endif