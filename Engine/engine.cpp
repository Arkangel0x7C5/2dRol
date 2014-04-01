#include "engine.h"
#include "event.h"

#include <GL/freeglut.h>
#include <GL/glx.h>

#include <GLES3/gl3.h>

#include <Event/keyboarevent.h>


Engine::Engine(int *pargc, char **argv){
    glutInit(pargc,argv);
    glutInitContextVersion(3,0);

    glutInitDisplayMode(GLUT_DEPTH |
                        GLUT_DOUBLE |
                        GLUT_RGBA |
                        GLUT_MULTISAMPLE);

    glutInitWindowSize(800,600);
    glutCreateWindow("ventana");

    glutDisplayFunc(&draw);
    glutReshapeFunc(&resize);
    glutKeyboardFunc(&keyDown);
    glutKeyboardUpFunc(&keyUp);

    glutSpecialFunc(&eKeyDown);
    glutSpecialUpFunc(&eKeyUp);

    glutMouseFunc(&mouseButton);

    KeyboarEvent::init();

}

Engine &Engine::instance(int *pargc, char **argv){
    static Engine s_instance(pargc,argv);

    return s_instance;
}

void Engine::setViewPort(){

}

void Engine::draw(){
    Engine& e = instance();
    drawable* d = e.drawableObject();

    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);

    if(d){
        d->draw();
    }


    glutSwapBuffers();
}

void Engine::resize(int width, int height){


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0,0,width,height);
    //currentWindows->setSize(Size(width,height));
/*
    printf("Engine::resize\n\twindows size: %ix%i, matrix size: %.2fx%.2f\n",
                width,height,matrixSize.width(),matrixSize.height());*/
    glOrtho(0,40,40,0,-100,100);

    glMatrixMode(GL_MODELVIEW);

    glutPostRedisplay();
}

void Engine::keyDown(byte key, int /*width*/, int /*height*/){
    printf("%x\n",key);
    KeyboarEvent* e = KeyboarEvent::create(key);
    EventManager::instance().sendEvent(e);
}

void Engine::keyUp(byte /*key*/, int /*width*/, int /*height*/){

}

void Engine::eKeyDown(int /*key*/, int /*width*/, int /*height*/){

}

void Engine::eKeyUp(int /*key*/, int /*width*/, int /*height*/){

}

void Engine::mouseButton(int /*button*/, int /*state*/, int /*x*/, int /*y*/){

}

void initScene();
void Engine::run(){
    initScene();
    EventManager::instance().start();

    glutMainLoop();
}
drawable *Engine::drawableObject() const{
    return m_drawableObject;
}

void Engine::setDrawableObject(drawable *drawableObject){
    m_drawableObject = drawableObject;
}

void initScene()
{
    glClearColor(0,0,0,0);
}
