#include "character.h"
#include "configparser.h"
#include <fstream>
#include <manager/terrainmanager.h>


const char* basicAnimations[] = {"down","rigth","letf","up"};

Character::Character():m_terrain(nullptr){
    m_life.setName("life");
    m_maxLife.setName("maxLife");

    propiedades.add(&m_life);
    propiedades.add(&m_maxLife);
}

drawable *Character::getDrawable(){
    return terrain();
}

Rect2D Character::boundBox(){
    return Rect2D();
}

externAnimation *Character::animation(){
    return 0;
}
Terrain *Character::terrain() const{
    return m_terrain;
}

void Character::setTerrain(Terrain *terrain){
    m_terrain = terrain;
}

void Character::addAnimation(const std::string &name, AnimateTerrain *animation){
    m_animations.insert(std::pair<std::string,AnimateTerrain*>(name,animation));
}
Point2d Character::direction() const{
    return m_vecDirector;
}

void Character::setDirection(const Point2d &d){
    m_vecDirector = d;
    if(m_vecDirector.x()!=0){
        m_terrain = m_vecDirector.x()==1?m_animations[basicAnimations[1]]:m_animations[basicAnimations[2]];
    }else{
        m_terrain = m_vecDirector.y()==1?m_animations[basicAnimations[0]]:m_animations[basicAnimations[3]];
    }
}



CharacterCtor::CharacterCtor(std::string cfgPath):m_cfgPath(cfgPath){}

GameObject *CharacterCtor::create(){
    Character* personaje = nullptr;
    std::ifstream file;
    file.open(m_cfgPath,std::ios_base::in);

    if(file.is_open()){
        configParser parser;
        personaje = new Character();

        parser.parseInitFile(file);

        file.close();

        TerrainManager mgr;
        //cargo el terrain del personaje
        mgr.load(parser.queryString("terrainFile"));
        for(uint i = 0;i<sizeof(basicAnimations)/sizeof(*basicAnimations);i++){
            personaje->addAnimation(basicAnimations[i],(AnimateTerrain*)mgr.get(parser.queryInt(basicAnimations[i])));
        }
        personaje->setDirection(Point2d(0,1));
    }


    return personaje;
}
