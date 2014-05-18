#include "scene.h"

class startCommand:public Command{
    public:
        startCommand(Scene* escena){
            m_escena = escena;
        }
        virtual void exec(){
            printf("startCommand\n");
            m_escena->animationMgr().start();
            m_escena->onStart();
        }
    private:
        Scene* m_escena;
};
class pauseCommand:public Command{
    public:
        pauseCommand(Scene* escena){
            m_escena = escena;
        }
        virtual void exec(){
            m_escena->animationMgr().restart();
            m_escena->animationMgr().stop();
            m_escena->onPause();
        }
    private:
        Scene* m_escena;
};
class stopCommand:public Command{
    public:
        stopCommand(Scene* escena){
            m_escena = escena;
        }
        virtual void exec(){
            printf("stopCommand\n");
            m_escena->onStop();
        }
    private:
        Scene* m_escena;
};

Scene::Scene(){
}

void Scene::draw(Rect2D & /*r*/){

}

Command *Scene::createCommandPrivate(const std::vector<std::string> &comands){
    Command* cmd = nullptr;
    if(comands.size()){
        if (comands[0] == "start") {
            cmd = new startCommand(this);
        } else if (comands[0] == "pause") {

        } else if (comands[0] == "stop") {

        }
    }
    return cmd;
}

void Scene::onStart(){
}

void Scene::onPause(){
}

void Scene::onStop(){
}

void Scene::run(){

}
ObjectFactory<GameObject, std::string> *Scene::gameFactory() const{
    return m_gameFactory;
}

void Scene::setGameFactory(ObjectFactory<GameObject, std::string> *gameFactory){
    m_gameFactory = gameFactory;
}

Size Scene::size() const
{
    return m_size;
}

void Scene::setSize(const Size &size)
{
    m_size = size;
}

QuadTree &Scene::tree(){
    return m_tree;
}

void Scene::setTree(const QuadTree &tree)
{
    m_tree = tree;
}

AnimationManager &Scene::animationMgr(){
    return m_animationMgr;
}

void Scene::loadFromFile(std::string /*path*/){}

