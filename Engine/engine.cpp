#include "engine.h"
#include "event.h"

#include <GL/freeglut.h>
#include <GL/glu_mangle.h>
#include <GL/glx.h>

#include <GLES3/gl3.h>

#include <Event/keyboarevent.h>
#include <Event/mouseevent.h>
#include <imagemanager.h>


bool Engine::gameMode = false;
Engine::Engine(int *pargc, char **argv){
    glutInit(pargc,argv);
    glutInitContextVersion(3,0);
    glutInitContextProfile(GLUT_FORWARD_COMPATIBLE);
    glutInitContextProfile(GLUT_CORE_PROFILE);

    glutInitDisplayMode(GLUT_DEPTH |
                        GLUT_DOUBLE |
                        GLUT_RGBA |
                        GLUT_MULTISAMPLE);

    glutInitWindowSize(800,600);
    glutCreateWindow("ventana");

    setupWindows();

    KeyboarEvent::init();
    MouseClickEvent::init();
    MouseMotionEvent::init();

    int error = glGetError();
    if(error != GL_NO_ERROR)
        printf("engine error %u %s\n",error,glGetStringi(error,0));

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

    Camera* c = e.currentCamera();
    if(c){
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        c->setup();

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glTranslatef(c->pos().x(),c->pos().y(),c->pos().z());


    if(d){
        d->draw();
    }/*
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,e.m_texture);

        //glColor3f(1,1,0.3);
        glBegin(GL_QUADS);
        glTexCoord2f(1,1);glVertex3f(3,0,0);
        glTexCoord2f(1,0);glVertex3f(3,6,0);
        glTexCoord2f(0,0);glVertex3f(0,6,0);
        glTexCoord2f(0,1);glVertex3f(0,0,0);
        glEnd();*/

        glutSwapBuffers();
    }
}

void Engine::resize(int width, int height){
    Engine& e = instance();
    Camera* c = e.currentCamera();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0,0,width,height);
    printf("resize %ux%u\n",width,height);
    //currentWindows->setSize(Size(width,height));
    if(c)
        c->setup();

    glMatrixMode(GL_MODELVIEW);

    glutPostRedisplay();
}

void Engine::keyDown(byte key, int /*width*/, int /*height*/){
    printf("%x\n",key);
    KeyboarEvent* e = KeyboarEvent::create(key);
    EventManager::instance().sendEvent(e);
    if(key == 0xd){
        instance().startGame();
    }else if(key == 0x1b){
        if(gameMode)
            instance().stopGame();
        else {
            instance().exit();
        }
    }
}

void Engine::keyUp(byte /*key*/, int /*width*/, int /*height*/){

}

void Engine::eKeyDown(int key, int /*width*/, int /*height*/){
    printf("especial %x\n",key);
    Camera* c = instance().currentCamera();
    Point cameraPos = c->pos();
    switch (key) {
        case GLUT_KEY_DOWN:
            cameraPos.y() += 0.2;
            break;
        case GLUT_KEY_UP:
            cameraPos.y() -= 0.2;
            break;
        case GLUT_KEY_LEFT:
            cameraPos.x() -= 0.02;
            break;
        case GLUT_KEY_RIGHT:
            cameraPos.x() += 0.02;
            break;
        default:
            break;
    }
    c->setPos(cameraPos);
}

void Engine::eKeyUp(int /*key*/, int /*width*/, int /*height*/){

}

void Engine::mouseButton(int /*button*/, int /*state*/, int /*x*/, int /*y*/){
    printf("click\n");
}

void Engine::run(){
    EventManager::instance().start();

    onInit();

    glutMainLoop();
    printf("exit main loop\n");
}

void Engine::onInit(){
    glClearColor(0,0,0,0);

    m_texture = ImageManager::instance().getImage("/home/juan/Sources/Games/Rol/launcher/img/prueba.png");
}
drawable *Engine::drawableObject() const{
    return m_drawableObject;
}

void Engine::setDrawableObject(drawable *drawableObject){
    m_drawableObject = drawableObject;
}

void Engine::startGame(){
    if(!gameMode){
        gameMode = true;
        glutGameModeString("640x480:16@60");
        //glutFullScreen();
        glutEnterGameMode();

        setupWindows();
    }

}

void Engine::stopGame(){
    //glutLeaveFullScreen();
    glutLeaveGameMode();
    gameMode = false;
}

void Engine::exit(){
    glutLeaveMainLoop();
}

void Engine::setupWindows(){
    //draw
    glutDisplayFunc(&draw);
    glutOverlayDisplayFunc(&draw);
    //resize
    glutReshapeFunc(&resize);
    //keyboard
    glutKeyboardFunc(&keyDown);
    glutKeyboardUpFunc(&keyUp);

    glutSpecialFunc(&eKeyDown);
    glutSpecialUpFunc(&eKeyUp);

    //mouse
    glutMouseFunc(&mouseButton);

    //glutPostRedisplay();
}
Camera *Engine::currentCamera(){
    return m_currentCamera;
}

void Engine::setCurrentCamera(Camera *currentCamera){
    m_currentCamera = currentCamera;
}

