#pragma once
#include "include/ClientList.h"

class WaitingList : public ClientList
{
    public:
        WaitingList(void);
        virtual ~WaitingList();
        void removeTail();
        void add(Client* client);
};
