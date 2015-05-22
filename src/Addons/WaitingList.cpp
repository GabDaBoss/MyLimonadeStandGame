#include "include/WaitingList.h"
WaitingList::WaitingList(void)
{

}
WaitingList::~WaitingList()
{

}
void WaitingList::removeTail()
{
    int pos = 0;
    Node* p = _pTail;
    if(p->getNext() == 0)
    {
        _pTail = 0;
        _pHead = 0;
    }
    else
    {
        _pTail = p->getNext();
        _pTail->setPrevious(0);
    }
    p->setPosition(pos);
    for(Node* p = _pTail; p != 0; p = p->getNext())
    {
        pos++;
        p->setPosition(pos);
    }
}
void WaitingList::add(Client* client)
{
    std::cout << "adding a client to the waitingList" << std::endl;
    int pos = 0;
    Node* p = _pHead;
    _pHead = new Node(client);
    if(_pTail == 0) _pTail = _pHead;
    if(p != 0)
    {
        p->setNext(_pHead);
        _pHead->setPrevious(p);
    }
    for(Node* p = _pTail; p != 0; p = p->getNext())
    {
        pos++;
    }
    _pHead->setPosition(pos);
}

