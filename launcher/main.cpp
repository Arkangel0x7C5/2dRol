#include <iostream>
#include <climits>

#include <engine.h>
#include <cuadricula.h>

#include "GLES3/gl3.h"
#include "GL/freeglut.h"
#include "GL/freeglut_ext.h"
#include "camera.h"


using namespace std;

int main(int argc, char** argv )
{

    Camera camara;
    Engine& e = Engine::instance(&argc,argv);
    cuadricula c(8,4);

    camara.setSize(Size(8,16,100));
    e.setCurrentCamera(&camara);

    e.setDrawableObject(&c);

    e.run();
    return 0;
}
