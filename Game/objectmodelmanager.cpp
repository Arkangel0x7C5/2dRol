#include "objectmodelmanager.h"

ObjectModelManager::ObjectModelManager(){
}

void ObjectModelManager::loadTemplate(std::string /*filePath*/){

}

GameObject *ObjectModelManager::objectTemplate(std::string name){
    std::map<std::string,GameObject*>::iterator it = m_gameObjectTemplates.find(name);

    return (GameObject*)(it != m_gameObjectTemplates.end()?(*it).second->clone():nullptr);
}
