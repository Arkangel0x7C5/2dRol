#include "tile.h"

Tile::Tile():m_terrain(nullptr){
}
Terrain *Tile::terrain() const{
    return m_terrain;
}

void Tile::setTerrain(Terrain *terrain){
    m_terrain = terrain;
}

