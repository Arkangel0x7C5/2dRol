#ifndef ENGINE_GLOBAL_H
#define ENGINE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(ENGINE_LIBRARY)
#  define ENGINESHARED_EXPORT Q_DECL_EXPORT
#else
#  define ENGINESHARED_EXPORT Q_DECL_IMPORT
#endif

typedef unsigned char byte;
struct Point{
    public:
        Point(float x = 0,float y = 0,float z = 0){
            this->x() = x;
            this->y() = y;
            this->z() = z;
        }
        float ejes[3];
        float &x(){
            return ejes[0];
        }
        float &y(){
            return ejes[1];
        }
        float &z(){
            return ejes[2];
        }
};
struct Size{
    Size(){
        w() = h() = x() = 0;
    }
    float s[3];
    float& w(){
        return s[0];
    }
    float& h(){
        return s[1];
    }
    float& x(){
        return s[2];
    }
};

struct Color{
    Color(){
        r() = g() = b() = 0;
        a() = 255;
    }

    byte rgba[4];
    byte& r(){
        return rgba[0];
    }
    byte& g(){
        return rgba[1];
    }
    byte& b(){
        return rgba[2];
    }
    byte& a(){
        return rgba[3];
    }
};

#endif // ENGINE_GLOBAL_H
