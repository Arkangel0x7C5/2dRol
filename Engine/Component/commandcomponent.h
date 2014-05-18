#ifndef COMMANDCOMPONENT_H
#define COMMANDCOMPONENT_H

#include "Interfaces/component.h"
#include "Interfaces/command.h"

class CommandComponent : public Component,public CommandFactory{
    public:
        CommandComponent();

        // Component interface
        const std::string &type() const;
};

#endif // COMMANDCOMPONENT_H
