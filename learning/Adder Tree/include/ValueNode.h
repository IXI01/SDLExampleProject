#ifndef VALUENODE_H
#define VALUENODE_H
#include "../include/Node.h"
#include "../include/PlusNode.h"


class ValueNode : public Node
{
    public:
        ValueNode(int value);
        virtual ~ValueNode();
        virtual int calculate();
    protected:
    private:
        int new_value;
};

#endif // VALUENODE_H
