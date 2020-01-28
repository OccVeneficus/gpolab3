#include "RedBlackNode.h"

RedBlackNode::RedBlackNode(int key, bool isRed, RedBlackNode * left,
	RedBlackNode * right, RedBlackNode * parent)
{
	this->_key = key;
	this->_isRed = isRed;
	this->_left = left;
	this->_right = right;
	this->_parent = parent;
}

bool RedBlackNode::IsRed()
{
	if (this == nullptr)
	{
		return false;
	}
	else
	{
		return this->_isRed;
	}
}


int RedBlackNode::GetKey()
{
	return this->_key;
}

bool RedBlackNode::IsOnLeft()
{
	return this == _parent->_left;
}

RedBlackNode * RedBlackNode::GetBrother()
{
	if (_parent == nullptr)
	{
		return nullptr;
	}
	if (IsOnLeft())
	{
		return _parent->_right;
	}
	else
	{
		return _parent->_left;
	}
}

RedBlackNode * RedBlackNode::GetLeft()
{
	return this->_left;
}

RedBlackNode * RedBlackNode::GetRight()
{
	return this->_right;
}

RedBlackNode * RedBlackNode::GetParent()
{
	return this->_parent;
}

