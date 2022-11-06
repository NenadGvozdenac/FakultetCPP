#ifndef BROD_HPP_INCLUDED
#define BROD_HPP_INCLUDED

#include "Motor.hpp"

enum StanjeBroda {
    USIDREN,
    PLOVI,
    POKVAREN
};

class Brod {

private:
    StanjeBroda stanjeBroda;
    Motor motor;
    int predjenoKilometara;
    int kolicinaGoriva;

public:
    Brod() : stanjeBroda(USIDREN), predjenoKilometara(0), kolicinaGoriva(0), motor() {}

    const char* getStanje() const {
        switch(stanjeBroda) {
            case USIDREN:
                return "USIDREN";
            break;

            case PLOVI:
                return "PLOVI";
            break;

            case POKVAREN:
                return "POKVAREN";
            break;

            default:
                return "NEDEFINISANO";
        }
    }

    int getPredjenoKilometara() const {
        return this->predjenoKilometara;
    }

    int getKolicinaGoriva() const {
        return this->kolicinaGoriva;
    }

    StanjeBroda getStanjeBroda() const {
        return this->stanjeBroda;
    }

    Motor getMotor() const {
        return this->motor;
    }

    bool pokvari() {
        if(stanjeBroda == USIDREN || stanjeBroda == PLOVI) {
            stanjeBroda = POKVAREN;
            kolicinaGoriva = 0;
            motor.setBrzina(0);
            return true;
        } else return false;
    }

    bool popravi() {
        if(stanjeBroda == POKVAREN) {
            stanjeBroda = USIDREN;
            motor.setBrzina(0);
            return true;
        } else return false;
    }

    bool pokreni() {
        if(stanjeBroda == USIDREN) {
            stanjeBroda = PLOVI;
            return true;
        } else return false;
    }

    bool zaustavi() {
        if(stanjeBroda == PLOVI) {
            stanjeBroda = USIDREN;
            motor.setBrzina(0);
            return true;
        } else return false;
    }

    bool sipajGorivo() {
        if(stanjeBroda == USIDREN) {
            if(kolicinaGoriva + 2 >= 15) {
                kolicinaGoriva = 15;
                return true;
            } else {
                kolicinaGoriva += 2;
                return true;
            }
        } else return false;
    }

    bool povecajBrzinu() {
        if(stanjeBroda == PLOVI) {

            if(motor.getBrzina() + 1 > 5) {
                return false;
            } 

            motor.setBrzina(motor.getBrzina() + 1);
            return true;
        } else return false;
    }

    bool smanjiBrzinu() {
        if(stanjeBroda == PLOVI) {

            if(motor.getBrzina() - 1 < 0) {
                return false;
            }

            motor.setBrzina(motor.getBrzina() - 1);
            return true;
        } else return false;
    }

    bool putuj() {
        if(stanjeBroda == PLOVI) {
            if(kolicinaGoriva - 1 < 0) {
                return false;
            } else {
                kolicinaGoriva--;
                predjenoKilometara += 5 * motor.getBrzina();
                return true;
            }
        } else return false;
    }

};

#endif