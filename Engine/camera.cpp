#include "camera.h"
#include "GL/freeglut.h"
#include "GLES3/gl3.h"

Camera::Camera(){
    m_windowsID = 0;
}

void Camera::setup(){
    glOrtho(0,m_size.w(),m_size.h(),0,-m_size.x(),m_size.x());
}
Size Camera::size() const{
    return m_size;
}

void Camera::setSize(const Size &size){
    m_size = size;
    update();
}
Point Camera::pos() const{
    return m_pos;
}

void Camera::setPos(const Point &pos){
    m_pos = pos;
    update();
}

void Camera::update(){
    glutPostRedisplay();
    glutPostRedisplay();
}







