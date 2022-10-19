#ifndef PRAVOUGAONIK
#define PRAVOUGAONIK

#include <cmath>

class Pravougaonik {

private:
    float a, b;
    float obim, povrsina;

public:
    Pravougaonik() {
        a = 0, b = 0;
        obim = 0, povrsina = 0;

        this->izracunajObim();
        this->izracunajPovrsinu();
    }

    Pravougaonik(float a, float b) {
        this->a = a;
        this->b = b;

        this->izracunajObim();
        this->izracunajPovrsinu();
    }

    Pravougaonik(Pravougaonik& Pravougaonik) {
        a = Pravougaonik.getA();
        b = Pravougaonik.getB();
        obim = Pravougaonik.getObim();
        povrsina = Pravougaonik.getPovrsina();

        this->izracunajObim();
        this->izracunajPovrsinu();
    }

    void setA(float a) {
        this-> a = a;
    }

    void setB(float b) {
        this->b = b;
    }

    float getA() {
        return a;
    }

    float getB() {
        return b;
    }

    float getObim() {
        return obim;
    }

    float getPovrsina() {
        return povrsina;
    }

    void izracunajPovrsinu() {
        this->povrsina = a * b;
    }

    void izracunajObim() {
        this->obim = a + b + a + b;
    }
};

#endif