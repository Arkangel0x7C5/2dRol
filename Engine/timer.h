#ifndef TIMER_H
#define TIMER_H

#include "engine_global.h"

class Timer{
    public:
        Timer();
        void start();
        void stop();

        uint interval() const{
            return m_interval;
        }
        void setInterval(const uint &interval);
        virtual void tick() = 0;

    private:
        static ulong timerCallback(ulong interval, void *param);
        void* id;
        uint m_interval;
};

#endif // TIMER_H
