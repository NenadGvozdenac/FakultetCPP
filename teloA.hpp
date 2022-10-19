#ifndef TELOA
#define TELOA

#include "trougao.hpp"
#include "pravougaonik.hpp"

class TeloA {
    
private:
    Trougao trougao;
    Pravougaonik pravougaonik;

    float duzina;
    float povrsina, zapremina;

public:
    TeloA() {
        povrsina = 0;
        zapremina = 0;

        this->izracunajPovrsinu();
        this->izracunajZapreminu();
    }

    TeloA(Trougao t, Pravougaonik p, float d) {
        this->trougao = t;
        this->pravougaonik = p;
        this->duzina = d;

        this->izracunajPovrsinu();
        this->izracunajZapreminu();
    }

    TeloA(TeloA& teloA) {
        this->trougao = teloA.getTrougao();
        this->pravougaonik = teloA.getPravougaonik();
        this->duzina = teloA.getDuzina();

        this->povrsina = teloA.getPovrsina();
        this->zapremina = teloA.getZapremina();

        this->izracunajPovrsinu();
        this->izracunajZapreminu();
    }

    Trougao getTrougao() {
        return this->trougao;
    }

    Pravougaonik getPravougaonik() {
        return this->pravougaonik;
    }

    float getDuzina() {
        return this->duzina;
    }

    void setTrougao(Trougao t) {
        this->trougao = t;
    }

    void setPravougaonik(Pravougaonik p) {
        this->pravougaonik = p;
    }

    void setDuzina(float duzina) {
        this->duzina = duzina;
    }

    float getPovrsina() {
        return this->povrsina;
    }

    float getZapremina() {
        return this->zapremina;
    }

    void izracunajPovrsinu() {
        povrsina = 2 * pravougaonik.getPovrsina() + 2 * trougao.getPovrsina() + duzina * pravougaonik.getB() * 2 + trougao.getC() * duzina + trougao.getB() * duzina;
    }

    void izracunajZapreminu() {
        zapremina = pravougaonik.getPovrsina() * duzina + trougao.getPovrsina() * duzina;
    }
};

#endif