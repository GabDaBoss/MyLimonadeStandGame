#pragma once
#include <string>
#include <strstream>
#include <sstream>
#include "SDLSetup.h"
class Text
{
    public:
        Text(TTF_Font *font, int x, int y, SDL_Color color, SDLSetup* SDL);
        virtual ~Text();
        void setString(std::string s);
        void setString(int n);
        void draw();
        void draw(int x, int y, int w, int h);
        SDL_Rect getRect();
    protected:
    private:
        void update();
        std::string str;
        TTF_Font *font;
        SDL_Rect rect;
        SDL_Color color;
        SDLSetup* SDL;


        SDL_Texture* text;
};




