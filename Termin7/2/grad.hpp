#ifndef GRAD_INCLUDE
#define GRAD_INCLUDE

#include "prodavnica.hpp"

class Grad {

private:
    DinString naziv;
    List<Prodavnica*> listaProdavnica;

public:
    Grad() : naziv("") {
        listaProdavnica.clear();
    }
    Grad(DinString naziv) : naziv(naziv) {
        listaProdavnica.clear();
    }

    bool dodajProdavnicu(Prodavnica* prodavnica) {
        listaProdavnica.add(listaProdavnica.size() + 1, prodavnica);
    }

    void ispisiSveProdavnice() {
        Prodavnica* temp;

        for(int i = 1; i <= listaProdavnica.size(); i++) {
            listaProdavnica.read(i, temp);

            cout << *temp;
        }
    }

    void ispisiNajjeftinijuProdavnicu() {
        if(listaProdavnica.empty()) {
            cout << "Lista prodavnica je prazna debilu." << endl;
            return;
        } else {
            Prodavnica* temp;
            Prodavnica* najjeftinijaProdavnica;
            double najveceMax = INT_MAX;

            for(int i = 1; i <= listaProdavnica.size(); i++) {
                listaProdavnica.read(i, temp);

                List<Proizvod*> listaProizvoda = temp->getListaProizvoda();
                Proizvod* temp2;

                int prosecnaCena = 0;
                int brojac54 = 0;

                for(int j = 1; j <= listaProizvoda.size(); j++) {
                    listaProizvoda.read(j, temp2);

                    cout << temp2->getNaziv() << endl;

                    prosecnaCena += temp2->getCena();
                    brojac54++;

                    cout << prosecnaCena << endl;
                }

                double trenutnaMax = prosecnaCena / brojac54;
                cout << "TRENUTNA MAX " << trenutnaMax << endl;
                if(trenutnaMax <= najveceMax) {
                    najjeftinijaProdavnica = temp;
                    najveceMax = trenutnaMax;
                }

                cout << *najjeftinijaProdavnica;
            }
        }
    }

};

#endif