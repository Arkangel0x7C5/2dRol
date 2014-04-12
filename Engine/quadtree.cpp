#include "quadtree.h"
#include <cstring>
#include <cstdlib>


QuadTreeNode::QuadTreeNode(const Rect2D &r){
    memset(child,0,sizeof(child));
    father = nullptr;
    this->r = r;
}

void QuadTreeNode::addObjet(GameObject *o, uint maxObjectLevel){
    Rect2D rect;
    if(isHoja() && maxObjectLevel <=  m_Objects.size()){
        //grego un nuevo nivel
        newLevel();
    }
    if(isHoja()){
        //si es hoja, ponemos los objetos aqui
        m_Objects.insert(o);
    }else{
        rect = o->boundBox();
        if(//Compruebo que no se queda a en la frontera
                (rect.w()+rect.x())> (**child)->r.w() ||
                (rect.h()+rect.y())> (**child)->r.h()){
            m_Objects.insert(o);
        }else {
            child[(r.x()+r.w())>rect.x()][(r.h()+r.y())>rect.y()]->addObjet(o,maxObjectLevel);
        }
        //si no es hoja seguimos bajando
    }
}

bool QuadTreeNode::isEmpy(){
    return !m_Objects.size();
}

bool QuadTreeNode::isHoja(){
    return !**child;
}

void QuadTreeNode::newLevel(){
    Rect2D rect = r;
    rect.w() /= 2;
    rect.h() /= 2;
    child[0][0] = new QuadTreeNode(rect);

    rect.x() += rect.w();

    child[0][1] = new QuadTreeNode(rect);

    rect.y() += rect.h();
    rect.x() -= rect.w();
    child[1][0] = new QuadTreeNode(rect);
    rect.x() += rect.w();
    child[1][1] = new QuadTreeNode(rect);
}
