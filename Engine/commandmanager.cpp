#include "commandmanager.h"
#include "SDL/SDL_timer.h"

CommandManager::CommandManager(){}

CommandManager &CommandManager::instance(){
    static CommandManager s_instance;
    return s_instance;
}

void CommandManager::run(){
    while (runing()) {
        if(m_comands.empty()){
            SDL_Delay(10);
        }else{
            Command* cmd = m_comands.front();
            m_comands.pop();
            cmd->exec();
            delete cmd;
        }
    }
}

void CommandManager::execComand(Command *cmd){
    m_comands.push(cmd);
}
