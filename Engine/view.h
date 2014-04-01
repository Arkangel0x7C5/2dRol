#ifndef VIEW_H
#define VIEW_H

#include <gameobject.h>
#include <Event/mouseevent.h>

class View:public GameObject{
    public:
        View();
        virtual void onClick(MouseClickEvent* e);
};

#endif // VIEW_H
