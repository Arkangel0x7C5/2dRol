#ifndef OBJECTMODELMANAGER_H
#define OBJECTMODELMANAGER_H

#include "game_global.h"
#include <gameobject.h>
#include <map>

class ObjectModelManager{
    public:
        ObjectModelManager();
        void loadTemplate(std::string filePath);
        GameObject* objectTemplate(std::string name);
    private:
        std::map<std::string,GameObject*> m_gameObjectTemplates;
};

#endif // OBJECTMODELMANAGER_H
