#include "Node.h"

Node::Node(int data, Node *parent)
{
	this->_data = data;
	this->_parent = parent;
	this->_left = nullptr;
	this->_right = nullptr;
}

Node * Node::GetLeft()
{
	return this->_left;
}

Node * Node::GetRight()
{
	return this->_right;
}

Node Node::operator=(const Node & other)
{
	this->_data = other._data;
	this->_left = other._left;
	this->_parent = other._parent;
	this->_right = other._right;
	return *this;
}

int Node::GetData()
{
	return this->_data;
}

Node::~Node()
{

}
