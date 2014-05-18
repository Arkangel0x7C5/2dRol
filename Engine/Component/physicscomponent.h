#ifndef PHYSICSCOMPONENT_H
#define PHYSICSCOMPONENT_H

#include "Interfaces/component.h"

class PhysicsComponent:public Component{
    public:
        PhysicsComponent();

        // Component interface
        const std::string &type() const;
};

#endif // PHYSICSCOMPONENT_H
