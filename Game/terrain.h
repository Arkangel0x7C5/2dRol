#ifndef TERRAIN_H
#define TERRAIN_H

#include  <drawable.h>
#include <Interfaces/clonable.h>

struct textureClip{
    uint textID;
    Point textCoord[4];
};

class Terrain:public drawable,Clonable{
    public:
        Terrain();
        uint id() const;
        void setId(const uint &id);
    private:
        uint m_id;
};

#endif // TERRAIN_H
