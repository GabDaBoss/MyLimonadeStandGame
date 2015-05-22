#pragma once
#include "include/SDLApp.h"
#include <ctime>
#include <cstdlib>

class Client
{
    public:
        const int LEFT = -1;
        const int RIGHT = 1;

        Client(Sprite* spriteSheet);
        virtual ~Client();
        bool init();
        void draw();

        int     getDirection();
        int     getStoppingPoint();
        bool    getIsHeStopped();
        void    setIsHeStopped(bool st);
        bool  getTimeLeftForStart();
        bool    getIsInBackground();
        bool    getBuyingDialog();
        bool    getTransactionDone();
        int     getPosition();
        bool    getWaitingForStart();
        Uint32  getWaitingTime();
        SDL_Rect getOriginalRect();
        int     getSwing();
        Button* getHandButton();
        Sprite* getSprite();
        int getFacing();
        bool getWillStop();

        void setWaitingForStart(bool status);
        void setFacing(int facing);
        void setTimeOfStop(Uint32 time);
        void setStoppingPoint(int a = 0);
        void setSwing(int a);
        void setMoneyGiven(bool status);
        void setLimonadeReceived(bool status);
        void setPositionInList(int pos);
        void setBuyingDialog(bool status);
    protected:
    private:
        const int FRONT_SIZE = 10;
        const int BACKGROUND_SIZE = 5;
        const int FRONT_PATH = 280;
        const int BACKGROUND_PATH = 320;
        const int SPACE_IN_BETWEEN = 50;

        Sprite* spriteSheet;
        Sprite* clientSprite;
        SDL_Rect originalRect;
        Sprite* talk;
        Button* hand;
        bool isInBackground;
        bool isHeStopped;
        bool willStop;
        bool waitingForStart;
        bool buyingDialog;
        bool moneyGiven;
        bool limonadeReceived;
        bool transactionDone;
        int positionInWaitingList;
        int swing;
        int stoppingPoint;
        int direction;
        int facing;

        Uint32 timeOfStart;
        Uint32 timeLeftForStart;
        Uint32 timeWaiting;
        Uint32 timeStop;


};


