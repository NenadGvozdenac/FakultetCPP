#ifndef POLINOM
#define POLINOM

#include <cmath>
#include <iostream>

class Polinom {

private:
    double* a = new double[20]; // koef
    int n;

public:
    Polinom() {
        n = 0;
    }

    Polinom(double niz[], int n) {
        a = niz;
        this->n = n;
    }

    Polinom(Polinom& polinom) {

        for(int i = 0; i < 20; i++) {
            (this->a)[i] = polinom.a[i];
        }

        this->n = polinom.getRed();
    }

    double* getKoeficijenti() {
        return this->a;
    }

    int getRed() {
        return this->n;
    }

    void setKoeficijenti(double* niz) {
        for(int i = 0; i < 20; i++) {
            (this->a)[i] = niz[i];
        }
    }
    
    void setRed(int n) {
        this->n = n;
    }

    ~Polinom() {
        delete a;
    }

    void unesiPolinom() {

        int brojac = 0, polinom = 0;

        do {
            std::cout << "Unesite " << brojac << ": ";
            std::cin >> polinom;

            brojac++;
            this->a[brojac] = polinom;

        } while(polinom != 0 && brojac != 20);

        this->n = brojac;
    }

    Polinom operator + (Polinom& polinom) {

        Polinom* p = new Polinom();

        double niz[20];

        for(int i = 0; i < 20; i++) {
            niz[i] = this->a[i] + polinom.getKoeficijenti()[i];
        }

        p->setRed(this->n > polinom.n ? this->n : polinom.n); 
        p->setKoeficijenti(niz);

        return *p;
    }

    Polinom operator += (Polinom& polinom) {

        for(int i = 0; i < 20; i++) {
            this->a[i] = this->a[i] + polinom.getKoeficijenti()[i];
        }

        this->setRed(this->n > polinom.n ? this->n : polinom.n); 
        
        return *this;
    }

    Polinom operator - (Polinom& polinom) {

        Polinom* p = new Polinom();

        double niz[20];

        for(int i = 0; i < 20; i++) {
            niz[i] = this->a[i] - polinom.getKoeficijenti()[i];
        }

        for(int i = 20; i >= 0; i--) {
            if(niz[i] != 0) {
                p->setRed(i);
                break;
            }
        }

        p->setKoeficijenti(niz);

        return *p;
    }

    Polinom operator -= (Polinom& polinom) {

        for(int i = 0; i < 20; i++) {
            this->a[i] = this->a[i] - polinom.getKoeficijenti()[i];
        }

        for(int i = 20; i >= 0; i--) {
            if(this->a[i] != 0) {
                this->setRed(i);
            }
        }

        return *this;
    }

    void operator = (Polinom& polinom) {

        for(int i = 0; i < 20; i++) {
            this->a[i] = polinom.getKoeficijenti()[i];
        }

        this->n = polinom.getRed();
    }

    bool operator == (Polinom& polinom) {

        if(this->n != polinom.getRed()) return false;

        for(int i = 0; i < 20; i++) {
            if(polinom.getKoeficijenti()[i] != this->getKoeficijenti()[i]) {
                return false;
            }
        }

        return true;
    }

    bool operator != (Polinom& polinom) {

        if(this->n != polinom.getRed()) return true;

        for(int i = 0; i < 20; i++) {
            if(polinom.getKoeficijenti()[i] != this->getKoeficijenti()[i]) {
                return true;
            }
        }

        return false;
    }

    friend std::ostream& operator << (std::ostream& os, Polinom& polinom) {
        os << "Polinom " << polinom.getRed() << " reda: ";
        for(int i = 0; i < 20; i++) {

            if(polinom.getKoeficijenti()[i] == 0) {
                break;
            }

            os << polinom.getKoeficijenti()[i] << "x^" << i << " ";
        }

        return os;
    }
};

#endif