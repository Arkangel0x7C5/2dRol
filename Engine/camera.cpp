#include "camera.h"
#include "GL/freeglut.h"
#include "GLES3/gl3.h"

Camera::Camera(){
    m_windowsID = 0;
}

void Camera::setup(){
    glOrtho(0,m_size.w()/m_wordSize.w(),m_size.h()/m_wordSize.h(),0,-m_wordSize.x(),m_wordSize.x());
}
Size Camera::wordSize() const{
    return m_wordSize;
}

void Camera::setWordSize(const Size &wordSize)
{
    m_wordSize = wordSize;
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







