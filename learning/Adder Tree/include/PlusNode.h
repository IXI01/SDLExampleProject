#ifndef PLUSNODE_H
#define PLUSNODE_H
#include "../include/Node.h"
#include "../include/PlusNode.h"



class PlusNode : public Node
{
  public:
    PlusNode(Node *left, Node *right);
    virtual ~PlusNode();
    virtual int calculate();

  protected:
  private:
    Node *leftChild;
    Node *rightChild;


};

#endif // PLUSNODE_H
