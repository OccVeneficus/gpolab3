#pragma once
#include "RedBlackNode.h"
class RedBlackTree
{
private:
	RedBlackNode *_root;
	RedBlackNode *InsertBST(RedBlackNode *&root, RedBlackNode *&toInsert);
	RedBlackNode *ReplaceBST(RedBlackNode *toReplace);
	RedBlackNode *FindSuccessor(RedBlackNode *root);
	RedBlackNode *MinimumKeyNode(RedBlackNode *root);
	void RotateLeft(RedBlackNode *&toRotate);
	void RotateRight(RedBlackNode *&toRotate);
	void DeleteTree(RedBlackNode *root);
	void FixDoubleBlack(RedBlackNode *toFix);
	void DeleteNode(RedBlackNode *&toReplace);
	void FixInsert(RedBlackNode *&insertedNode);
	int _rotationCounter;
public:
	RedBlackTree();
	RedBlackNode *GetRoot();
	RedBlackNode *SearchByKey(RedBlackNode *root, int key);
	void InsertNode(int key, RedBlackNode *root);
	void DeleteByKey(int key);
	int GetRotationCounter();
	~RedBlackTree();
};

