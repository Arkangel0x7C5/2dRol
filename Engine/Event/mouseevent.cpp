#include "mouseevent.h"

uint MouseClickEvent::s_ID;
uint MouseMotionEvent::s_ID;

MouseClickEvent::MouseClickEvent()
{
}

void MouseClickEvent::init(){
     s_ID = EventManager::instance().registerEvent();
}

void MouseClickEvent::uinit(){

}






void MouseMotionEvent::init(){
    s_ID = EventManager::instance().registerEvent();
}
