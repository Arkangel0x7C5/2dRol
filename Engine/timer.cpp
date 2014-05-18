#include "timer.h"
#include <SDL/SDL.h>

Timer::Timer():id(0),m_interval(0){
    SDL_InitSubSystem(SDL_INIT_TIMER);
}

void Timer::start(){
    id = SDL_AddTimer(interval(),(SDL_NewTimerCallback)&timerCallback,this);
}

void Timer::stop(){
    SDL_RemoveTimer((SDL_TimerID)id);
    id = 0;
}

void Timer::setInterval(const uint &interval){
    m_interval = interval;
}

ulong Timer::timerCallback(ulong /*interval*/, void *param){
    if(param){
        Timer* t = (Timer*)param;
        t->tick();
        return t->interval();
    }
    return 0;
}

