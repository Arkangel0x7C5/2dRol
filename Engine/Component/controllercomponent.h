#ifndef CONTROLLERCOMPONENT_H
#define CONTROLLERCOMPONENT_H

#include "Interfaces/component.h"

class ControllerComponent : public Component{
    public:
        ControllerComponent();

        // Component interface
        const std::string &type() const;
};

#endif // CONTROLLERCOMPONENT_H
