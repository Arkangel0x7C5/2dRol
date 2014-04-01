#include "keyboarevent.h"
#include "event.h"

uint KeyboarEvent::s_ID;
KeyboarEvent::KeyboarEvent():m_key(0),m_up(false){
    typeID = s_ID;
}

KeyboarEvent *KeyboarEvent::create(byte k){
    KeyboarEvent* e = new KeyboarEvent();
    e->setKey(k);

    return e;
}

void KeyboarEvent::init(){
    s_ID = EventManager::instance().registerEvent();
}

void KeyboarEvent::uinit(){

}







uint KeyboarSpecialEvent::s_ID;
KeyboarSpecialEvent::KeyboarSpecialEvent():m_key(0),m_up(false){
    typeID = s_ID;
}

KeyboarSpecialEvent *KeyboarSpecialEvent::create(uint k){
    KeyboarSpecialEvent* e = new KeyboarSpecialEvent();
    e->setKey(k);

    return e;
}

void KeyboarSpecialEvent::init(){
    s_ID = EventManager::instance().registerEvent();
}

void KeyboarSpecialEvent::uinit(){

}








