#pragma once

class TreapNode
{
private:
	int _key;
	int _priority;
	TreapNode *_left;
	TreapNode *_right;
	TreapNode *_parent;
	friend class Treap;
public:
	TreapNode(int key, int priority,
		TreapNode *left = nullptr ,
		TreapNode *right = nullptr);
	int GetKey();
	int GetPriority();
	TreapNode *GetLeft();
	TreapNode *GetRight();
	~TreapNode();
};

