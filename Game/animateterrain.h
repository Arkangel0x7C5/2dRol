#ifndef ANIMATETERRAIN_H
#define ANIMATETERRAIN_H

#include "terrain.h"
#include <Interfaces/animation.h>
#include <vector>

class AnimateTerrain:public Terrain,Animation{
    public:
        AnimateTerrain();
        virtual void draw() override;
        virtual void tick() override;

        std::vector<textureClip>& frames();
    private:
        uint m_index;
        std::vector<textureClip> m_frames;

};

#endif // ANIMATETERRAIN_H
