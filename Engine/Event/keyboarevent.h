#ifndef KEYBOAREVENT_H
#define KEYBOAREVENT_H
#include "event.h"

class KeyboarEvent:public Event{
        KeyboarEvent();
    public:
        static KeyboarEvent* create(byte k = 0);
        static uint ID(){
            return s_ID;
        }
        static void init();
        static void uinit();

        byte key() const{
            return m_key;
        }
        void setKey(const byte &key){
            m_key = key;
        }
        bool up() const{
            return m_up;
        }
        void setUp(bool up){
            m_up = up;
        }

    private:
        static uint s_ID;
        byte m_key;
        bool m_up;
};
class KeyboarSpecialEvent:public Event{
        KeyboarSpecialEvent();
    public:
        static KeyboarSpecialEvent* create(uint k);
        static uint ID(){
            return s_ID;
        }
        uint key() const{
            return m_key;
        }
        void setKey(const uint &key){
            m_key = key;
        }

        static void init();
        static void uinit();

        bool up() const{
            return m_up;
        }
        void setUp(bool up){
            m_up = up;
        }

private:
        static uint s_ID;
        uint m_key;
        bool m_up;
};

#endif // KEYBOAREVENT_H
