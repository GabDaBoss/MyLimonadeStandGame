#include "include/Text.h"

Text::Text(TTF_Font *font, int x, int y, SDL_Color color, SDLSetup* SDL)
{
    //ctor
    if(!font) {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
        // handle error
        std::cout <<"FUCK" << std::endl;
    }
    this->SDL = SDL;
    text = 0;
    str = " ";
    rect.x = x;
    rect.y = y;
    this->font = font;
    this->color = color;
    update();
}

Text::~Text()
{
    //dtor
    TTF_CloseFont(font);
    font=NULL;
}
void Text::draw()
{SDL_RenderCopy(SDL->getRenderer(), text, NULL, &rect);}
void Text::draw(int x, int y, int w, int h)
{
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = w;
    r.h = h;
    SDL_RenderCopy(SDL->getRenderer(), text, NULL, &r);
}
void Text::setString(std::string s)
{
    str = s;
    update();
}

void Text::setString(int n)
{
    std::ostringstream ss;
    ss << n;
    str = ss.str();
    //str = std::to_string(n);
    update();
}

void Text::update()
{

    SDL_Surface *text_surface = TTF_RenderText_Solid(font,str.c_str(),color);

    if(!text_surface) std::cout <<"FUCK" << std::endl;
    rect.w = text_surface->w;
    rect.h = text_surface->h;
    //rect.w = 100;
    //rect.h = 40;
    SDL_DestroyTexture(text);
    text = SDL_CreateTextureFromSurface(SDL->getRenderer(), text_surface);
    if(!text) std::cout <<"FUCK" << std::endl;
    //perhaps we can reuse it, but I assume not for simplicity.
    SDL_FreeSurface(text_surface);
}
SDL_Rect Text::getRect(){return rect;}
