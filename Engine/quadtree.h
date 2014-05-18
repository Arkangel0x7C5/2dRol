#ifndef QUADTREE_H
#define QUADTREE_H
#include <set>
#include <cstdlib>
#include <cstdio>
#include <string>
#include "engine_global.h"

class GameObject;
struct QuadTreeNode;

class QuadTree{
    public:
        QuadTree();
        void setSize(Size2D &s);
        void setLevelSize(Size2D& s);
        std::set<GameObject*> getObjects(Rect2D& r);
        void addObjet(GameObject *o);
        void removeObjet(GameObject *o);
    private:
        QuadTreeNode* m_tree;
        uint m_maxObjectLevel;
};

#endif // QUADTREE_H
