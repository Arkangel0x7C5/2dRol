#ifndef TERRAINMANAGER_H
#define TERRAINMANAGER_H

#include "terrain.h"
#include <map>


class TerrainManager{
    public:
        TerrainManager();
        void load(std::string filePath);
        Terrain* get(uint Id);
    private:
        std::map<uint,Terrain*> m_terrains;
};

#endif // TERRAINMANAGER_H
