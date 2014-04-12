#ifndef QUADTREE_H
#define QUADTREE_H
#include <set>
#include <gameobject.h>
#include <cstdlib>
#include <cstdio>
#include <string>

typedef struct QuadTreeNode{
    QuadTreeNode(const Rect2D& r = Rect2D());
    void addObjet(GameObject *o,uint maxObjectLevel = 30);

    bool isEmpy();
    bool isHoja();
    void newLevel();

    struct QuadTreeNode* child[2][2];
    struct QuadTreeNode* father;
    std::set<GameObject*> m_Objects;
    Rect2D r;
}QuadTreeNode;

#endif // QUADTREE_H
