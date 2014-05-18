#ifndef GRAPHICCOMPONENT_H
#define GRAPHICCOMPONENT_H

#include "Interfaces/component.h"
#include "drawable.h"

class GraphicComponent:public Component,public drawable{
    public:
        GraphicComponent();

        // Component interface
        const std::string &type() const;
};

#endif // GRAPHICCOMPONENT_H
