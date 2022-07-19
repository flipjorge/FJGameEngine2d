#include <iostream>
#include <SDL.h>

typedef struct
{
    SDL_Window* window;
    SDL_Renderer* renderer;
} App;

void initSDL(App& app)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        exit(1);
    }

    app.window = SDL_CreateWindow("FJGameEngine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);

    if (!app.window)
    {
        SDL_Log("Unable to create window: %s", SDL_GetError());
        exit(1);
    }

    app.renderer = SDL_CreateRenderer(app.window, -1, SDL_RENDERER_ACCELERATED);

    if (!app.renderer)
    {
        SDL_Log("Unable to create renderer: %s", SDL_GetError());
        exit(1);
    }
}

int main(int argc, char* argv[])
{
    App app;
    
    initSDL(app);

    return 0;
}