#pragma once
#include "include/SDLApp.h"
#include "include/Stand.h"
class Menu
{
    public:
        Menu(SDLSetup* SDL, Stand* stand);
        virtual ~Menu();

        Button* getInventoryButton();
        Button* getBuyIceButton();
        Button* getBuyCupButton();
        Button* getBuyLemonButton();
        Button* getBuySugarButton();


        void draw();
        void flipStatus();

    protected:
    private:
        Stand* stand;
        SDLSetup* SDL;
        SDL_Texture* buttonSheet;
        SDL_Texture* iconSheet;
        Sprite*     moneySprite;
        Sprite*     menu;
        Sprite*     iceSprite;
        Sprite*     sugarSprite;
        Sprite*     lemonSprite;
        Sprite*     cupSprite;

        Button*     inventoryButton;
        Button*     buyIceButton;
        Button*     buyCupButton;
        Button*     buyLemonButton;
        Button*     buySugarButton;



        Text*       moneyAmount;
        Text*       iceAmount;
        Text*       cupAmount;
        Text*       lemonAmount;
        Text*       sugarAmount;
        bool status;
};


