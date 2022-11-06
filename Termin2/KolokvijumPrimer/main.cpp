#include <iostream>
#include "Motor.hpp"
#include "Brod.hpp"

void ispisiMotor(const Motor& motor) {

    std::cout << "--- Motor ---" << std::endl;
    std::cout << "Brzina: " << motor.getBrzina() << std::endl << std::endl;
}

void ispisiBrod(const Brod& brod) {

    std::cout << "--- Brod ---" << std::endl;
    std::cout << "Stanje: " << brod.getStanje() << std::endl;
    std::cout << "Predjeno kilometara: " << brod.getPredjenoKilometara() << std::endl;
    std::cout << "Kolicina goriva: " << brod.getKolicinaGoriva() << std::endl;
    ispisiMotor(brod.getMotor());
}

int main(int argn, char* argv[]) {

    Motor m;            // Deklaracija motor (prazan konstruktor)
    ispisiMotor(m);     // Zvanje ispis funkcije motor, sadrzi get metodu za brzinu
    m.setBrzina(4);     // Postavljanje brzine na okej vrednost
    ispisiMotor(m);     // Zvanje ispis funkcije motor
    m.setBrzina(69);    // Postavljanje brzine na losu vrednost
    ispisiMotor(m);     // Zvanje ispis funkcije motor 

    Brod brod;          // Deklaracija brod (prazan konstruktor)
    ispisiBrod(brod);   // Zvanje ispis funkcije brod
    brod.sipajGorivo(); // Metoda sipajGorivo()
    brod.sipajGorivo(); // Metoda sipajGorivo()
    brod.sipajGorivo(); // Metoda sipajGorivo()
    ispisiBrod(brod);   // Zvanje ispis funkcije brod
    brod.pokreni();     // Metoda pokreni
    ispisiBrod(brod);   // Zvanje ispis funkcije brod
    brod.putuj();       // Metoda putuj
    ispisiBrod(brod);   // Ispisi brod
    brod.povecajBrzinu();   // Povecaj brzinu metoda
    brod.povecajBrzinu();   // Povecaj brzinu metoda
    brod.povecajBrzinu();   // Povecaj brzinu metoda
    ispisiBrod(brod);   // Ispisi brod
    brod.smanjiBrzinu();    // Smanji brzinu metoda
    ispisiBrod(brod);   // Ispisi motor
    brod.putuj();       // Putuj metoda
    brod.putuj();       // Putuj metoda
    ispisiBrod(brod);   // Ispisi brod
    brod.pokvari();     // Pokvari metoda
    ispisiBrod(brod);   // Ispisi brod
    brod.pokreni();     // Pokreni metoda
    ispisiBrod(brod);   // Ispisi brod
    brod.popravi();     // Popravi metoda
    ispisiBrod(brod);   // Ispisi brod
    brod.pokvari();     // Pokvari metoda
    ispisiBrod(brod);   // Ispisi brod
    brod.popravi();     // Popravi metoda
    brod.sipajGorivo(); // Sipaj gorivo
    brod.sipajGorivo(); // Sipaj gorivo
    brod.pokreni();     // Pokreni brod
    ispisiBrod(brod);   // Ispisi brod
    brod.zaustavi();    // Zaustavi brod
    ispisiBrod(brod);   // Ispisi brod

    return 0;
}