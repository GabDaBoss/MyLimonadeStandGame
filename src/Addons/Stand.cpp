#include "include/Stand.h"

int Stand::cupPrice = 1;
int Stand::icePrice = 1;
int Stand::lemonPrice = 1;
int Stand::sugarPrice = 1;
Stand::Stand(int sugar,
                        int ice,
                        int cup,
                        int lemon,
                        int money,
                        int price,
                        int sugarPC,
                        int icePC,
                        int lemonPC,
                        SDLSetup* SDL)
{
    //ctor
    this->SDL = SDL;
    sugarAmount = sugar;
    iceAmount = ice;
    cupAmount = cup;
    lemonAmount = lemon;
    moneyAmount = money;
    stand = 0;
    sugarPerCup = sugarPC;
    icePerCup = icePC;
    lemonPerCup = lemonPC;
    pricePerCup = price;
    spriteSheet = IMG_LoadTexture(SDL->getRenderer(), "img/stand.png");
    stand = new Sprite(spriteSheet, SDL, {0,8,80,13},0,470,10);
    pitcher = new Sprite(spriteSheet, SDL, {0,0,9,8},670,500,10);
    pitcherButton   = new Button(pitcher, true);

    for(int i = 0; i < 5; i++)
    {
        cupButton[i] = new Button(new Sprite(spriteSheet, SDL, {9,0,8,8},100+ i*80,500,10), true);
    }
}

Stand::~Stand()
{
    //dtor
}
void Stand::draw()
{
    stand->draw();
    pitcherButton->draw();

    for(int i = 0; i < 5; i++)
    {
        cupButton[i]->draw();
    }
}
void Stand::makeLimonade()
{
    sugarAmount -= 5*sugarPerCup;
    lemonAmount -= 5*lemonPerCup;
    iceAmount -= 5*icePerCup;
    cupAmount -= 5;
}
void Stand::sellLimonade()
{
    //sugarAmount -= sugarPerCup;
    //lemonAmount -= lemonPerCup;
    //iceAmount -= icePerCup;
    //cupAmount --;
    moneyAmount += pricePerCup;
    std::cout << "cup sold" << std::endl;
}

void Stand::buySugar(int amount)
{
    sugarAmount += amount;
    moneyAmount -= amount*sugarPrice;
}

void Stand::buyIce(int amount)
{
    iceAmount += amount;
    moneyAmount -= amount*icePrice;
}

void Stand::buyCup(int amount)
{
    cupAmount += amount;
    moneyAmount -= amount*cupPrice;
}

void Stand::buyLemon(int amount)
{
    lemonAmount += amount;
    moneyAmount -= amount*lemonPrice;
}

void Stand::setSugarPerCup(int amount)
{
    sugarPerCup = amount;
}

void Stand::setIcePerCup(int amount)
{
    icePerCup  = amount;
}

void Stand::setLemonPerCup(int amount)
{
    lemonPerCup  = amount;
}

void Stand::setPricePerCup(int amount)
{
    pricePerCup  = amount;
}
int Stand::getIceAmount(){return iceAmount;}
int Stand::getCupAmount(){return cupAmount;}
int Stand::getSugarAmount(){return sugarAmount;}
int Stand::getLemonAmount(){return lemonAmount;}
int Stand::getMoneyAmount(){return moneyAmount;}
Button* Stand::getCupButton(int i){if(i < 5)return cupButton[i];}
Button* Stand::getPitcherButton(){return pitcherButton;}
bool Stand::isOutOfStock()
{
    if(cupAmount == 0 || lemonAmount < lemonPerCup || sugarAmount < sugarPerCup || iceAmount < icePerCup)
        return true;

    else return false;
}
