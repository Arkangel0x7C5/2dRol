#ifndef EVENT_H
#define EVENT_H
#include "engine_global.h"
#include <service.h>
#include <queue>
#include <set>
#include <map>
#include <list>

class Event{
    public:
        Event();
        virtual ~Event(){}
        uint typeID;
        void* sender;
};
class eventListener{
    public:
        virtual void onEvent(Event* e) = 0;
};
class EventManager:public Service{
        EventManager();
    public:
        static EventManager& instance();
        virtual void run();

        uint registerEvent();
        void unregisterEvent(uint id);

        void suscribEvent(uint eventID,eventListener* listener);
        void unSuscribEvent();

        void sendEvent(Event* e);

    private:
        std::queue<Event*> m_queue;
        std::set<uint> m_eventIDs;
        std::map<uint,std::list<eventListener*> > m_listeners;
        uint m_lastID;
};

#endif // EVENT_H
