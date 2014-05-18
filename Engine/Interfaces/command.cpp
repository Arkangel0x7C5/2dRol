#include "command.h"

#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>


using namespace boost::algorithm;

Command::Command()
{
}

bool Command::setParam(const std::string &/*name*/, const std::string &/*value*/){
    return false;
}

bool Command::setParam(const std::string &/*name*/, const std::vector<std::string> &/*value*/){
    return false;
}

Command::~Command(){

}
CommandFactory::CommandFactory(){

}/*
Command *CommandFactory::createCommand(const std::string &command){
    Command* newCommand = nullptr;

    if(!command.empty()){
        std::vector<std::string> commandTokend;
        //Dividimos la cadena separandola por espacios
        split(commandTokend,command,is_any_of(" "));
        newCommand = createCommandPrivate(commandTokend);
    }

    return newCommand;
}*/
