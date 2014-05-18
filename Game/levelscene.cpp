#include "levelscene.h"
#include "cuadricula.h"
#include "gameobject.h"

#include <GL/freeglut.h>
#include <fstream>

using namespace std;

levelScene::levelScene(uint w, uint h){
    d = new cuadricula(8,6);
    setSize(Size2D(w,h));
    //tree().addObjet(&enemy);
}

void levelScene::draw(Rect2D &r){
    printf("draw\n");
    glEnable(GL_DEPTH_TEST);
    //d->draw();
    Terrain *terrain;
    glPushMatrix();
    glDepthFunc(GL_LESS);

    for (uint y = 0; y < m_tiles.size(); ++y) {
        for (uint x = 0; x < m_tiles[y].size(); ++x) {
            glPushMatrix();
            glTranslatef(x,y,0);

            terrain = m_tiles[y][x].terrain();
            if(terrain)
                terrain->draw();

            glPopMatrix();
        }
    }
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_COLOR,GL_ONE);
    glTranslatef(0,0,1);
    std::set<GameObject*> objects = tree().getObjects(r);
    for(std::set<GameObject*>::iterator it = objects.begin();
            it!=objects.end();it++){
        drawable* d = (*it)->getDrawable();
        if(d)
            d->draw();
    }
    glPopMatrix();
    glDisable(GL_BLEND);
    glDisable(GL_DEPTH_TEST);
}

void levelScene::loadFromFile(std::string /*path*/){
    std::ifstream file;
    file.open("map.conf");

    if(file.is_open()){
        std::string strBuff,keyName,value;
        std::map<string,string> values;
        size_t ecualPos;

        //Parseo las lineas y las guardo en un map
        while (!file.eof()) {
            std::getline(file,strBuff);
            if(!strBuff.empty() && (ecualPos = strBuff.find_first_of('=')) != string::npos){
                keyName = strBuff.substr(0,ecualPos);
                value = strBuff.substr(ecualPos+1);
                values.insert(pair<string,string>(keyName,value));
            }
        }
        file.close();
        uint mapWidth = atoi(values["mapWidth"].c_str());
        uint mapHeigth = atoi(values["mapHeigth"].c_str());
        m_terrainMgr.load(values["terrainFile"]);
        string data = values["data"];

        enemy.setTerrain(m_terrainMgr.get(51));
        tree().addObjet(gameFactory()->create("Heroe"));

        setSize(Size2D(mapWidth,mapHeigth));
        if(!data.empty() && mapHeigth && mapWidth){
            size_t nextPos,backPos = 0;
            uint terrainID;
            //m_tiles.resize(mapHeigth);
            for(uint y= 0;y < mapHeigth && nextPos != string::npos;y++){
                //m_tiles[y].resize(mapWidth);
                for (uint x = 0; x < mapWidth && nextPos != string::npos; ++x) {
                    nextPos = data.find(',',backPos);
                    terrainID = atoi(data.substr(backPos,nextPos).c_str());
                   ((Tile*)&m_tiles[y][x])->setTerrain(m_terrainMgr.get(terrainID));


                    backPos = nextPos+1;
                }
            }
        }
#ifdef QT_DEBUG
        else{
            printf("levelScene::loadFromFile load error");
        }
#endif
    }
}

void levelScene::setSize(const Size2D &s){
    Size2D &size = *(Size2D*)&s;
    tree().setSize(*(Size2D*)&s);
    if(size.w() && size.h()){
        m_tiles.resize(size.h());
        for (int i = 0; i < size.h(); ++i) {
            m_tiles[i].resize(size.w());
        }
    }
}


cubeEnemy::cubeEnemy(){

}

Rect2D cubeEnemy::boundBox(){
    return Rect2D(0,0,1,1);
}

void cubeEnemy::setTerrain(Terrain *terrain){
    m_terrain = terrain;
}

drawable *cubeEnemy::getDrawable(){
    return m_terrain;
}

