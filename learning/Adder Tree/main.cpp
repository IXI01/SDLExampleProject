#include <iostream>
#include "include/Node.h"
#include "include/PlusNode.h"
#include "include/ValueNode.h"

using namespace std;

int main()
{
    Node *pnode = new PlusNode(new PlusNode(new ValueNode(6), new PlusNode(new ValueNode(5), new ValueNode(1))), new ValueNode(6));
    std::cout << pnode->calculate() << std::endl;
    return 0;
}
