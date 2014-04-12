#include "cuadricula.h"
#include <GLES3/gl3.h>
#include <GL/glx.h>
#include <SOIL/SOIL.h>

#include "imagemanager.h"

cuadricula::cuadricula(int w, int h){
    glGenBuffers(1,&m_vboPoint);
    glGenBuffers(1,&m_vboTexture);


    m_size.w() = w+1;
    m_size.h() = h+1;

    m_texture = ImageManager::instance().getImage("/home/juan/Imágenes/main_banner.png");

    gen();
}

cuadricula::~cuadricula(){
    glDeleteBuffers(1,&m_vboPoint);
    glGenBuffers(1,&m_vboTexture);
}

void cuadricula::draw(){

    glTranslatef(m_size.w()/2,m_size.h()/2-1,0);
    glRotatef(180,1,0,0);

    glEnable(GL_TEXTURE_2D);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D,m_texture);

    glEnableClientState( GL_VERTEX_ARRAY );						// Enable Vertex Arrays
    glEnableClientState( GL_TEXTURE_COORD_ARRAY );				// Enable Texture Coord Arrays


    glBindBuffer( GL_ARRAY_BUFFER, m_vboPoint );
    glVertexPointer( 3, GL_FLOAT, 0, (char *) NULL );		// Set The Vertex Pointer To The Vertex Buffer
    glBindBuffer( GL_ARRAY_BUFFER, m_vboTexture );
    glTexCoordPointer( 2, GL_FLOAT, 0, (char *) NULL );		// Set The TexCoord Pointer To The TexCoord Buffer


    // Render
    glDrawArrays( GL_TRIANGLE_STRIP, 0, m_point.size() );	// Draw All Of The Triangles At Once
    //printf("draw error %u %s\n",glGetError(),glGetStringi(glGetError(),0));

    // Disable Pointers
    glDisableClientState( GL_VERTEX_ARRAY );					// Disable Vertex Arrays
    glDisableClientState( GL_TEXTURE_COORD_ARRAY );				// Disable Texture Coord Arrays

    glDisable(GL_TEXTURE_2D);
}
Size cuadricula::size() const{
    return m_size;
}

void cuadricula::setSize(const Size &size){
    m_size = size;
}

void cuadricula::gen(){
    m_point.clear();
    m_textCoord.clear();

    m_point.reserve((m_size.w())*(m_size.h()));
    m_textCoord.reserve((m_size.w())*(m_size.h()));
    uint y,x;
/*
    Vertex coord;
    for (uint i = 0; i < (uint)(m_size.h()*m_size.w()); i++) {
        y = i/(uint)size().h();
        x = i%(uint)size().h();
        coord.point.x() = x;
        coord.point.y() = y;

        coord.texCoord.x() = (x)/m_size.w();
        coord.texCoord.y() = (y)/m_size.h();

        m_point.push_back(coord);
    }*/
    Point2d texCoord;
    Point point;
    for (uint i = m_size.w(),e; i < (uint)((m_size.h())*m_size.w()); i++) {
        //e = fila superior
        //i = fila inferior
        e = i-m_size.w();

        //Calculo los puntos y las texturas para la posicion e
        y = e/(uint)size().w();
        x = e%(uint)size().w();

        point.x() = x-m_size.w()/2;
        point.y() = y-m_size.h()/2;

        texCoord.x() = x/m_size.w();
        texCoord.y() = 1-y/m_size.h();

        m_textCoord.push_back(texCoord);
        m_point.push_back(point);

        //Calculo los puntos y las texturas para la posicion i
        y = i/(uint)m_size.w();
        x = i%(uint)m_size.w();

        point.x() = x-m_size.w()/2;
        point.y() = y-m_size.h()/2;

        texCoord.x() = x/m_size.w();
        texCoord.y() = 1-y/m_size.h();

        m_textCoord.push_back(texCoord);
        m_point.push_back(point);
    }/*
    m_textCoord.clear();

    m_textCoord.push_back(Point2d(0,0));
    m_textCoord.push_back(Point2d(0,1));
    m_textCoord.push_back(Point2d(0.5,0));
    m_textCoord.push_back(Point2d(0.5,1));*/

    glBindBuffer(GL_ARRAY_BUFFER,m_vboPoint);
    glBufferData(GL_ARRAY_BUFFER, (m_point.size())*sizeof(*m_point.data()), m_point.data(), GL_STATIC_DRAW);
    //glVertexPointer(sizeof(Point)/sizeof(*Point::ejes),GL_FLOAT,sizeof(Vertex),0);
    glBindBuffer(GL_ARRAY_BUFFER,m_vboTexture);
    glBufferData(GL_ARRAY_BUFFER, (m_textCoord.size())*sizeof(*m_textCoord.data()), m_textCoord.data(), GL_STATIC_DRAW);
    //glTexCoordPointer(2,GL_FLOAT,sizeof(Vertex),&((Vertex*)m_point.data())->texCoord);
}
