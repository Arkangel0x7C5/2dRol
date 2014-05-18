#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "drawable.h"
#include "Interfaces/clonable.h"
#include "Interfaces/property.h"
#include "Interfaces/component.h"


struct QuadTreeNode;

class externAnimation;
class GameObject:public Clonable{
    public:
        GameObject();
        virtual drawable* getDrawable();
        virtual Rect2D boundBox();
        virtual externAnimation* animation();
        PropertySet propiedades;
    private:
        std::map<std::string,Component*> m_components;
        PropertyPoint m_pos;
        PropertyPoint m_direction;
        PropertySize m_size;
};

#endif // GAMEOBJECT_H
