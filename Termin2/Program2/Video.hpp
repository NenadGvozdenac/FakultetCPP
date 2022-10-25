#ifndef VIDEO_HPP
#define VIDEO_HPP

enum VideoState {
    STOPPED, PAUSED, PLAYING
};

class Video {

private:
    VideoState state;
    int videoSpeed;
    int currentTime;

public:
    Video();
    Video(VideoState state, int videoSpeed, int currentTime);
    Video(Video& video);
    ~Video();

    bool increaseSpeed();
    bool decreaseSpeed();
    bool setCurrentTime(int);
    bool play();
    bool pause();
    bool stop();
    void watch(int);

    VideoState getVideoState() const;
    int getVideoSpeed() const;
    int getCurrentTime() const;
};

#endif