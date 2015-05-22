#pragma once
#include "Sprite.h"

class SpriteHandler
{
    public:
        SpriteHandler();
        SpriteHandler(Sprite* sprite);
        virtual ~SpriteHandler();
        void draw();
        void moveX(int a = 1);
        void moveY(int a = 1);
        void grow(int a = 1);
        void reduce(int a = 1);
    protected:
        Sprite* mainSprite;
    private:
};


