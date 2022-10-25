#ifndef VIDEO_CPP
#define VIDEO_CPP

#include <iostream>
#include "Video.hpp"

Video::Video() {
    this->state = STOPPED;
    this->videoSpeed = 1;
    this->currentTime = 0;
}

Video::Video(VideoState state, int videoSpeed, int currentTime) {
    this->state = state;
    this->videoSpeed = videoSpeed;
    this->currentTime = currentTime;
}

Video::Video(Video& video) {
    this->state = video.state;
    this->videoSpeed = video.videoSpeed;
    this->currentTime = video.currentTime;
}

Video::~Video() {
    std::cout << "Object 'Video' deleted." << std::endl;
}

bool Video::increaseSpeed() {

    if(this->state != PAUSED && this->state != PLAYING) {
        return false;
    }

    if(this->videoSpeed + 1 == 4) {
        return false;
    } else {
        this->videoSpeed++;
        return true;
    }
}

bool Video::decreaseSpeed() {

    if(this->state != PAUSED && this->state != PLAYING) {
        return false;
    }

    if(this->videoSpeed - 1 == 0) {
        return false;
    } else {
        this->videoSpeed--;
        return true;
    }
}

bool Video::setCurrentTime(int time) {

    if(this->state != PAUSED && this->state != PLAYING) {
        return false;
    }

    if(time >= 80 || time < 0) {
        return false;
    } else {
        this->currentTime = time;
        return true;
    }
}

bool Video::play() {
    if(this->state != PAUSED && this->state != STOPPED) {
        return false;
    } else {
        this->state = PLAYING;
        return true;
    }
}

bool Video::pause() {
    if(this->state != PAUSED) {
        return false;
    } else {
        this->state = PAUSED;
        return true;
    }
}

bool Video::stop() {
    if(this->state != PAUSED && this->state != PLAYING) {
        return false;
    } else {
        this->state = STOPPED;
        return true;
    }
}

void Video::watch(int time) {

    if(this->state != PLAYING) {
        return;
    }

    if(!(this->videoSpeed * time + this->currentTime > 60)) {
        this->currentTime += videoSpeed * time;
    } else {
        this->state = STOPPED;
        this->videoSpeed = 1;
        this->currentTime = 0;
    }
}

VideoState Video::getVideoState() const {
    return this->state;
}

int Video::getVideoSpeed() const {
    return this->videoSpeed;
}

int Video::getCurrentTime() const {
    return this->currentTime;
}

void ispis(const Video& video) {
    std::cout << "Video. State: " << video.getVideoState() << ". Video Speed: " << video.getVideoSpeed() << ". Current Time: " << video.getCurrentTime() << "." << std::endl;
}

#endif