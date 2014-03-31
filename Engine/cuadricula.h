#ifndef CUADRICULA_H
#define CUADRICULA_H

#include "drawable.h"
#include <vector>

class cuadricula : public drawable{
    public:
        cuadricula(int w,int x);
        virtual ~cuadricula();
        virtual void draw();

        Size size() const;
        void setSize(const Size &size);

    private:
        void gen();
        uint m_vboID;
        Size m_size;
        std::vector<Point> m_point;
        std::vector<byte> m_index;
};

#endif // CUADRICULA_H
