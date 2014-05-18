#ifndef ANIMATION_H
#define ANIMATION_H

#include "timer.h"
#include <set>

class Animation{
    public:
        Animation();
        virtual ~Animation();
        virtual void tick() = 0;
        virtual void restart();
        virtual bool pause();
        virtual void setPause(bool value);
        //retardo entre cambios de frame, en segundos
        virtual void setDelay(float d);
};
//Hereda de timer
class AnimationManager:public Timer{
    public:
        AnimationManager();
        virtual void tick() override;
        void restart();

        void addAnimation(Animation* a);
        void removeAnimation(Animation* a);
    private:
        std::set<Animation*> m_animations;
};

#endif // ANIMATION_H
