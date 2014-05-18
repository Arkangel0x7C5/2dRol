#include "animateterrain.h"
#include <GLES3/gl3.h>
#include <GL/freeglut.h>

AnimateTerrain::AnimateTerrain():m_index(0){
}

void AnimateTerrain::draw(){
    textureClip text = m_frames[m_index];
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D,text.textID);
    glBegin(GL_QUADS);
        glTexCoord2f(text.textCoord[0].x(),text.textCoord[0].y());glVertex2f(0,0);
        glTexCoord2f(text.textCoord[1].x(),text.textCoord[1].y());glVertex2f(0,1);
        glTexCoord2f(text.textCoord[2].x(),text.textCoord[2].y());glVertex2f(1,1);
        glTexCoord2f(text.textCoord[3].x(),text.textCoord[3].y());glVertex2f(1,0);
    glEnd();
}

void AnimateTerrain::tick(){}
std::vector<textureClip> &AnimateTerrain::frames()
{
    return m_frames;
}
