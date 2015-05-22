#pragma once

#include <SDLApp/include/SDLApp.h>
#include <Addons/include/ClientHandler.h>
#include <Addons/include/Menu.h>
#include <Addons/include/Stand.h>



class MyApp : public SDLApp
{
    public:
        MyApp();
        virtual ~MyApp();
        bool run();
    protected:
        const int MAX_CLIENTS = 5;
        void eventHandler();
        void eventHandling();
        void rendering();
        void logic();
        int wichCupSelected;
        Uint32 actualTime;
        Uint32 pastTime;
        Uint32 runtime;
        bool pause;
        ClientHandler* clients;
        int nbOfClients;
        Stand* stand;
        Menu* menu;
        //Client* client[2];

    private:
};


