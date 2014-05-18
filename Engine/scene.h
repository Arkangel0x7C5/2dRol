#ifndef SCENE_H
#define SCENE_H

#include "engine_global.h"
#include "quadtree.h"
#include <queue>
#include "service.h"
#include "Interfaces/command.h"
#include "Interfaces/animation.h"
#include "Interfaces/objectfactory.h"

class ENGINESHARED_EXPORT Scene:public CommandFactory{
    public:
        Scene();
        virtual void draw(Rect2D &r);

        AnimationManager& animationMgr();
        virtual void loadFromFile(std::string path);
        QuadTree& tree();
        void setTree(const QuadTree &tree);

        Size size() const;
        void setSize(const Size &size);

        ObjectFactory<GameObject, std::string> *gameFactory() const;
        void setGameFactory(ObjectFactory<GameObject, std::string> *gameFactory);

    protected:
        virtual Command* createCommandPrivate(const std::vector<std::string>& comands);

        virtual void onStart();
        virtual void onPause();
        virtual void onStop();

    private:
        friend class startCommand;
        friend class pauseCommand;
        friend class stopCommand;

        virtual void run();
        QuadTree m_tree;
        Size m_size;
        AnimationManager m_animationMgr;
        ObjectFactory<GameObject, std::string> *m_gameFactory;

};

#endif // SCENE_H
