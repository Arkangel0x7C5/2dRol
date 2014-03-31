#ifndef SERVICE_H
#define SERVICE_H

#include <pthread.h>

class Service{
    public:
        virtual ~Service();
        void start();
        void stop();

        virtual void run() = 0;

        bool runing() const{
            return m_runing;
        }
    private:
        static void *thread(Service* _this);
    protected:
        bool m_runing;
        pthread_t m_thread;
        Service();
};

#endif // SERVICE_H
