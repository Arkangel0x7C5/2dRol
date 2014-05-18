#ifndef LEVELSCENE_H
#define LEVELSCENE_H

#include "scene.h"
#include "drawable.h"
#include "tile.h"
#include "manager/terrainmanager.h"
#include <gameobject.h>

class cubeEnemy:public GameObject{
    public:
        cubeEnemy();
        virtual Rect2D boundBox() override;
        void setTerrain(Terrain *terrain);
        virtual drawable* getDrawable()  override;

private:
        Terrain* m_terrain;
};

class levelScene:public Scene{
    public:
        levelScene(uint w = 0,uint h = 0);

        virtual void draw(Rect2D &r) override;
        virtual void loadFromFile(std::string path) override;

        void setSize(const Size2D& s);
        Size2D size()const{
            return Size2D(m_tiles.size()?
                              m_tiles[0].size():0
                          ,m_tiles.size());
        }
    private:
        drawable* d;
        std::vector< std::vector<Tile> > m_tiles;
        TerrainManager m_terrainMgr;
        cubeEnemy enemy;
};

#endif // LEVELSCENE_H
