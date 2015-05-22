#include "include/ClientList.h"

ClientList::ClientList()
{
    _pHead = _pTail = 0;
}
ClientList::ClientList(Client* client)
{
    _pHead = new Node(client);
    _pTail = _pHead;
}
ClientList::~ClientList()
{
    for(Node* p = _pTail; p != 0; p = p->getNext())
    {
        delete p;
    }
}
void ClientList::removeTail()
{
    Node* p = _pTail;
    if(p->getNext() == 0)
    {
        _pTail = 0;
    }
    else
    {
        _pTail = p->getNext();
        _pTail->setPrevious(0);
    }
}
void ClientList::add(Client* client)
{

    Node* p = _pHead;
    _pHead = new Node(client);
    if(_pTail == 0) _pTail = _pHead;
    if(p != 0)
    {
        p->setNext(_pHead);
        _pHead->setPrevious(p);
    }
}
Node* ClientList::getHead()
{
    return _pHead;
}
Node* ClientList::getTail()
{
    return _pTail;
}

