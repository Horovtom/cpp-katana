//
// Created by lactosis on 29.7.18.
//

#ifndef KATANA_TIMER_H
#define KATANA_TIMER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Timer {
public:
    //Initializes variables
    Timer();

    //The various clock actions
    void start();

    void stop();

    void pause();

    void unpause();

    //Gets the timer's time
    Uint32 getTicks();

    //Checks the status of the timer
    bool isStarted();

    bool isPaused();

private:
    //The clock time when the timer started
    Uint32 mStartTicks;

    //The ticks stored when the timer was paused
    Uint32 mPausedTicks;

    //The timer status
    bool mPaused;
    bool mStarted;
};


#endif //KATANA_TIMER_H
