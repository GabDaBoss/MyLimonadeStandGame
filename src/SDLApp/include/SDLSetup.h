#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <cstdlib>
class SDLSetup
{
    public:
        SDLSetup(bool *quit);
        virtual ~SDLSetup();
        SDL_Renderer* getRenderer();
        SDL_Window* getWindow();
        void start();
        void finish();
        //SDL_Event* getEvent();
    protected:
    private:
        SDL_Renderer* renderer;
        SDL_Window* window;
        //SDL_Event event;
};

