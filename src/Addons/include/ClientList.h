#pragma once
#include "include/Node.h"


class ClientList
{
    public:
        /* Constructors with No Arguments */
        ClientList(void);
        /* Constructors with a given value of a list node */
        ClientList(Client* client);

        virtual ~ClientList();
        void removeTail();
        void add(Client* client);
        Node* getHead();
        Node* getTail();
    protected:
         /* pointer of head node */
        Node *_pHead;
        /* pointer of tail node */
        Node *_pTail;
    private:
};


