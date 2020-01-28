#include "Treap.h"

Treap::Treap()
{
	this->_root = nullptr;
}

TreapNode *Treap::GetRoot()
{
	return this->_root;
}

TreapNode *Treap::Merge(TreapNode *left, TreapNode *right)
{
	if (left == nullptr || right == nullptr)
	{
		return left == nullptr ? right : left;
	}
	if (left->_priority > right->_priority)
	{
		left->_right = Merge(left->_right, right);
		return left;
	}
	else
	{
		right->_left = Merge(left, right->_left);
		return right;
	}
}

void Treap::Split(TreapNode *node, int key, TreapNode *&left, TreapNode *&right)
{
	if (node == nullptr)
	{
		left = nullptr;
		right = nullptr;
	}
	else if (node->_key <= key)
	{
		Split(node->_right, key, node->_right, right);
		left = node;
	}
	else if (node->_key > key)
	{
		Split(node->_left, key, left, node->_left);
		right = node;
	}
}

TreapNode *Treap::Add(int key)
{
	TreapNode *newNode = new TreapNode(key, rand() % 100);
	TreapNode *left = nullptr;
	TreapNode *right = nullptr;
	Split(this->_root, key, left, right);
	return this->_root = Merge(Merge(left, newNode), right);
}

void Treap::OptimisedAdd(TreapNode *&current, TreapNode *newNode)
{
	if (this->_root == nullptr)
	{
		this->_root = newNode;
	}
	if (current == nullptr)
	{
		current = newNode;
	}
	else if (newNode->_priority > current->_priority)
	{
		Split(current, newNode->_key, newNode->_left, newNode->_right);
		if (current == this->_root)
		{
			this->_root = newNode;
		}
		else 
		{
			current = newNode;
		}
	}
	else
	{
		OptimisedAdd(newNode->_key < current->_key
			? current->_left : current->_right, newNode);
	}
}

TreapNode *Treap::Remove(int key)
{
	TreapNode *left = nullptr;
	TreapNode *right = nullptr;
	TreapNode *midlle = nullptr;
	Split(this->_root, key - 1, left, right);
	Split(right, key, midlle, right);
	return this->_root = Merge(left, right);
}

TreapNode *Treap::OptimisedRemove(int key, TreapNode *&current)
{
	if (current == nullptr)
	{
		return nullptr;
	}
	else if (current->_key == key)
	{
		current = Merge(current->_left, current->_right);
		if (this->_root->_key == key)
		{
			this->_root = current;
		}
		return this->_root;
	}
	else
	{
		OptimisedRemove(key, key < current->_key
			? current->_left : current->_right);
	}

}

TreapNode *Treap::Search(int key, TreapNode *toCheck)
{
	if (toCheck == nullptr)
	{
		return nullptr;
	}
	if (toCheck->_key == key)
	{
		return toCheck;
	}
	if (key > toCheck->_key)
	{
		Search(key, toCheck->_right);
	}
	else
	{
		Search(key, toCheck->_left);
	}
}

void Treap::DeleteTreap(TreapNode *toDelete)
{
	if (toDelete == nullptr)
	{
		return;
	}
	DeleteTreap(toDelete->_left);
	DeleteTreap(toDelete->_right);
	delete toDelete;
}

Treap::~Treap()
{
	DeleteTreap(this->_root);
	this->_root = nullptr;
}
