#pragma once
#include "include/SDLApp.h"


class Stand
{
    public:
        Stand(int sugarAmount = 0,
                    int iceAmount = 0,
                    int cupAmount = 0,
                    int lemonAmount = 0,
                    int moneyAmount = 0,
                    int pricePerCup = 0,
                    int sugarPerCup = 0,
                    int icePerCup = 0,
                    int lemonPerCup =0,
                    SDLSetup* SDL = 0
                    );
        virtual ~Stand();
        void draw();
        void sellLimonade();
        void makeLimonade();
        bool isOutOfStock();

        void buySugar(int amount);
        void buyIce(int amount);
        void buyCup(int amount);
        void buyLemon(int amount);

        void setSugarPerCup(int amount);
        void setIcePerCup(int amount);
        void setLemonPerCup(int amount);
        void setPricePerCup(int amount);

        int getIceAmount();
        int getCupAmount();
        int getSugarAmount();
        int getLemonAmount();
        int getMoneyAmount();

        Button* getCupButton(int i);
        Button* getPitcherButton();

    protected:
    private:
        int sugarAmount;
        int iceAmount;
        int cupAmount;
        int lemonAmount;
        int moneyAmount;
        int pricePerCup;
        int sugarPerCup;
        int icePerCup;
        int lemonPerCup;
        static int sugarPrice;
        static int cupPrice;
        static int icePrice;
        static int lemonPrice;
        SDL_Texture* spriteSheet;
        Sprite* stand;
        Sprite* cups;
        Sprite* pitcher;

        Button*     pitcherButton;
        Button*     cupButton[5];
        SDLSetup* SDL;
        bool outOfStock;
};

