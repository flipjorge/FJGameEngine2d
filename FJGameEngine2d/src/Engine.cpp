#include "Engine.h"

void Engine::init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        exit(1);
    }

    _window = SDL_CreateWindow("FJGameEngine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);

    if (!_window)
    {
        SDL_Log("Unable to create window: %s", SDL_GetError());
        exit(1);
    }

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

    if (!_renderer)
    {
        SDL_Log("Unable to create renderer: %s", SDL_GetError());
        exit(1);
    }
}

void Engine::processInput()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            _isRunning = false;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                _isRunning = false;
            }
        default:
            break;
        }
    }
}

void Engine::update()
{
    double deltaTime = (SDL_GetTicks() - _lastFrameTicks) / 1000.0f;
    _lastFrameTicks = SDL_GetTicks();

    //
}

void Engine::render()
{
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);

    SDL_RenderPresent(_renderer);
}

bool Engine::getIsRunning()
{
    return _isRunning;
}