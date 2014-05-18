#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "engine_global.h"

class drawable{
    public:
        drawable();
        virtual ~drawable();
        virtual void draw() = 0;/*
        Point pos() const;
        void setPos(const Point &pos);

        Size size() const;
        void setSize(const Size &size);

    private:
        Point m_pos;
        Size m_size;*/
};

#endif // DRAWABLE_H
