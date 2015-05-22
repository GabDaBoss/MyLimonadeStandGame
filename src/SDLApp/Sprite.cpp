#include "include/Sprite.h"


Sprite::Sprite(SDL_Texture* texture, SDLSetup* SDL)
{
    //ctor
    int w = 0;
    int h = 0;
    this->SDL = 0;
    this->texture = 0;
    if(SDL!= NULL) this->SDL = SDL;
    if(texture!=0)
    {
        SDL_QueryTexture(texture, NULL, NULL, &w, &h);
        this->texture = texture;
    }
    else
    {
        std::cout<< SDL_GetError() <<std::endl;
    }
    setSrcRect({0, 0, w, h});
    setDestRect(0,0,1);
    setAngle(0);
    centerOfRotation = NULL;
    setFlip(SDL_FLIP_NONE);
}
Sprite::Sprite(SDL_Texture* texture, SDLSetup* SDL, int x, int y, int scale)
{
    int w = 0;
    int h = 0;
    this->SDL = 0;
    this->texture = 0;
    if(SDL!= NULL) this->SDL = SDL;
    this->texture = texture;
    if(texture!=0)
    {
        SDL_QueryTexture(texture, NULL, NULL, &w, &h);
        this->texture = texture;
    }
    else
    {
        std::cout<< SDL_GetError() <<std::endl;
    }
    setSrcRect({0, 0, w, h});
    setDestRect(x,y,scale);
    setAngle(0);
    centerOfRotation = NULL;
    setFlip(SDL_FLIP_NONE);
}
Sprite::Sprite(SDL_Texture* texture, SDLSetup* SDL, SDL_Rect srcRect, int x, int y, int scale)
{
    int w = 0;
    int h = 0;
    this->SDL = 0;
    this->texture = 0;
    if(SDL!= NULL) this->SDL = SDL;
    if(texture!=0)
    {
        this->texture = texture;
    }
    setSrcRect(srcRect);
    setDestRect(x,y,scale);
    setAngle(0);
    centerOfRotation = NULL;
    setFlip(SDL_FLIP_NONE);
}
Sprite::~Sprite()
{
    delete texture;
}
Sprite* Sprite::makeSprite(SDL_Rect srcRect, int x, int y, int scale)
{
    Sprite* sprite = new Sprite(texture, SDL, srcRect, x, y, scale);
    return sprite;
}
SDL_Rect Sprite::getSrcRect(){return srcRect;}

void    Sprite::setSrcRect(SDL_Rect src){srcRect = src;}

SDL_Rect Sprite::getDestRect(){return destRect;}

void    Sprite::setDestRect(SDL_Rect dest){destRect=dest;}

void    Sprite::setDestRect(int x, int y, int scaling)
{
    destRect.x =x;
    destRect.y = y;
    this->scaling = scaling;
    destRect.w = srcRect.w * scaling;
    destRect.h = srcRect.h * scaling;
}

void    Sprite::setDestRect(int x, int y){destRect.x =x; destRect.y = y;}

void    Sprite::setX(int x){destRect.x = x;}

void    Sprite::setY(int y){destRect.y = y;}

void    Sprite::moveX(int x){destRect.x += x;}

void    Sprite::moveY(int y){destRect.y += y;}

int     Sprite::getScaling(){return scaling;}

void    Sprite::setScaling(int scaling){this->scaling = scaling;}

double  Sprite::getAngle(){return angleOfRotation;}

void    Sprite::setAngle(double angle){angleOfRotation = angle;}

SDL_Point Sprite::getCenter(){return *centerOfRotation;}

void    Sprite::setCenter(int x , int y){centerOfRotation->x = x; centerOfRotation->y = y;}

SDL_RendererFlip Sprite::getFlip(){return flip;}

void    Sprite::setFlip(SDL_RendererFlip flip){this->flip = flip;}

void Sprite::draw()
{
    if(texture!= 0 && SDL!= 0)
    {
        destRect.w = srcRect.w * scaling;
        destRect.h = srcRect.h * scaling;
        SDL_RenderCopyEx(SDL->getRenderer(), texture, &srcRect, &destRect, angleOfRotation, centerOfRotation, flip);
    }
}






