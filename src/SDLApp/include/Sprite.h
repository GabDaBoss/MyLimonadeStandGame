#pragma once
#include "SDLSetup.h"


class Sprite
{
    public:
        Sprite(SDL_Texture* texture, SDLSetup* SDL);
        Sprite(SDL_Texture* texture, SDLSetup* SDL, int x, int y, int scale);
        Sprite(SDL_Texture* texture, SDLSetup* SDL, SDL_Rect srcRect, int x, int y, int scale);
        virtual ~Sprite();
        Sprite* makeSprite(SDL_Rect srcRect, int x, int y, int scale);
        SDL_Rect getSrcRect();
        void setSrcRect(SDL_Rect src);
        void setSrcRect(int x, int y, int w, int h);

        SDL_Rect getDestRect();
        void setDestRect(SDL_Rect dest);
        void setDestRect(int x=0, int y=0, int scaling=1);
        void setDestRect(int x=0, int y=0);
        void setX(int x);
        void setY(int y);
        void moveX(int x=1);
        void moveY(int y=1);
        int getScaling();
        void setScaling(int scaling);

        double getAngle();
        void setAngle(double angle);
        SDL_Point getCenter();
        void setCenter(int x , int y);
        SDL_RendererFlip getFlip();
        void setFlip(SDL_RendererFlip);


        void draw();
        void draw(SDL_Rect* srcRect, SDL_Rect* destRect, double rotation, SDL_Point* center, SDL_RendererFlip flipping);
    protected:
    private:
        SDL_Texture* texture;
        SDL_Rect srcRect;
        SDL_Rect destRect;
        SDLSetup* SDL;
        double angleOfRotation;
        SDL_Point* centerOfRotation;
        SDL_RendererFlip flip;
        int scaling;
};

