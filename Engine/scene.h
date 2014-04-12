#ifndef SCENE_H
#define SCENE_H

#include "engine_global.h"
#include "quadtree.h"
#include <queue>
#include "Interfaces/externanimation.h"
#include "Interfaces/internanimation.h"

class scene{
    public:
        scene();
        Size m_size;
    private:
        QuadTreeNode m_tree;
        std::queue<externAnimation*> m_eAnimation;
        std::queue<internAnimation*> m_iAnimation;
};

#endif // SCENE_H
