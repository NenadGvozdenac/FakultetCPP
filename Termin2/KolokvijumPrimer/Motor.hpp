#ifndef MOTOR_HPP_INCLUDED
#define MOTOR_HPP_INCLUDED

class Motor {

private:
    int brzina;

public:
    Motor() {
        this->brzina = 0;
    }

    int getBrzina() const {
        return this->brzina;
    }

    void setBrzina(int br) {

        if(br < 0 || br > 5) {
            return;
        }

        this->brzina = br;
    }

};

#endif