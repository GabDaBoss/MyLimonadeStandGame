#include "include/Button.h"

Button::Button(Sprite* sprite, bool status)
{
    //ctor
    this->sprite = sprite;
    this->status = status;
}

Button::~Button()
{
    //dtor
    delete sprite;
}
void Button::flipStatus()
{
    if(status == true) status = false;
    else status = true;
}

bool Button::getStatus() {return status;}
void Button::setStatus(bool status) {this->status = status;}
SDL_Rect Button::getRect() {return sprite->getDestRect();}
SDL_Rect Button::setRect(SDL_Rect rect){sprite->setDestRect(rect);}
void Button::draw(){if(status)sprite->draw();}
