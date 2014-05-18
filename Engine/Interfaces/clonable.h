#ifndef CLONABLE_H
#define CLONABLE_H

class Clonable{
    public:
        Clonable();
        virtual Clonable* clone();
};

#endif // CLONABLE_H
