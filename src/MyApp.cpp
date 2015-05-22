#include "MyApp.h"

MyApp::MyApp()
{
    std::cout << "derp" << std::endl;
    pastTime = 0;
    actualTime = SDL_GetTicks();

    pause = false;

    stand = new Stand(10,10,10,10,200,5,1,1,1, SDL);

    menu = new Menu(SDL, stand);
    clients = new ClientHandler(SDL);
    nbOfClients = 0;

}

MyApp::~MyApp()
{
    //delete the clientList

    delete menu;

    delete stand;


}
void MyApp::eventHandling()
{
    if(in->isKeyPress(SDLK_ESCAPE))
        quit = true;

    else if(in->isButtonPress(menu->getInventoryButton()))
    {
        if(!pause)pause = true;
        else pause = false;
        menu->flipStatus();
    }
    else if(in->isButtonPress(menu->getBuyCupButton()))
        stand->buyCup(10);
    else if(in->isButtonPress(menu->getBuyIceButton()))
        stand->buyIce(10);
    else if(in->isButtonPress(menu->getBuyLemonButton()))
        stand->buyLemon(10);
    else if(in->isButtonPress(menu->getBuySugarButton()))
        stand->buySugar(10);

    if(clients->getFirstClient() != 0)
    {
        Client* customer = clients->getFirstClient();
        for(int a = 0; a < 5; a++)
        {
            if(in->isButtonPress(stand->getCupButton(a)))
            {
                if(stand->getCupButton(a)->getStatus())
                {
                    wichCupSelected = a;
                    clients->getFirstClient()->setLimonadeReceived(true);
                }
            }
        }
        if(in->isButtonPress(clients->getFirstClient()->getHandButton()) && customer->getBuyingDialog())
        {
            customer->setMoneyGiven(true);
        }
        if(clients->transaction(customer))
        {
            stand->sellLimonade();
            stand->getCupButton(wichCupSelected)->setStatus(false);
        }
    }

    if( !stand->getCupButton(0)->getStatus() &&
        !stand->getCupButton(1)->getStatus() &&
        !stand->getCupButton(2)->getStatus() &&
        !stand->getCupButton(3)->getStatus() &&
        !stand->getCupButton(4)->getStatus()    )
    {
        if(in->isButtonPress(stand->getPitcherButton()) && !stand->isOutOfStock())
        {
            stand->makeLimonade();
            for(int i = 0; i < 5; i++)
            {
                stand->getCupButton(i)->setStatus(true);
            }
        }
    }
    SDLApp::eventHandling();
}
void MyApp::eventHandler()
{
    while(in->update())
    {
        eventHandling();
    }
}
void MyApp::rendering()
{

    SDLApp::rendering();
    clients->draw();

    stand->draw();
    menu->draw();

}
void MyApp::logic()
{
    actualTime = SDL_GetTicks();
    runtime = actualTime - pastTime;

    if(runtime > 5)
    {
        if(nbOfClients < MAX_CLIENTS)
        {

            clients->addClient();
            nbOfClients++;
        }
        clients->updateAll();
        pastTime = actualTime;
    }
}
bool MyApp::run()
{
    eventHandler();
    logic();

    SDL->start();
    rendering();
    SDL->finish();
    return !quit;
}
