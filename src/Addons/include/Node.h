#pragma once
#include "include/Client.h"
class Node
{
    friend class CLientList;
    public:
        Node();
        Node(Client* val);
        virtual ~Node();
        Client* getValue();
        void setValue(Client* client);
        Node* getNext();
        Node* getPrevious();
        void setNext(Node* next);
        void setPrevious(Node* previous);
        void setPosition(int pos);
    protected:
    private:
        Client* value; /* data, can be any data type, but use integer for easiness */
        Node* next; /* pointer to the next node */
        Node* previous; /* pointer to the previous node */
};
