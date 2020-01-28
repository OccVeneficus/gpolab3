#pragma once
class AVLTree;

class AVLNode
{
private:
	int _key;
	AVLNode *_left;
	AVLNode *_right;
	int _height;
	friend class AVLTree;
public:
	int GetKey();
	AVLNode *GetLeft();
	AVLNode *GetRight();
	AVLNode(int key);
};

