#ifndef CAMERA_H
#define CAMERA_H

#include <engine_global.h>

class Camera{
    public:
        Camera();


        Size size() const;
        void setSize(const Size &size);

        Point pos() const;
        void setPos(const Point &pos);
        void update();
        Size wordSize() const;
        void setWordSize(const Size &wordSize);

protected:
        friend class Engine;
        virtual void setup();
    private:
        int m_windowsID;
        Size m_windowsSize;
        Point m_windowsPos;

        Size m_size;
        Size m_wordSize;
        Point m_pos;

};

#endif // CAMERA_H
