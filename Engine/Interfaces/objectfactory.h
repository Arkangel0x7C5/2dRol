#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include <map>

template<typename typeBase>
class ObjectCtor{
    public:
        ObjectCtor(){}
        virtual typeBase* create();
};

template<typename typeBase>
typeBase* ObjectCtor<typeBase>::create(){
    return nullptr;
}


template <typename typeBase,typename typeID>
class ObjectFactory{
    public:
        void registerClassObject(typeID uniqueID,ObjectCtor<typeBase>* ctor);
        typeBase* create(typeID uniqueID);
    private:
        std::map<typeID,ObjectCtor<typeBase>*> m_registeredObject;
};

template <typename typeBase,typename typeID>
void ObjectFactory< typeBase,typeID >::registerClassObject(typeID uniqueID, ObjectCtor<typeBase>* ctor){
    m_registeredObject.insert(std::pair<typeID,ObjectCtor<typeBase>*>(uniqueID,ctor));
}
template <typename typeBase,typename typeID>
typeBase* ObjectFactory< typeBase,typeID >::create(typeID uniqueID){

    typename std::map<typeID,ObjectCtor<typeBase>*>::iterator it = m_registeredObject.find(uniqueID);

    return (it!=m_registeredObject.end()?
                (*it).second->create():
                nullptr);
}
#endif // OBJECTFACTORY_H
