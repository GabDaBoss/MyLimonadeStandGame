
#include "include/SDLSetup.h"

SDLSetup::SDLSetup(bool *quit)
{
    //ctor
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_JPG);
    if(TTF_Init()==-1) {
        printf("TTF_Init: %s\n", TTF_GetError());
        exit(2);
    }
    window = NULL;
    window = SDL_CreateWindow("King of Trade",100 , 100, 800, 600, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        std::cout << "window init Error: " << SDL_GetError() << std::endl;
        *quit = true;
    }
    renderer = NULL;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

}

SDLSetup::~SDLSetup()
{
    //dtor
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    TTF_Quit();
    SDL_Quit();
    std::cout << "bye" << std::endl;
}
/*SDL_Event* SDL_setup_Class::getEvent()
{
    return &event;
}*/

SDL_Renderer* SDLSetup::getRenderer()
{
    return renderer;
}

SDL_Window* SDLSetup::getWindow()
{
    return window;
}


void SDLSetup::start()
{

    SDL_RenderClear(renderer);
}

void SDLSetup::finish()
{
    SDL_RenderPresent(renderer);
}
