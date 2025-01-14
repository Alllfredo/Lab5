#include "..\\HeaderFiles\Treap.h"

Treap::Treap() 
{
	_node = nullptr;
}

Treap::~Treap()
{
	Clear(_node);
	_node = nullptr;
}

TreapNode* Treap::GetNode()
{
	return _node;
}

void Treap::Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right)
{
	if (node == nullptr)
	{
		left = right = nullptr;
	}
	else if (node->Key <= key)
	{
		Split(node->Right, key, node->Right, right);
		left = node;
	}
	else
	{
		Split(node->Left, key, left, node->Left);
		right = node;
	}

}

TreapNode* Treap::Merge(TreapNode* left, TreapNode* right)
{
	if (left == nullptr || right == nullptr)
	{
		return left == nullptr ? right : left;
	}
	if (left->Priority > right->Priority)
	{
		left->Right = Merge(left->Right, right);
		return left;
	}

	right->Left = Merge(left, right->Left);
	return right;
}

void Treap::Insert(int key, int priority)
{
	TreapNode* newNode = new TreapNode{ key, priority };
	TreapNode* left = nullptr;
	TreapNode* right = nullptr;

	Split(_node, key, left, right);
	left = Merge(left, newNode);
	_node = Merge(left, right);
}

void Treap::OptimizedInsert(int key, int priority)
{
	TreapNode* newNode = new TreapNode{ key, priority };
	TreapNode* current = _node;
	TreapNode* parent = nullptr;

	while (current != nullptr && current->Priority >= priority)
	{
		parent = current;
		if (key < current->Key) {
			current = current->Left;
		}
		else {
			current = current->Right;
		}
	}

	TreapNode* left = nullptr;
	TreapNode* right = nullptr;

	if (current != nullptr) 
	{
		Split(current, key, left, right);
	}

	newNode->Left = left;
	newNode->Right = right;

	if (parent == nullptr) 
	{
		_node = newNode;
	}
	else if (key < parent->Key) 
	{
		parent->Left = newNode;
	}
	else {
		parent->Right = newNode;
	}
}

void Treap::Delete(int key)
{
	TreapNode* left = nullptr;
	TreapNode* right = nullptr;
	Split(_node, key, left, right);

	TreapNode* leftWithoutX = nullptr;
	TreapNode* rightWithoutX = nullptr;
	Split(left, key - 1, leftWithoutX, rightWithoutX);

	left = leftWithoutX;
	_node = Merge(left, right);
}

void Treap::OptimizedDelete(int key)
{
	TreapNode* current = _node;
	TreapNode* parent = nullptr;
	while (current != nullptr && current->Key != key)
	{
		parent = current;
		if (key < current->Key) 
		{
			current = current->Left;
		}
		else 
		{
			current = current->Right;
		}
	}

	if (current == nullptr) return;

	TreapNode* merged = Merge(current->Left, current->Right);

	if (parent == nullptr)
	{
		_node = merged;
	}
	else if (key < parent->Key) 
	{
		parent->Left = merged;
	}
	else {
		parent->Right = merged;
	}

	current->Left = nullptr;
	current->Right = nullptr;

	delete current;
}

TreapNode* Treap::Find(TreapNode* node, int key) {
	if (node == nullptr) 
	{
		return nullptr;
	}
	if (node->Key == key) 
	{
		return node;
	}
	if (key < node->Key) 
	{
		return Find(node->Left, key);
	}
	else 
	{
		return Find(node->Right, key);
	}
}


void Treap::Clear(TreapNode* node) 
{
	if (node == nullptr) return;
	Clear(node->Left);
	Clear(node->Right);
	delete node;
}