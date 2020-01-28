#pragma once
#include "AVLNode.h"

class AVLTree
{
private:
	AVLNode *_root;
	int GetHeight(AVLNode *root);
	int MaxFromTwo(int first, int second);
	AVLNode *RotateRight(AVLNode *&toRotate);
	AVLNode *RotateLeft(AVLNode *&toRotate);
	AVLNode *BigRotateLeft(AVLNode *&toRotate);
	AVLNode *BigRotateRight(AVLNode *&toRotate);
	AVLNode *InsertAVLNode(int key, AVLNode *root);
	AVLNode *RemoveAVLNode(int key, AVLNode *root);
	AVLNode *FindMinimum(AVLNode *root);
	void DeleteTree(AVLNode *root);
	int _rotationCounter;
public:
	AVLTree();
	int GetRotationCounter();
	AVLNode *GetRoot();
	void Insert(int key);
	void Delete(int key);
	AVLNode *SearchByKey(int key, AVLNode *root);
	~AVLTree();
};

