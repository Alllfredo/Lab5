#include "..\HeaderFiles\BinaryTree.h"
#include "..\HeaderFiles\BinaryTreeNode.h"
#include <exception>

BinaryTree::BinaryTree() : _node(nullptr) {}


BinaryTree::~BinaryTree()
{
	FreeTree(_node);
	_node = nullptr;
}

BinaryTreeNode* BinaryTree:: GetNode()
{
	return _node;
}

void BinaryTree::FreeTree(BinaryTreeNode* node) 
{
	if (node == nullptr)
	{
		return;
	}

	FreeTree(node->Left);
	FreeTree(node->Right);
	delete node;
}

BinaryTreeNode* BinaryTree::Find(BinaryTreeNode* node, int value) 
{
	if (node == nullptr)
	{
		return nullptr;
	}
	if (node->Data == value)
	{
		return node;
	}
	if (node->Data > value)
	{
		return Find(node->Left, value);
	}
	else
	{
		return Find(node->Right, value);
	}


}

BinaryTreeNode* BinaryTree::FindMin(BinaryTreeNode* node)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	while (node->Left != nullptr)
	{
		node = node->Left;
	}

	return node;
}


BinaryTreeNode* BinaryTree::FindMax(BinaryTreeNode* node)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	while (node->Right != nullptr)
	{
		node = node->Right;
	}

	return node;
}

void BinaryTree :: RecursiveAdd(BinaryTreeNode*& node, const int value)
{
	if(node == nullptr)
	{
		node = new BinaryTreeNode(value);
		return;
	}

	if(node->Data > value)
	{
		return RecursiveAdd(node->Left, value);
	}
	else
	{
		return RecursiveAdd(node->Right, value);
	}
}


void BinaryTree::Add(int value)
{
		RecursiveAdd(_node, value);
}


void BinaryTree::Remove(int value)
{
	RecursiveRemove(_node, value);
}


void BinaryTree::RecursiveRemove(BinaryTreeNode*& node, const int value)
{
	if (node == nullptr)
	{
		return;
	}
	if (value < node->Data)
	{
		RecursiveRemove(node->Left, value);
	}
	else if (value > node->Data)
	{
		RecursiveRemove(node->Right, value);
	}
	else
	{
		if (node->Left == nullptr && node->Right == nullptr)
		{
			delete node;
			node = nullptr;
		}
		else if (node->Left == nullptr)
		{
			BinaryTreeNode* temp = node;
			node = node->Right;
			temp->Right = nullptr;
			delete temp;
		}
		else if (node->Right == nullptr)
		{
			BinaryTreeNode* temp = node;
			node = node->Left;
			temp->Left = nullptr;
			delete temp; 
		}
		else
		{
			BinaryTreeNode* minNode = FindMin(node->Right);
			node->Data = minNode->Data;
			RecursiveRemove(node->Right, minNode->Data);
		}
	}
}

