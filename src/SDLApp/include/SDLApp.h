#pragma once
#include "Input.h"
#include "SDLSetup.h"
#include "Text.h"
#include "SpriteHandler.h"

class SDLApp
{
    public:
        SDLApp();
        virtual ~SDLApp();
        bool run();
    protected:
        void eventHandling();
        void eventHandler();
        void rendering();
        bool quit;
        SDLSetup* SDL;
        Sprite* background;
        Input* in;
    private:
    };
