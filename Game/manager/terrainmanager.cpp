#include "terrainmanager.h"
#include "staticterrain.h"
#include "animateterrain.h"
#include <imagemanager.h>
#include "configparser.h"

#include <fstream>
#include <iostream>
#include <map>
#include <string.h>

using namespace std;
TerrainManager::TerrainManager(){
}

void TerrainManager::load(std::string filePath){
    std::ifstream file;
    configParser parser;
    file.open(filePath,std::ios_base::in);

    if(file.is_open() && parser.parseInitFile(file) && !parser.empy()){
        string name;
        int tileWidth,tileHeigth,imageWidth,imageHeigth,nFotogram;
        name = parser.queryString("name");
        imageWidth = parser.queryInt("imageWidth",0)/*atoi(parser.values["imageWidth"].c_str())*/;
        imageHeigth = parser.queryInt("imageHeigth",0);
        tileWidth = parser.queryInt("tileWidth",0);
        tileHeigth = parser.queryInt("tileHeigth",0);
        int textID = ImageManager::instance().getImage(parser.queryString("imgPath").c_str());
        bool animate = parser.queryBool("animate",false);
        nFotogram = parser.queryInt("nFotogram");

        int xMax = imageWidth/tileWidth,yMax = imageHeigth/tileHeigth;

        Terrain* terrain;
        textureClip texture;
        for(int y = 0;y<yMax;y++){
            for(int x = 0;x<xMax;x++){
                texture.textID = textID;

                texture.textCoord[0] = Point(x*tileWidth/(float)imageWidth
                                             ,y*tileHeigth/(float)imageHeigth);
                texture.textCoord[3] = Point((x+1)*tileWidth/(float)imageWidth
                                             ,y*tileHeigth/(float)imageHeigth);
                texture.textCoord[2] = Point((x+1)*tileWidth/(float)imageWidth
                                             ,(y+1)*tileHeigth/(float)imageHeigth);
                texture.textCoord[1] = Point(x*tileWidth/(float)imageWidth
                                             ,(y+1)*tileHeigth/(float)imageHeigth);

                if(animate){
                    if(!((x+y*xMax)%nFotogram)){
                        terrain = new AnimateTerrain();
                        //terrain->setSize(Size(1,1,0));
                        terrain->setId(x+y*xMax+1);

                        m_terrains.insert(pair<uint,Terrain*>(terrain->id(),terrain));
                    }
                    ((AnimateTerrain*)terrain)->frames().push_back(texture);
                }else{
                    terrain = new staticTerrain();
                    ((staticTerrain*)terrain)->setTexture(texture);
                    //terrain->setSize(Size(1,1,0));
                    terrain->setId(x+y*xMax+1);

                    m_terrains.insert(pair<uint,Terrain*>(terrain->id(),terrain));

                }
            }
        }
    }
}

Terrain* TerrainManager::get(uint Id){
    Terrain* t = nullptr;
    map<uint,Terrain*>::iterator it;
    if((it = m_terrains.find(Id)) != m_terrains.end()){
        t = (*it).second;
    }
    return t;
}
