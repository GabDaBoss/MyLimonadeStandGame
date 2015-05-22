#include "include/SpriteHandler.h"


SpriteHandler::SpriteHandler(Sprite* sprite)
{
    mainSprite = sprite;
}
SpriteHandler::~SpriteHandler()
{
    //dtor
    mainSprite = 0;
}
void SpriteHandler::moveX(int a){mainSprite->moveX(a);}
void SpriteHandler::moveY(int a){mainSprite->moveY(a);}
void SpriteHandler::grow(int a){mainSprite->setScaling(mainSprite->getScaling()+a);}
void SpriteHandler::reduce(int a){mainSprite->setScaling(mainSprite->getScaling()-a);}

void SpriteHandler::draw()
{
    mainSprite->draw();
}
