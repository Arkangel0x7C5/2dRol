#include "gameobject.h"

GameObject::GameObject(){}

drawable *GameObject::getDrawable(){
    return nullptr;
}

Rect2D GameObject::boundBox(){
    return Rect2D();
}

void GameObject::onMove(QuadTreeNode *node){

}
