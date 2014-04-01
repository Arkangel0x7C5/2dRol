#include "event.h"
#include <pthread.h>
#include <unistd.h>

Event::Event():typeID(0),sender(nullptr){
}


EventManager::EventManager():m_lastID(0){

}

EventManager &EventManager::instance(){
    static EventManager s_instance;
    return s_instance;
}

void EventManager::run(){
    while (runing()) {
        if(!m_queue.empty()){
            Event* e = m_queue.front();
            m_queue.pop();

            std::map<uint,std::list<eventListener*> >::iterator itMap = m_listeners.find(e->typeID);
            if(itMap != m_listeners.end()){
                std::list<eventListener*> list = (*itMap).second;
                for (std::list<eventListener*>::iterator itList = list.begin(); itList != list.end(); ++itList) {
                    (*itList)->onEvent(e);
                }
            }
            delete e;
        }else{
            usleep(10);
        }

    }
}

uint EventManager::registerEvent(){
    m_eventIDs.insert(++m_lastID);

    return m_lastID;
}

void EventManager::unregisterEvent(uint id){
    m_eventIDs.erase(id);
    m_listeners.erase(id);
}

void EventManager::sendEvent(Event *e){
    m_queue.push(e);
}

