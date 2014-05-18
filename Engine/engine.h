#ifndef ENGINE_H
#define ENGINE_H

#include "engine_global.h"
#include <gameobject.h>
#include "camera.h"
#include "scene.h"

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
        void onInit();

        drawable *drawableObject() const;
        void setDrawableObject(drawable *drawableObject);

        void startGame();
        void pauseGame();
        void stopGame();
        void exit();

        void setupWindows();

        Camera *currentCamera();
        void setCurrentCamera(Camera *currentCamera);

        uint m_texture;
        Scene *scene() const;
        void setScene(Scene *scene);

    private:
        static bool gameMode;
        drawable* m_drawableObject;

        std::list<GameObject*> gameObjects;
        Camera* m_currentCamera;
        Scene* m_scene;
};

#endif // ENGINE_H
