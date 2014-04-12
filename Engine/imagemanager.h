#ifndef IMAGEMANAGER_H
#define IMAGEMANAGER_H

#include <engine_global.h>

class ImageManager{
        ImageManager();
    public:
        static ImageManager& instance();
        int getImage(const char* fileName);
        Size getImageResolution(int texture);
};

#endif // IMAGEMANAGER_H
