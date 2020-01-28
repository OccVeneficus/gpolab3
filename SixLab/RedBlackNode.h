#pragma once
class RedBlackTree;

class RedBlackNode
{
private:
	bool _isRed;
	int _key;
	RedBlackNode *_left;
	RedBlackNode *_right;
	RedBlackNode *_parent;
	friend class RedBlackTree;
public:
	RedBlackNode(int key, bool isRed = true, RedBlackNode *left = nullptr,
		RedBlackNode *right = nullptr, RedBlackNode *parent = nullptr);
	bool IsRed();
	int GetKey();
	bool IsOnLeft();
	RedBlackNode *GetBrother();
	RedBlackNode *GetLeft();
	RedBlackNode *GetRight();
	RedBlackNode *GetParent();
};


