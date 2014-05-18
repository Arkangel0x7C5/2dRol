#ifndef TILE_H
#define TILE_H

#include "game_global.h"
#include "terrain.h"

class GAMESHARED_EXPORT Tile{
    public:
        Tile();
        Terrain *terrain() const;
        void setTerrain(Terrain *terrain);

    private:
        Terrain* m_terrain;
};

#endif // TILE_H
