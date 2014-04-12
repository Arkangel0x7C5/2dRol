#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "drawable.h"
struct QuadTreeNode;

class GameObject{
    public:
        GameObject();
        virtual drawable* getDrawable();
        virtual Rect2D boundBox();
        virtual void onMove(QuadTreeNode* node);
};

#endif // GAMEOBJECT_H
