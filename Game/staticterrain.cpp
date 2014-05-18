#include "staticterrain.h"
#include "GL/freeglut.h"

staticTerrain::staticTerrain(){
}

staticTerrain::~staticTerrain(){}

void staticTerrain::draw(){
    textureClip& text = m_texture;
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D,text.textID);
    glBegin(GL_QUADS);
        glTexCoord2f(text.textCoord[0].x(),text.textCoord[0].y());glVertex2f(0,0);
        glTexCoord2f(text.textCoord[1].x(),text.textCoord[1].y());glVertex2f(0,1);
        glTexCoord2f(text.textCoord[2].x(),text.textCoord[2].y());glVertex2f(1,1);
        glTexCoord2f(text.textCoord[3].x(),text.textCoord[3].y());glVertex2f(1,0);
    glEnd();
}
textureClip staticTerrain::texture() const{
    return m_texture;
}

void staticTerrain::setTexture(const textureClip &texture){
    m_texture = texture;
}

