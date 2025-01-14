#include "..\HeaderFiles\BinaryTreeNode.h"

BinaryTreeNode::BinaryTreeNode(int value)
    : Data(value), Left(nullptr), Right(nullptr) {}


BinaryTreeNode::~BinaryTreeNode() 
{
    if (Left != nullptr)
    {
        delete Left;
    }

    if (Right != nullptr)
    {
        delete Right;
    }
}
