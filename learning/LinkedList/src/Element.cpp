#include "../include/Element.h"
#include <iostream>

Element::Element(int new_value)
{
    value=new_value;
    next=NULL;
}

Element::~Element()
{
    if(next!=NULL)
        delete next;
}

void Element::printList(Element *p)
{

    std::cout << p->value;
    if(p->next!=NULL)
        printList(p->next);

}
