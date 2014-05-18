#include "game.h"
#include "engine.h"
#include "character.h"

Game::Game()/*:c(8,4)*/{
}

void Game::init(){
    CharacterCtor* charCtor = new CharacterCtor("heroe.conf");
    //charCtor.create();
    m_gameObjectFactory.registerClassObject("Heroe",charCtor);

    //Engine::instance().setDrawableObject(&c);
    m_gameLevel.setGameFactory(&m_gameObjectFactory);
    m_gameLevel.loadFromFile("map.conf");

    Engine::instance().setScene(&m_gameLevel);
}
