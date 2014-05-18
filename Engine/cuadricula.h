#ifndef CUADRICULA_H
#define CUADRICULA_H

#include "drawable.h"
#include <vector>
struct Vertex{
    Point point;
    Point2d texCoord;
};

class ENGINESHARED_EXPORT cuadricula : public drawable{
    public:
        cuadricula(int w, int h);
        virtual ~cuadricula();
        virtual void draw();

        Size size() const;
        void setSize(const Size &size);

    private:
        void gen();
        uint m_vboPoint;
        uint m_vboTexture;
        uint m_texture;
        Size m_size;
        std::vector<Point> m_point;
        std::vector<Point2d> m_textCoord;
        std::vector<byte> m_index;
};

#endif // CUADRICULA_H
