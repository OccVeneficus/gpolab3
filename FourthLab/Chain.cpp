#include "DataInOut.h"
#include "Chain.h"

Chain::Chain()
{
	_size = 0;
	_head = nullptr;
}

Chain::~Chain()
{
	delete _head;
}

Chain & Chain::operator=(const Chain & toAssign)
{
	delete this->_head;
	this->_head = toAssign._head;
	this->_size = toAssign._size;
	return *this;
}

void Chain::AddToEnd(string key, string value)
{
	if (_head == nullptr)
	{
		_head = new Node(key, value);
	}
	else
	{
		Node *tempNode = this->_head;
		while (tempNode->GetNext() != nullptr)
		{
			tempNode = tempNode->GetNext();
		}
		tempNode->SetNext(key,value);
	}
	_size++;
}

void Chain::DeleteNode(Node *toDelete)
{
	if (toDelete == _head)
	{
		DeleteHeadNode();
		return;
	}
 	Node *previous = this->_head;
	while (previous->GetNext() != toDelete)
	{
		previous = previous->GetNext();
	}
	previous->SetNext(toDelete->GetNext());
	delete toDelete;
	_size--;
}

void Chain::DeleteHeadNode()
{
	Node *tempNode = _head;
	_head = _head->GetNext();
	delete tempNode;
	_size--;
}

Node *Chain::GetNode(int index)
{
	Node *toGet = _head;
	while (index != 0)
	{
		toGet = toGet->GetNext();
		index--;
	}
	return toGet;
}

Node *Chain::Search(string key, string value)
{
	Node *toSearch = _head;
	for (int i = 0; i < this->GetSize(); i++)
	{
		if (toSearch->GetKey() == key && toSearch->GetValue() == value)
		{
			return toSearch;
		}
		toSearch = toSearch->GetNext();
	}
	return toSearch = nullptr;
}

Node *Chain::Search(string key)
{
	Node *toSearch = _head;
	for (int i = 0; i < this->GetSize(); i++)
	{
		if (toSearch->GetKey() == key)
		{
			return toSearch;
		}
		toSearch = toSearch->GetNext();
	}
	return toSearch = nullptr;
}