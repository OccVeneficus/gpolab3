#include "BinaryTree.h"

void BinaryTree::DeleteTree(Node * toDelete)
{
	if (toDelete == nullptr)
	{
		return;
	}
	DeleteTree(toDelete->_right);
	DeleteTree(toDelete->_left);
	delete toDelete;
	toDelete = nullptr;
}

BinaryTree::BinaryTree()
{
	this->_root = nullptr;
}


BinaryTree::~BinaryTree()
{
	DeleteTree(this->_root);
	this->_root = nullptr;
}

Node *BinaryTree::GetRoot()
{
	return this->_root;
}

void BinaryTree::AddNode(int data, Node *parent)
{
	if (parent == nullptr)
	{
		parent = this->_root;
	}
	Node *tempNode = parent;
	if (this->_root == nullptr)
	{
		this->_root = new Node(data);
		return;
	}
	if (data < tempNode->_data)
	{
		if (tempNode->_left != nullptr)
		{
			AddNode(data, tempNode->_left);
		}
		else
		{
			tempNode->_left = new Node(data, parent);
		}
	}
	if (data > tempNode->_data)
	{
		if (tempNode->_right != nullptr)
		{
			AddNode(data, tempNode->_right);
		}
		else
		{
			tempNode->_right = new Node(data, parent);
		}
	}
}

Node *BinaryTree::DeleteNode(int data, Node *&toDelete)
{
	if (toDelete == nullptr)
	{
		return toDelete;
	}
	if (data < toDelete->_data)
	{
		toDelete->_left = DeleteNode(data, toDelete->_left);
	}
	else if (data > toDelete->_data)
	{
		toDelete->_right = DeleteNode(data, toDelete->_right);
	}
	else
	{
		if (toDelete->_left == nullptr)
		{
			Node *toReplace = toDelete->_right;
			if (toDelete == this->_root)
			{
				this->_root = toReplace;
				return this->_root;
			}
			delete toDelete;
			return toReplace;
		}
		else if (toDelete->_right == nullptr)
		{
			Node *toReplace = toDelete->_left;
			if (toDelete == this->_root)
			{
				this->_root = toReplace;
				return this->_root;
			}
			delete toDelete;
			return toReplace;
		}
		Node *toReplace = SearchMin(toDelete->_right);
		toDelete->_data = toReplace->_data;
		toDelete->_right = DeleteNode(toReplace->_data, toDelete->_right);
	}
	return toDelete;
}

Node *BinaryTree::SearchMax(Node * toCheck)
{
	toCheck = this->_root;
	while (toCheck->_right != nullptr)
	{
		toCheck = toCheck->_right;
	}
	return toCheck;
}

Node *BinaryTree::SearchMin(Node *toCheck)
{
	if (toCheck == nullptr)
	{
		toCheck = this->_root;
	}
	while (toCheck->_left != nullptr)
	{
		toCheck = toCheck->_left;
	}
	return toCheck;
}

Node *BinaryTree::SearchNode(int data, Node *toCheck)
{
	if (toCheck == nullptr)
	{
		return nullptr;
	}
	if (toCheck->_data == data)
	{
		return toCheck;
	}
	if (data > toCheck->_data)
	{
		SearchNode(data, toCheck->_right);
	}
	else 
	{
		SearchNode(data, toCheck->_left);
	}
}
