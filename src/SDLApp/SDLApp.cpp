#include "include/SDLApp.h"

SDLApp::SDLApp()
{
    quit = false;
    SDL = new SDLSetup(&quit);
    background = new Sprite(IMG_LoadTexture(SDL->getRenderer(), "img/background.png"), SDL, 0, 0, 10);

    in = new Input();
}

SDLApp::~SDLApp()
{
    delete background;
    delete in;
    delete SDL;
}
void SDLApp::eventHandling()
{
    if(in->getEvent()->type == SDL_QUIT) quit = true;
}
void SDLApp::eventHandler()
{
    while(in->update())
    {
        eventHandling();
    }
}

void SDLApp::rendering()
{
    background->draw();
}

bool SDLApp::run()
{
    eventHandler();

    SDL->start();
    rendering();
    SDL->finish();
    return !quit;
}

