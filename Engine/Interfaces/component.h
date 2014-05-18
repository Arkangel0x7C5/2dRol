#ifndef COMPONENT_H
#define COMPONENT_H

#include <iostream>

class GameObject;
class Component{
    public:
        Component();
        GameObject *gameObject(){
            return m_gameObject;
        }
        void setGameObject(GameObject *gameObject);
        virtual const std::string& type() const = 0;

    private:
        GameObject* m_gameObject;
};

#endif // COMPONENT_H
