#include "quadtree.h"
#include <cstring>
#include <cstdlib>

#include <gameobject.h>


typedef struct QuadTreeNode{
    QuadTreeNode(const Rect2D& r = Rect2D());
    void addObjet(GameObject *o,uint maxObjectLevel);

    bool isEmpy();
    bool isHoja();
    void newLevel();

    struct QuadTreeNode* child[2][2];
    struct QuadTreeNode* father;
    std::set<GameObject*> m_Objects;
    Rect2D r;
}QuadTreeNode;

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
        if(!rect.w())
            rect.w() = 1;
        if(!rect.h())
            rect.h() = 1;
        if(//Compruebo que no se queda a en la frontera
                (rect.w()+rect.x())> (**child)->r.w() ||
                (rect.h()+rect.y())> (**child)->r.h()){
            m_Objects.insert(o);
        }else {
            //si no es hoja seguimos bajando
            child[(r.x()+r.w())>rect.x()][(r.h()+r.y())>rect.y()]->addObjet(o,maxObjectLevel);
        }
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


QuadTree::QuadTree():m_tree(new QuadTreeNode()){

}

void QuadTree::setSize(Size2D &s){
    m_tree->r = Rect2D(0,0,s.w(),s.h());
}

std::set<GameObject *> QuadTree::getObjects(Rect2D &rect){
    std::set<GameObject *> Objects;
    //Va tomando caminos y recojiendo objeto hasta encontrarse que no hay mas niveles
    for(QuadTreeNode* node = m_tree;node;
        node = node->child[(node->r.x()+node->r.w())>rect.x()]
                            [(node->r.h()+node->r.y())>rect.y()]){
        //Agrego los objetos que se quedan en la frontera
        Objects.insert(node->m_Objects.begin(),node->m_Objects.end());
    }
    return Objects;
}

void QuadTree::addObjet(GameObject *o){
    m_tree->addObjet(o,m_maxObjectLevel);
}

void QuadTree::removeObjet(GameObject */*o*/){

}
