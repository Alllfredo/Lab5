#include "..\\HeaderFiles\TreapNode.h"

TreapNode::TreapNode(int key, int priority)
    : Key(key), Priority(priority), Left(nullptr), Right(nullptr) 
{
}


TreapNode::~TreapNode()
{
    delete Left;
    delete Right;
}
