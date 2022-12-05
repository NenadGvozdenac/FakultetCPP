#include "grad.hpp"

int Odeca::ukupanBrojObjekataVelikeOdece = ukupanBrojObjekataVelikeOdece + 1;

int main(int argn, char* argv[]) {

    Voce v1("Srbija", 30, 150, "Kondom"), v2("Srbija", 50, 15022, "Dildo"), v3("Kosovo", 69, 32875, "Albinjoni");

    v1.ispisi();
    v1.izracunajPopust();
    v1.ispisi();

    Odeca o1(10000, "Kurac XL", XL, PANTALONE), o2(420, "Severina", XS, MAJICA);
    o1.ispisi();
    o1.izracunajPopust();
    o1.ispisi();

    Prodavnica prodavnica("Kondom veliki TM"), p2("Discord Marketplace");

    prodavnica.dodajProizvod(&o1);
    cout << prodavnica;

    prodavnica.dodajProizvod(&v1);
    cout << prodavnica;

    prodavnica.dodajProizvod(&o1);
    cout << prodavnica;

    prodavnica.obrisiProizvod(1);
    cout << prodavnica;

    prodavnica.obrisiProizvod("Kurac XL");
    cout << prodavnica;

    prodavnica.obrisiProizvod("Kondom");
    cout << prodavnica;

    prodavnica.dodajProizvod(&o1);
    prodavnica.dodajProizvod(&v1);

    p2.dodajProizvod(&v2);
    p2.dodajProizvod(&v3);
    p2.dodajProizvod(&o2);

    cout << p2;
    cout << prodavnica;

    Grad gucciMane("Pancevo");
    gucciMane.dodajProdavnicu(&p2);
    gucciMane.dodajProdavnicu(&prodavnica);
    cout << "A{OPIKROPASO{PIK:ASOPIJK:RAWSOR{ASRPSR}ASOPR{}AO{P}R{OA}SR" << endl << endl;
    gucciMane.ispisiNajjeftinijuProdavnicu();

    return 0;
}