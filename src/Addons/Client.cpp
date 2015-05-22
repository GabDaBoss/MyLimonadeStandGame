#include "include/Client.h"

Client::Client(Sprite* spriteSheet)
{
    //ctor

    std::srand(std::time(0));
    this->spriteSheet = spriteSheet;
    clientSprite = 0;
    talk = spriteSheet->makeSprite({83,23,32,27},80,80,10);
    hand = new Button(spriteSheet->makeSprite({83,0,9,11},400,300,10));
}

Client::~Client()
{

}
bool Client::init()
{
    int random = rand()*SDL_GetTicks()%6;
    swing = 1;
    SDL_Rect rect;
    int x;
    int y;
    int scale;
    SDL_RendererFlip flip;
    willStop = false;
    timeWaiting = 0;
    buyingDialog = false;
    isHeStopped = false;
    transactionDone = false;
    moneyGiven = false;
    limonadeReceived = false;
    switch(random)
    {
        case 0: rect ={0,0,20,30}; break;
        case 1: rect ={40,0,20,30}; break;
        case 2: rect ={0,30,20,30}; break;
        case 3: rect ={40,30,20,30}; break;
        case 4: rect ={0,60,20,30};break;
        case 5: rect ={40,60,20,30};break;
        default:rect ={0,0,20,30}; break;
    }
    random = rand()*SDL_GetTicks()%4;
    switch(random)
    {
        case 0: isInBackground = true;
                scale = BACKGROUND_SIZE;
                x = -rect.w * scale;
                y = BACKGROUND_PATH;
                direction = RIGHT;
                facing = RIGHT;
                flip = SDL_FLIP_NONE;
                stoppingPoint = 800; break;
        case 1: isInBackground = false;
                scale = FRONT_SIZE;
                x = -rect.w * scale;
                y = FRONT_PATH;
                direction = RIGHT;
                facing = RIGHT;
                flip = SDL_FLIP_NONE;
                stoppingPoint = 800; break;
        case 2: isInBackground = true;
                scale = BACKGROUND_SIZE;
                x = 800;
                y =BACKGROUND_PATH;
                direction = LEFT;
                facing = LEFT;
                flip = SDL_FLIP_HORIZONTAL;
                stoppingPoint = -rect.w * scale; break;
        case 3: isInBackground = false;
                scale = FRONT_SIZE;
                x = 800;
                y = FRONT_PATH;
                direction = LEFT;
                facing = LEFT;
                flip = SDL_FLIP_HORIZONTAL;
                stoppingPoint = -rect.w * scale; break;
    }
    if(!isInBackground)
    {
        random = rand()*SDL_GetTicks()%2;
        switch(random)
        {
            case 0: willStop = true; break;
            case 1: willStop = false; break;
            default:willStop = false;
        }
    }
    if(clientSprite == 0)
    {
        clientSprite = spriteSheet->makeSprite(rect,x,y,scale);
        originalRect = rect;
    }
    else
    {
        clientSprite->setSrcRect(rect);
        clientSprite->setDestRect(x,y,scale);
        originalRect = rect;
    }
    clientSprite->setFlip(flip);
    timeLeftForStart = rand()*SDL_GetTicks()%5000;
    timeOfStart = SDL_GetTicks() + timeLeftForStart;
    waitingForStart = true;
    positionInWaitingList = 0;
    return willStop;
}
void Client::draw()
{
    clientSprite->draw();
    if(buyingDialog)
    {
        talk->draw();
        hand->draw();
    }
}

bool Client::getWaitingForStart(){return waitingForStart;}
bool Client::getWillStop(){return willStop;}
bool Client::getIsInBackground(){return isInBackground;}
bool Client::getTransactionDone()
{
    transactionDone = (moneyGiven && limonadeReceived);
    return transactionDone;
}
Button* Client::getHandButton(){return hand;}
bool Client::getTimeLeftForStart(){return timeOfStart < SDL_GetTicks();}
bool Client::getIsHeStopped(){return isHeStopped;}
int Client::getDirection(){return direction;}
int Client::getStoppingPoint(){return stoppingPoint;}
Sprite* Client::getSprite(){return clientSprite;}
int Client::getSwing(){return swing;}
SDL_Rect Client::getOriginalRect(){return originalRect;}
bool Client::getBuyingDialog(){return buyingDialog;}
int Client::getPosition(){return positionInWaitingList;}
int Client::getFacing(){return facing;}
Uint32 Client::getWaitingTime()
{
    if(isHeStopped)
        timeWaiting = SDL_GetTicks() - timeStop;
    else timeWaiting = 0;
    return timeWaiting;
}

void Client::setWaitingForStart(bool status){waitingForStart = status;}
void Client::setMoneyGiven(bool status) {moneyGiven = status;}
void Client::setLimonadeReceived(bool status){limonadeReceived = status;}
void Client::setIsHeStopped(bool st){isHeStopped = st;}
void Client::setSwing(int a){swing = a;}
void Client::setStoppingPoint(int a)
{
    if(positionInWaitingList != 0) stoppingPoint = 400 - clientSprite->getDestRect().w/2 - (positionInWaitingList-1)*(clientSprite->getDestRect().w +10);
    else stoppingPoint = a;
}
void Client::setBuyingDialog(bool status)
{
    buyingDialog = status;
    if(status)
    {
        hand->setStatus(true);
    }
    else
        hand->setStatus(false);
}
void Client::setFacing(int facing)
{
    if(facing == RIGHT)
    {
        clientSprite->setFlip(SDL_FLIP_NONE);
    }
    else clientSprite->setFlip(SDL_FLIP_HORIZONTAL);
}
void Client::setTimeOfStop(Uint32 time)
{
    if(time!= 0)timeStop = time;
    else timeStop = SDL_GetTicks();
}
void Client::setPositionInList(int pos)
{
    positionInWaitingList = pos;
    if(stoppingPoint != 400 - clientSprite->getDestRect().w/2 - (pos-1)*(SPACE_IN_BETWEEN) && pos != 0)
    {
        stoppingPoint = 400 - clientSprite->getDestRect().w/2 - (pos-1)*(SPACE_IN_BETWEEN);
        isHeStopped = false;
    }
    if(pos == 0)
    {
        if(direction == 1)
        {
            stoppingPoint = 800;
        }
        else
        {
            stoppingPoint = -clientSprite->getDestRect().w;
        }
    }
}
