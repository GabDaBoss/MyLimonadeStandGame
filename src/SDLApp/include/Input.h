#pragma once
#include <SDL2/SDL.h>
#include "Button.h"
#include <iostream>
class Input
{
public:
	Input();
	~Input();
	bool isKeyPress(SDL_Keycode key);
	bool isButtonPress(Button* button);
    int update();
    SDL_Event* getEvent();
private:
	SDL_Event event;
	SDL_Keycode key;
};
