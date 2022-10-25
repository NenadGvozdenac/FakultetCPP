#ifndef MACHINE_HPP
#define MACHINE_HPP

#include <iostream>

enum MachineState {
    sA, sB, sC, sD
};

class Machine {

private:
    int value;
    MachineState currentState;

public:
    Machine() {
        value = 80, currentState = sC;
    }

    bool metodaX() {
        if(currentState != sC && currentState != sB) {
            return false;
        }

        currentState = sA;
        return true;
    }

    bool metodaY() {
        if(currentState != sB && currentState != sD) {
            return false;
        }

        currentState = sC;
        value = 80;
        return true;
    }

    bool metodaZ() {
        if(currentState != sA) {
            return false;
        }

        currentState = sB;
        value = 0;
        return true;
    }

    bool metodaW() {
        if(currentState != sA) {
            return false;
        }

        value = 0;
        currentState = sD;

        return true;
    }

    bool plus() {
        if(currentState != sA) {
            return false;
        }

        if(value + 20 <= 80) {
            value+=20;
            return true;
        } else {
            return false;
        }
    }

    bool minus() {
        if(currentState != sA) {
            return false;
        }

        if(value - 20 >= 0) {
            value-=20;
            return true;
        } else {
            return false;
        }
    }

    MachineState getCurrentState() const {
        return this->currentState;
    }

    int getValue() const {
        return this->value;
    }
};

    void printInfo(const Machine& machine) {
        std::cout << "Machine: " << machine.getCurrentState() << " state. Value: " << machine.getValue() << ".";
    }

    int meni() {

        int unos;
        Machine* machine;

        do {
            std::cout << "Unesite sta zelite da radite: \n";
            std::cout << "1. Pokreni masinu\n";
            std::cout << "2. Metoda X\n";
            std::cout << "3. Metoda Y\n";
            std::cout << "4. Metoda Z\n";
            std::cout << "5. Metoda W\n";
            std::cout << "6. Saberi\n";
            std::cout << "7. Oduzmi\n";
            std::cout << "8. Info\n";

            std::cout << "0. Izlaz\n\nUnos: ";
            std::cin >> unos;

            switch(unos) {
                case 1:
                    machine = new Machine();
                break;

                case 2:
                    machine->metodaX();
                break;

                case 3:
                    machine->metodaY();
                break;

                case 4:
                    machine->metodaZ();
                break;

                case 5:
                    machine->metodaW();
                break;

                case 6:
                    machine->plus();
                break;

                case 7:
                    machine->minus();
                break;

                case 8:
                    printInfo(*machine);
                break;

                case 0:
                    std::cout << "Izlaz...";
                break;
            }
        } while(unos != 0);
    
        return unos;
    }

#endif