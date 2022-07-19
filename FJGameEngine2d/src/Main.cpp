#include <iostream>
#include <SDL.h>

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        exit(1);
    }

    std::cout << "Hello, world!" << std::endl;
    return 0;
}