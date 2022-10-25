#include "Video.hpp"
#include "Video.cpp"

int main(int argn, char* argv[]) {

    Video* video1 = new Video();
    Video* video2 = new Video(STOPPED, 1, 0);
    Video* video3 = new Video(*video2);

    video1->increaseSpeed();
    ispis(*video1);
    video1->decreaseSpeed();
    ispis(*video1);
    video1->setCurrentTime(50);
    ispis(*video1);
    video1->setCurrentTime(150);
    ispis(*video1);
    video1->play();
    ispis(*video1);
    video1->stop();
    ispis(*video1);
    video1->watch(50);
    ispis(*video1);

    delete video1, delete video2, delete video3;

    return 0;
}