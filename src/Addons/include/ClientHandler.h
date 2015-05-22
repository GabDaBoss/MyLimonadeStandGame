#include "include/SDLSetup.h"
#include "WaitingList.h"
#include <ctime>
#include <cstdlib>

class ClientHandler
{
    public:
        ClientHandler(SDLSetup* SDL);
        virtual ~ClientHandler();
        void addClient();
        void updateAll();
        void draw();
        Client* getFirstClient();
        bool transaction(Client* client);
    protected:
        const int MAXIMUM_WAITING_TIME = 10000;
        void addToList(Client* client);
        void removeTail();
        void update(Client* client);
        void walk(Client* client);
        void animate(Client* client, bool status);
        void swing(Client* client, bool status);


        WaitingList* waitingList;
        ClientList* allTheClient;
        Sprite* clientSheet;
    private:
};
