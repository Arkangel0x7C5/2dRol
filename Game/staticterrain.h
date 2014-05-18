#ifndef STATICTERRAIN_H
#define STATICTERRAIN_H

#include "terrain.h"

class staticTerrain:public Terrain{
    public:
        staticTerrain();
        virtual ~staticTerrain();
        virtual void draw() override;
        textureClip texture() const;
        void setTexture(const textureClip &texture);

    private:
        textureClip m_texture;
};

#endif // STATICTERRAIN_H
