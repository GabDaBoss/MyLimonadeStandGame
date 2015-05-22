#include "include/ClientHandler.h"


ClientHandler::ClientHandler(SDLSetup* SDL)
{
    std::cout << "derp" << std::endl;
    waitingList = new WaitingList();
    allTheClient = new ClientList();
    clientSheet = new Sprite(IMG_LoadTexture(SDL->getRenderer(), "img/clientSpriteSheet.png"), SDL);

}
ClientHandler::~ClientHandler()
{

}
void ClientHandler::addClient()
{

    Client* client = new Client(clientSheet);
    //if(client->init()) {addToList(client); client->setTimeOfStop(0);}
    client->init();
    allTheClient->add(client);
}
void ClientHandler::swing(Client* client, bool status)
{
    if(status)
    {
        if(client->getSprite()->getAngle() < 30 && client->getSprite()->getAngle() > -30)
            client->getSprite()->setAngle(client->getSprite()->getAngle() + client->getSwing());
        else
        {
            if(client->getSwing() == 1) client->setSwing(-1);
            else client->setSwing(1);
            client->getSprite()->setAngle(client->getSprite()->getAngle() + client->getSwing());
        }
    }
    else client->getSprite()->setAngle(0);
}

void ClientHandler::animate(Client* client, bool status)
{
    if(status)client->getSprite()->setSrcRect({client->getOriginalRect().x + client->getOriginalRect().w, client->getOriginalRect().y, client->getOriginalRect().w, client->getOriginalRect().h});
    else client->getSprite()->setSrcRect(client->getOriginalRect());
}

void ClientHandler::walk(Client* client)
{
    //std::cout << client->getStoppingPoint() << std::endl;
    if(!client->getIsHeStopped())
    {
        if(client->getSprite()->getDestRect().x > client->getStoppingPoint())
        {
            client->setFacing(client->LEFT);
            client->getSprite()->setX(client->getSprite()->getDestRect().x -1);
        }
        else if(client->getSprite()->getDestRect().x < client->getStoppingPoint())
        {
            client->setFacing(client->RIGHT);
            client->getSprite()->setX(client->getSprite()->getDestRect().x + 1);
        }
        else if(client->getSprite()->getDestRect().x == client->getStoppingPoint())
        {
            client->setIsHeStopped(true);
        }
    }
    swing(client, !client->getIsHeStopped());
}
void ClientHandler::update(Client* client)
{
    if(client->getWaitingForStart())
    {
        //sstd::cout <<client->getTimeLeftForStart()<<std::endl;
        if(client->getTimeLeftForStart())
        {
            if(!client->getIsInBackground() && client->getWillStop())
            {
                addToList(client);
                client->setTimeOfStop(0);
            }
            client->setWaitingForStart(false);
        }
    }
    else
    {
        walk(client);
        if(client->getIsHeStopped())
        {
            if(client->getSprite()->getDestRect().x == 800 || client->getSprite()->getDestRect().x == -client->getSprite()->getDestRect().w)
            {
                client->init();
                //if(client->init()) {addToList(client); client->setTimeOfStop(0);}
            }
            if(!client->getTransactionDone() && client->getPosition() == 1 && !client->getIsInBackground() && client->getIsHeStopped())
            {
                client->setBuyingDialog(true);
            }
            //std::cout << client->getWaitingTime() << std::endl;
            if(client->getTransactionDone() || client->getWaitingTime()>= MAXIMUM_WAITING_TIME)
            {
                removeTail();

                client->setIsHeStopped(false);
                client->setBuyingDialog(false);
                client->setMoneyGiven(false);
                client->setLimonadeReceived(false);
                std::cout << "Transaction done" <<std::endl;
            }
        }
    }
}
void ClientHandler::addToList(Client* client)
{
    waitingList->add(client);
}
void ClientHandler::removeTail()
{
    std::cout << "removing client from the waiting list" << std::endl;
    waitingList->removeTail();
}
void ClientHandler::draw()
{
    for(Node* p = allTheClient->getTail(); p != 0; p = p->getNext())
    {
        if(p->getValue()->getIsInBackground())p->getValue()->draw();
    }
    for(Node* p = allTheClient->getTail(); p != 0; p = p->getNext())
    {
        if(!p->getValue()->getIsInBackground() && p->getValue()->getPosition() == 0)p->getValue()->draw();
    }
    for(Node* p = waitingList->getHead(); p!=0; p = p->getPrevious())
    {
        p->getValue()->draw();

    }
}
void ClientHandler::updateAll()
{
    for(Node* p = allTheClient->getTail(); p != 0; p = p->getNext())
    {
        update(p->getValue());
    }
}
Client* ClientHandler::getFirstClient()
{
    Client* client = 0;
    if(waitingList->getTail() != 0)
    {
        client = waitingList->getTail()->getValue();
    }
    return client;
}
bool ClientHandler::transaction(Client* client)
{
    bool status =  client->getTransactionDone();
    return status;
}
