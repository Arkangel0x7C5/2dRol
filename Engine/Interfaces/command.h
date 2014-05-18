#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>
#include "objectfactory.h"

class Command{
    public:
        Command();

        virtual bool setParam(const std::string& name,const std::string& value);
        virtual bool setParam(const std::string& name,const std::vector<std::string>& value);

        virtual ~Command();
        virtual void exec() = 0;
};



class CommandFactory:public ObjectFactory<Command,std::string>{
    public:
        CommandFactory();/*
        Command* createCommand(const std::string& command);
        Command* createCommand(const std::vector<std::string>& comands){
            return createCommandPrivate(comands);
        }*/
        void exec(const std::string& command);

    protected:
        //virtual Command* createCommandPrivate(const std::vector<std::string>& comands) = 0;
};

#endif // COMMAND_H
