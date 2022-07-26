#include "Engine.h"

int main(int argc, char* argv[])
{
    Engine engine;
    
    engine.init();

    while (engine.getIsRunning())
    {
        engine.processInput();
        engine.update();
        engine.render();
        SDL_Delay(1000 / 60);
    }

    return 0;
}