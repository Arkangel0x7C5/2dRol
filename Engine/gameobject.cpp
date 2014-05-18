#include "gameobject.h"

GameObject::GameObject(){
    m_pos.setName("position");
    m_direction.setName("direction");
    m_size.setName("size");

    propiedades.add(&m_pos);
    propiedades.add(&m_direction);
    propiedades.add(&m_size);
}

drawable *GameObject::getDrawable(){
    return nullptr;
}

Rect2D GameObject::boundBox(){
    Rect2D r = {m_pos.value().x_const()
                ,m_pos.value().y_const()
                ,m_size.value().w_const()
                ,m_size.value().h_const()};

    return r;
}
externAnimation *GameObject::animation(){
    return nullptr;
}
