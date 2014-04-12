#include "imagemanager.h"

#include <FreeImagePlus.h>
#include <SOIL/SOIL.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include <GLES2/gl2.h>

ImageManager::ImageManager(){
}

ImageManager &ImageManager::instance(){
    static ImageManager s_instance;

    return s_instance;
}

int ImageManager::getImage(const char *fileName){
    GLuint texture = 0;
    int width,height,bitsPerPixel;

    SDL_Surface* surface = nullptr;
    surface = IMG_Load(fileName);

    byte* pixel = nullptr;//SOIL_load_image(fileName,&width,&height,&bitsPerPixel,4);

    if(surface){

        //SDL_LockSurface(surface);
        pixel = (byte*)surface->pixels;
        width = surface->w;
        height = surface->h;
        bitsPerPixel = surface->format->BitsPerPixel;
        int mode = bitsPerPixel == 32?GL_RGBA:GL_RGB;

        glGenTextures(1,&texture);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, mode,
                      GL_UNSIGNED_BYTE, pixel);
        //Set texture parameters
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        //printf("%u\n",glGetError());
        //Unbind texture
        glBindTexture( GL_TEXTURE_2D, 0 );
    }else{
        printf("ImageManager::getImage cant not load image\n\terror: %s\n",SDL_GetError());
    }

    return texture;
}
