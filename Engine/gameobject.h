#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "drawable.h"

class GameObject{
    public:
        GameObject();
        virtual drawable* getDrawable();
};

#endif // GAMEOBJECT_H
