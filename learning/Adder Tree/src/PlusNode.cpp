#include "../include/PlusNode.h"


PlusNode::PlusNode(Node *left, Node *right)
{
    leftChild=left;
    rightChild=right;

}

PlusNode::~PlusNode()
{
    //dtor
}


int PlusNode::calculate()
{

    if (leftChild != 0 && rightChild ==0)
        return leftChild->calculate();
    if (leftChild==0 && rightChild != 0)
        return rightChild->calculate();
    if (leftChild==0 && rightChild==0)
        return 0;

    return leftChild->calculate()+rightChild->calculate();
}
