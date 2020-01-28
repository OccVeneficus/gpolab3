#pragma once
#include "DataInOut.h"
class Chain;

class Node
{
private:
	string _key;
	string _value;
	Node *_next;
	void SetNext(Node *toSet);
	void SetNext(string key, string value);
	friend class Chain;
public:
	Node(string key, string value, Node *nextNode = nullptr)
	{
		this->_key = key;
		this->_value = value;
		this->_next = nextNode;
	}
	~Node()
	{
		
	}
	string GetKey();
	string GetValue();
	Node *GetNext();
};