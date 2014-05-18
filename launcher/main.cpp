#include <iostream>

#include <engine.h>
#include <cuadricula.h>

#include "camera.h"


#include "game.h"


using namespace std;

int main(int argc, char** argv ){
    //Inicializacion del motor grafico
    Engine& e = Engine::instance(&argc,argv);
    //Camara principal y juego
    Camera camara;
    Game game;

    camara.setWordSize(Size(40,40,100));
    e.setCurrentCamera(&camara);

    game.init();
    e.startGame();

    e.run();
    return 0;
}
