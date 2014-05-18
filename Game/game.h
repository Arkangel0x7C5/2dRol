#ifndef GAME_H
#define GAME_H

#include "game_global.h"
#include "cuadricula.h"
#include "levelscene.h"
#include "objectmodelmanager.h"

#include <map>

class GAMESHARED_EXPORT Game{
    public:
        Game();
        void init();
    private:
        //cuadricula c;
        levelScene m_gameLevel;
        ObjectFactory<GameObject,std::string> m_gameObjectFactory;
};

#endif // GAME_H
