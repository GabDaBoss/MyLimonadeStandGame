#include "include/Node.h"
Node::Node(void)
{
    next = 0;
    value = 0;
    previous = 0;
}
Node::Node(Client* val)
{
    value = val;
    next = 0;
    previous = 0;
}
Node::~Node()
{
    //dtor
    //delete _value;
}
Client* Node::getValue() { return value; }
void Node::setValue(Client* client) {value = client;}

Node* Node::getNext() { return next;}
Node* Node::getPrevious(){return previous;}
void Node::setNext(Node* next){this->next = next;}
void Node::setPrevious(Node* previous){this->previous = previous;}
void Node::setPosition(int pos){value->setPositionInList(pos);}





