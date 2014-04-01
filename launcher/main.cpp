#include <iostream>

#include <engine.h>
#include <cuadricula.h>

using namespace std;

int main(int argc, char** argv )
{
    Engine& e = Engine::instance(&argc,argv);
    cuadricula c(10,10);


    e.setDrawableObject(&c);

    e.run();
    cin.get();
    return 0;
}

