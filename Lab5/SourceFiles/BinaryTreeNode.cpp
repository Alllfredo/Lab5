#include "..\HeaderFiles\BinaryTreeNode.h"

BinaryTreeNode::BinaryTreeNode(int value)
    : Data(value), Left(nullptr), Right(nullptr) {}


BinaryTreeNode::~BinaryTreeNode() 
{
    delete Left;
    delete Right;
}
