#pragma once
#include "Node.h"
class Chain
{
private:
	int _size;
	Node *_head;
public:
	Chain();
	~Chain();
	Chain & operator=(const Chain & toAssign);
	void AddToEnd(string key, string value);
	//TODO: private(done)


	void DeleteNode(Node *toDelete);
	void DeleteHeadNode();
	int GetSize()
	{
		return _size;
	}
	Node *GetNode(int index);
	Node *Search(string key , string value);
	Node *Search(string key);
};