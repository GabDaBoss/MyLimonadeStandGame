#include "include/Input.h"

Input::Input()
{
    update();

}
Input::~Input()
{

}
int Input::update()
{
    int a;
    a = SDL_PollEvent(&event);
    return a;
}
SDL_Event* Input::getEvent()
{
    return &event;
}

bool Input::isKeyPress(SDL_Keycode key)
{

    if(event.type == SDL_KEYUP & event.key.keysym.sym == key)
        return true;
    else false;
}
bool Input::isButtonPress(Button* button)
{
    if(button->getStatus())
    {
        if( event.type == SDL_MOUSEBUTTONUP &
            event.button.button == SDL_BUTTON_LEFT &
            event.button.x > button->getRect().x &
            event.button.x < (button->getRect().x + button->getRect().w) &
            event.button.y > button->getRect().y &
            event.button.y < (button->getRect().y + button->getRect().h))
            {std::cout << "button press"<< std::endl;return true;}
        else return false;
    }
    else return false;

}
