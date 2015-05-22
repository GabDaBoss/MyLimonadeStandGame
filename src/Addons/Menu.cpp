#include "include/Menu.h"


Menu::Menu(SDLSetup* SDL, Stand* stand)
{
    //ctor
    this->stand = stand;
    buttonSheet = IMG_LoadTexture(SDL->getRenderer(), "img/buyIcons.png");
    iconSheet = IMG_LoadTexture(SDL->getRenderer(), "img/stockSpriteSheet.png");

    menu = new Sprite(IMG_LoadTexture(SDL->getRenderer(), "img/menu.png"), SDL, 100,100, 1);
    moneySprite = new Sprite(IMG_LoadTexture(SDL->getRenderer(), "img/money.png"), SDL,300, 0, 3);

    iceSprite = new Sprite(iconSheet, SDL,{0,0,50,50}, 600, 0, 1);

    cupSprite = new Sprite(iconSheet, SDL,{50,0,50,50}, 600,50, 1);

    lemonSprite = new Sprite(iconSheet, SDL,{100,0,50,50}, 600, 100, 1);

    sugarSprite = new Sprite(iconSheet, SDL,{150,0,50,50}, 600, 150, 1);


    inventoryButton = new Button(new Sprite(buttonSheet, SDL,{0,44,44,11}, 0,0, 3),true);
    buyIceButton    = new Button(new Sprite(buttonSheet, SDL,{0,0,44,11}, menu->getDestRect().x, menu->getDestRect().y +33, 3),false);
    buyCupButton    = new Button(new Sprite(buttonSheet, SDL,{0,11,44,11}, menu->getDestRect().x,menu->getDestRect().y +66, 3),false);
    buyLemonButton  = new Button(new Sprite(buttonSheet, SDL,{0,22,44,11}, menu->getDestRect().x,menu->getDestRect().y +99, 3),false);
    buySugarButton  = new Button(new Sprite(buttonSheet, SDL,{0,33,44,11}, menu->getDestRect().x,menu->getDestRect().y +132, 3),false);




    iceAmount = new Text(TTF_OpenFont("SFPixelate-Bold.ttf", 40), buyIceButton->getRect().x + buyIceButton->getRect().w, buyIceButton->getRect().y, {0, 0, 0}, SDL);
    cupAmount = new Text(TTF_OpenFont("SFPixelate-Bold.ttf", 40), buyCupButton->getRect().x + buyCupButton->getRect().w, buyCupButton->getRect().y, {0, 0, 0}, SDL);
    lemonAmount = new Text(TTF_OpenFont("SFPixelate-Bold.ttf", 40), buyLemonButton->getRect().x + buyLemonButton->getRect().w, buyLemonButton->getRect().y, {0, 0, 0}, SDL);
    sugarAmount = new Text(TTF_OpenFont("SFPixelate-Bold.ttf", 40), buySugarButton->getRect().x + buySugarButton->getRect().w, buySugarButton->getRect().y, {0, 0, 0}, SDL);
    moneyAmount = new Text(TTF_OpenFont("SFPixelate-Bold.ttf", 40), moneySprite->getDestRect().x + moneySprite->getDestRect().w, moneySprite->getDestRect().y, {0, 0, 0}, SDL);



    status = false;
}

Menu::~Menu()
{
    //dtor
}
Button* Menu::getInventoryButton() {return inventoryButton;}
Button* Menu::getBuyIceButton(){return buyIceButton;}
Button* Menu::getBuyCupButton(){return buyCupButton;}
Button* Menu::getBuyLemonButton(){return buyLemonButton;}
Button* Menu::getBuySugarButton(){return buySugarButton;}



void Menu::draw()
{
    iceAmount->setString(stand->getIceAmount());
    cupAmount->setString(stand->getCupAmount());
    lemonAmount->setString(stand->getLemonAmount());
    sugarAmount->setString(stand->getSugarAmount());
    moneyAmount->setString(stand->getMoneyAmount());

    iceAmount->draw(iceSprite->getDestRect().x + iceSprite->getDestRect().w, iceSprite->getDestRect().y, iceAmount->getRect().w, iceAmount->getRect().h);
    cupAmount->draw(cupSprite->getDestRect().x + cupSprite->getDestRect().w, cupSprite->getDestRect().y, cupAmount->getRect().w, cupAmount->getRect().h);
    lemonAmount->draw(lemonSprite->getDestRect().x + lemonSprite->getDestRect().w, lemonSprite->getDestRect().y, lemonAmount->getRect().w, lemonAmount->getRect().h);
    sugarAmount->draw(sugarSprite->getDestRect().x + sugarSprite->getDestRect().w, sugarSprite->getDestRect().y, sugarAmount->getRect().w, sugarAmount->getRect().h);
    moneyAmount->draw();

    moneySprite->draw();
    iceSprite->draw();
    lemonSprite->draw();
    cupSprite->draw();
    sugarSprite->draw();




    inventoryButton->draw();
    if(status)
    {

        iceSprite->draw();
        lemonSprite->draw();
        cupSprite->draw();
        sugarSprite->draw();
        menu->draw();
        iceAmount->draw();
        cupAmount->draw();
        lemonAmount->draw();
        sugarAmount->draw();
        buyIceButton->draw();
        buyCupButton->draw();
        buyLemonButton->draw();
        buySugarButton->draw();
    }

}
void Menu::flipStatus()
{
    if(status == true) status = false;
    else status = true;
    buyCupButton->setStatus(status);
    buyIceButton->setStatus(status);
    buyLemonButton->setStatus(status);
    buySugarButton->setStatus(status);
}
