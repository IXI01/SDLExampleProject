#include "../include/ValueNode.h"

ValueNode::ValueNode(int value)
{
    new_value=value;
}

ValueNode::~ValueNode()
{
    //dtor
}

int ValueNode::calculate()
{
    return new_value;
}
