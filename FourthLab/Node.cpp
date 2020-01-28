#include "Node.h"

string Node::GetKey()
{
	return this->_key;
}

string Node::GetValue()
{
	return this->_value;
}

void Node::SetNext(Node * toSet)
{
	this->_next = toSet;
}

void Node::SetNext(string key, string value)
{
	Node *toSet = new Node(key,value);
	this->_next = toSet;
}

Node * Node::GetNext()
{
	return this->_next;
}
