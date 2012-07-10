#include <iostream>
#include "include/Element.h"

using namespace std;

int main()
{
    Element *e = new Element(5);
    e->next = new Element(6);
    e->next->next = new Element(7);
    e->next->next->next = new Element(8);
    e->printList(e);

    delete e;







    return 0;
}
