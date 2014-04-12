#ifndef COMMANDMANAGER_H
#define COMMANDMANAGER_H

#include <service.h>
#include <queue>
#include <Interfaces/command.h>

class CommandManager : public Service{
    public:
        CommandManager();
        virtual void run();

        //void listenAction(std::string actionName,eventListener);
        //void setActionKeys(std::string actionName,keys);

        void execComand(Command* cmd);
    private:
        std::queue<Command*> m_comands;
};

#endif // COMMANDMANAGER_H
