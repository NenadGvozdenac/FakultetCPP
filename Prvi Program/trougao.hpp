#ifndef TROUGAO
#define TROUGAO

#include <cmath>

class Trougao {

private:
    float a, b, c;
    float obim, povrsina;

public:
    Trougao() {
        a = 0, b = 0, c = 0;
        obim = 0, povrsina = 0;

        this->izracunajObim();
        this->izracunajPovrsinu();
    }

    Trougao(float a, float b, float c) {
        this->a = a;
        this->b = b;
        this->c = c;
        
        this->izracunajObim();
        this->izracunajPovrsinu();
    }

    Trougao(Trougao& trougao) {
        a = trougao.getA();
        b = trougao.getB();
        c = trougao.getC();
        obim = trougao.getObim();
        povrsina = trougao.getPovrsina();
        
        this->izracunajObim();
        this->izracunajPovrsinu();
    }

    void setA(float a) {
        this->a = a;
    }

    void setB(float b) {
        this->b = b;
    }

    void setC(float c) {
        this->c = c;
    }

    float getA() {
        return a;
    }

    float getB() {
        return b;
    }

    float getC() {
        return c;
    }

    float getObim() {
        return obim;
    }

    float getPovrsina() {
        return povrsina;
    }

    void izracunajPovrsinu() {
        float s = (a + b + c) / 2;
        this->povrsina = sqrt(s*(s-a)*(s-b)*(s-c));
    }

    void izracunajObim() {
        this->obim = a + b + c;
    }
};

#endif