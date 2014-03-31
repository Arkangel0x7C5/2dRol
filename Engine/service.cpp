#include "service.h"
#include "GL/freeglut.h"
#include <pthread.h>

Service::~Service(){

}

void Service::start(){
    m_runing = true;
    pthread_create(&m_thread,nullptr,(void*(*)(void*))&thread,this);
}

void Service::stop(){
    void* returned;
    m_runing = false;
    pthread_join(m_thread,&returned);
}


Service::Service(){
}
void* Service::thread(Service* _this){
    //thread_local int h;
    if(_this){
        _this->run();
    }
    return nullptr;
}





