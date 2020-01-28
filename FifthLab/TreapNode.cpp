#include "TreapNode.h"



TreapNode::TreapNode(int key, int priority, TreapNode *left,
	TreapNode *right)
{
	this->_key = key;
	this->_priority = priority;
	this->_left = left;
	this->_right = right;
}

int TreapNode::GetKey()
{
	return this->_key;
}

int TreapNode::GetPriority()
{
	return this->_priority;
}

TreapNode * TreapNode::GetLeft()
{
	return this->_left;
}

TreapNode * TreapNode::GetRight()
{
	return this->_right;
}

TreapNode::~TreapNode()
{

}
