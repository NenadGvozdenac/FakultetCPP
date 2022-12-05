#ifndef PRODAVNICA_INCLUDE
#define PRODAVNICA_INCLUDE

#include "voce.hpp"
#include "odeca.hpp"

class Prodavnica {

private:
    DinString naziv;
    List<Proizvod*> listaProizvoda;

public:
    Prodavnica(const DinString& naziv) : naziv(naziv) {}

    bool dodajProizvod(Proizvod* proizvod) {

        if(listaProizvoda.empty()) {
            listaProizvoda.add(1, proizvod);
            return true;
        } else {
            Proizvod* temp;

            for(int i = 1; i <= listaProizvoda.size(); i++) {
                listaProizvoda.read(i, temp);

                if(temp->getNaziv() == proizvod->getNaziv()) {
                    return false;
                }
            }

            listaProizvoda.add(listaProizvoda.size() + 1, proizvod);
            return true;
        }
    }

    bool obrisiProizvod(const DinString& naziv) {
        if(listaProizvoda.empty()) {
            return false;
        } else {
            Proizvod* temp;

            for(int i = 1; i <= listaProizvoda.size(); i++) {
                listaProizvoda.read(i, temp);

                if(temp->getNaziv() == naziv) {
                    listaProizvoda.remove(i);
                    return true;
                }
            }

            return false;
        }
    }

    bool obrisiProizvod(int index) {
        if(listaProizvoda.empty()) {
            return false;
        } else if(index > listaProizvoda.size()) {
            return false;
        } else if(index < 1) {
            return false;
        } else {
            listaProizvoda.remove(index);
            return true;
        }
    }

    bool akcija() {

        if(listaProizvoda.empty()) {
            return false;
        } else {
            Proizvod* temp;

            for(int i = 1; i <= listaProizvoda.size(); i++) {
                listaProizvoda.read(i, temp);
                temp->izracunajPopust();
            }

            return true;
        }
    }

    friend ostream& operator << (ostream& os, const Prodavnica& p) {

        os << "------------" << endl;
        os << p.naziv << endl;

        if(p.listaProizvoda.empty()) {
            os << "Prodavnica je prazna." << endl;
        } else {
            Proizvod* temp;

            for(int i = 1; i <= p.listaProizvoda.size(); i++) {
                p.listaProizvoda.read(i, temp);
                os << temp->getNaziv() << endl;
            }
        }

        os << "------------" << endl;
        return os;
    }

    List<Proizvod*> getListaProizvoda() {
        return this->listaProizvoda;
    }

};

#endif