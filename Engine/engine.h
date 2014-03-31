#ifndef ENGINE_H
#define ENGINE_H

#include "engine_global.h"
#include <gameobject.h>

#include <list>

class ENGINESHARED_EXPORT Engine{
    private:
        Engine(int* pargc, char** argv);
    public:
        static Engine& instance(int* pargc = 0, char** argv = 0);

        void setResolution(int w,int h);
        void setViewPort();

        static void draw();
        static void resize(int width, int height);
        static void keyDown(byte key,int width, int height);
        static void keyUp(byte key,int width, int height);

        static void eKeyDown(int key,int width, int height);
        static void eKeyUp(int key,int width, int height);
        static void mouseButton(int button, int state,int x, int y);

        void run();

        drawable *drawableObject() const;
        void setDrawableObject(drawable *drawableObject);

    private:
        drawable* m_drawableObject;
        std::list<GameObject*> gameObjects;
};

#endif // ENGINE_H
