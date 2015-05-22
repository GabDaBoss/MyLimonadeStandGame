#pragma once
#include "include/SpriteHandler.h"


class Button
{
    public:
        Button(Sprite* sprite, bool status = true);
        virtual ~Button();
        void flipStatus();
        bool getStatus();
        void setStatus(bool status);
        SDL_Rect getRect();
        SDL_Rect setRect(SDL_Rect rect);
        void draw();
    protected:
    private:
        bool status;
        Sprite* sprite;
};

