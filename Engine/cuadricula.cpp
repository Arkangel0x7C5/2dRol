#include "cuadricula.h"
#include <GLES3/gl3.h>
#include <GL/glx.h>

cuadricula::cuadricula(int w, int x){
    glGenBuffers(1,&m_vboID);

    m_size.w() = w+1;
    m_size.h() = x+1;
    gen();
}

cuadricula::~cuadricula(){
    glDeleteBuffers(1,&m_vboID);
}

void cuadricula::draw(){
    glTranslatef(1,1,0);
    glBindBuffer(GL_ARRAY_BUFFER, m_vboID);

    glEnableClientState(GL_VERTEX_ARRAY);

    //glDrawArrays(GL_LINES, 0, (m_point.size())*sizeof(*m_point.data()));
    glDrawElements(GL_LINE_STRIP,m_index.size(),GL_UNSIGNED_BYTE,m_index.data());

    glDisableClientState(GL_TEXTURE_2D_ARRAY);
}
Size cuadricula::size() const{
    return m_size;
}

void cuadricula::setSize(const Size &size){
    m_size = size;
}

void cuadricula::gen(){
    m_point.clear();
    m_index.clear();

    m_point.reserve((m_size.w())*(m_size.h()));
    uint y,x;
    for (uint i = 0; i < (uint)(m_size.h()*m_size.w()); i++) {
        y = i/(uint)size().h();
        x = i%(uint)size().h();
        m_point.push_back(Point(x,y));
    }
/*
    for (int i = 0; i < m_size.w(); ++i) {
        m_index.push_back(i);
    }*/
    for (uint i = m_size.w(); i < (uint)((m_size.h()-1)*m_size.w()); i++) {

        m_index.push_back(i-m_size.w());
        m_index.push_back(i);
    }

    glBindBuffer(GL_ARRAY_BUFFER,m_vboID);
    glBufferData(GL_ARRAY_BUFFER, (m_point.size())*sizeof(*m_point.data()), m_point.data(), GL_STATIC_COPY);
    glVertexPointer(sizeof(Point)/sizeof(*Point::ejes),GL_FLOAT,0,0);
    //glIndexPointer(sizeof(Point)/sizeof(*Point::ejes),GL_FLOAT,0,0);
}
