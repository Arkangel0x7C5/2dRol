#ifndef MOUSEEVENT_H
#define MOUSEEVENT_H

#include "event.h"

class MouseClickEvent:public Event{
        MouseClickEvent();
    public:
        static MouseClickEvent* create(byte k = 0);
        static uint ID(){
            return s_ID;
        }
        static void init();
        static void uinit();

        Point p() const{
            return m_p;
        }
        void setP(const Point &p){
            m_p = p;
        }

    private:
        Point m_p;
        static uint s_ID;
};
class MouseMotionEvent:public Event{
        MouseMotionEvent();
    public:
        static MouseClickEvent* create(byte k = 0);
        static uint ID(){
            return s_ID;
        }
        static void init();
        static void uinit();
    private:
        static uint s_ID;
};

#endif // MOUSEEVENT_H
