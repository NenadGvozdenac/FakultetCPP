#include <iostream>
#include <cmath>
#include "trougao.hpp"
#include "pravougaonik.hpp"
#include "teloA.hpp"

int main(int argn, char* argv[]) {

    float a, b, c, d, h, ivica;

    std::cout << "Unesite a: ";
    std::cin >> a;

    std::cout << "Unesite b: ";
    std::cin >> b;

    std::cout << "Unesite c: ";
    std::cin >> c;

    std::cout << "Unesite d: ";
    std::cin >> d;

    std::cout << "Unesite h: ";
    std::cin >> h;

    Trougao* trougao = new Trougao(a, b, c);

    Pravougaonik* pravougaonik = new Pravougaonik(a, h);

    std::cout << "Trougao ima povrsinu: " << trougao->getPovrsina() << ". Trougao ima obim: " << trougao->getObim() << std::endl;
    std::cout << "Pravougaonik ima povrsinu: " << pravougaonik->getPovrsina() << ". Pravougaonik ima obim: " << pravougaonik->getObim() << std::endl; 

    TeloA* teloA = new TeloA(*trougao, *pravougaonik, d);

    std::cout << "Telo A ima povrsinu: " << teloA->getPovrsina() << ". Telo A ima zapreminu: " << teloA->getZapremina() << std::endl;

    std::cout << "Unesite ivicu koja treba biti ista: ";
    std::cin >> ivica;

    Trougao* trougaoIsteIvice = new Trougao(ivica, ivica, ivica);
    Pravougaonik* pravougaonikIsteIvice = new Pravougaonik(ivica, ivica);

    TeloA* teloB = new TeloA(*trougaoIsteIvice, *pravougaonikIsteIvice, ivica);

    std::cout << "Telo B ima povrsinu: " << teloB->getPovrsina() << ". Telo A ima zapreminu: " << teloB->getZapremina() << std::endl;

    delete trougao;
    delete pravougaonik;
    delete teloA;
    delete teloB;
    
    return 0;
}