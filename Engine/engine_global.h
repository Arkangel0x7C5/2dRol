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
        const float &x_const()const{
            return ejes[0];
        }
        const float &y_const()const{
            return ejes[1];
        }
        const float &z_const()const{
            return ejes[2];
        }
};
struct Point2d{
    public:
        Point2d(float x = 0,float y = 0){
            this->x() = x;
            this->y() = y;
        }
        float ejes[2];
        float &x(){
            return ejes[0];
        }
        float &y(){
            return ejes[1];
        }
        const float &x_const()const{
            return ejes[0];
        }
        const float &y_const()const{
            return ejes[1];
        }

};

struct Size{
    Size(){
        w() = h() = x() = 0;
    }
    Size(float w,float h,float x){
        this->w() = w;
        this->h() = h;
        this->x() = x;
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
    const float& w_const()const{
        return s[0];
    }
    const float& h_const()const{
        return s[1];
    }
    const float& x_const()const{
        return s[2];
    }
};

struct Size2D{
    Size2D(){
        w() = h() = 0;
    }
    Size2D(float w,float h){
        this->w() = w;
        this->h() = h;
    }
    float s[2];
    float& w(){
        return s[0];
    }
    float& h(){
        return s[1];
    }
    const float& w_const() const{
        return s[0];
    }
    const float& h_const() const{
        return s[1];
    }
};
struct Rect2D:Point2d,Size2D{
    Rect2D(float x = 0,float y = 0,float w = 0,float h = 0){
        this->w() = w;
        this->h() = h;
        this->x() = x;
        this->y() = y;
    }
    bool contains(Point2d& p){
        return (x()<=p.x() && (x()+w())>=p.x()) &&
                (y()<=p.y() && (y()+h())>=p.y());
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
