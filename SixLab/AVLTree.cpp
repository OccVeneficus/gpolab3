#include "AVLTree.h"
#include "AVLNode.h"

int AVLTree::GetHeight(AVLNode *root)
{
	if (root == nullptr)
	{
		return -1;
	}
	return root->_height;
}

AVLTree::AVLTree()
{
	this->_root = nullptr;
}

int AVLTree::GetRotationCounter()
{
	return this->_rotationCounter;
}

AVLNode * AVLTree::GetRoot()
{
	return this->_root;
}

int AVLTree::MaxFromTwo(int first, int second)
{
	return (first > second) ? first : second;
}

AVLNode *AVLTree::RotateRight(AVLNode *&toRotate)
{
	AVLNode *toRotateLeft = toRotate->_left;
	toRotate->_left = toRotateLeft->_right;
	toRotateLeft->_right = toRotate;
	toRotate->_height = MaxFromTwo(GetHeight(toRotate->_left),
		GetHeight(toRotate->_right))+ 1;
	toRotateLeft->_height = MaxFromTwo(GetHeight(toRotateLeft->_left),
		GetHeight(toRotate)) + 1;
	_rotationCounter++;
	return toRotateLeft;
}

AVLNode * AVLTree::RotateLeft(AVLNode *&toRotate)
{
	AVLNode *toRotateRight = toRotate->_right;
	toRotate->_right = toRotateRight->_left;
	toRotateRight->_left = toRotate;
	toRotate->_height = MaxFromTwo(GetHeight(toRotate->_left),
		GetHeight(toRotate->_right)) + 1;
	toRotateRight->_height = MaxFromTwo(GetHeight(toRotate->_right),
		GetHeight(toRotate)) + 1;
	_rotationCounter++;
	return toRotateRight;
}

AVLNode * AVLTree::BigRotateLeft(AVLNode *& toRotate)
{
	toRotate->_right = RotateRight(toRotate->_right);
	return RotateLeft(toRotate);
}

AVLNode * AVLTree::BigRotateRight(AVLNode *& toRotate)
{
	toRotate->_left = RotateLeft(toRotate->_left);
	return RotateRight(toRotate);
}

AVLNode * AVLTree::InsertAVLNode(int key, AVLNode *root)
{
	if (root == nullptr)
	{
		root = new AVLNode(key);
	}
	else if (key < root->_key)
	{
		root->_left = InsertAVLNode(key, root->_left);
		if ((GetHeight(root->_left) - GetHeight(root->_right)) == 2)
		{
			if (key < root->_left->_key)
			{
				root = RotateRight(root);
			}
			else
			{
				root = BigRotateRight(root);
			}
		}
	}
	else if (key > root->_key)
	{
		root->_right = InsertAVLNode(key, root->_right);
		if ((GetHeight(root->_right) - GetHeight(root->_left)) == 2)
		{
			if (key > root->_right->_key)
			{
				root = RotateLeft(root);
			}
			else
			{
				root = BigRotateLeft(root);
			}
		}
	}
	root->_height = MaxFromTwo(GetHeight(root->_left),
		GetHeight(root->_right)) + 1;
	return root;
}

AVLNode * AVLTree::RemoveAVLNode(int key, AVLNode * root)
{
	AVLNode *tempAVLNode;
	if (root == nullptr)
	{
		return nullptr;
	}
	else if (key < root->_key)
	{
		root->_left = RemoveAVLNode(key, root->_left);
	}
	else if (key > root->_key)
	{
		root->_right = RemoveAVLNode(key, root->_right);
	}
	else if (root->_left && root->_right)
	{
		tempAVLNode = FindMinimum(root->_right);
		root->_key = tempAVLNode->_key;
		root->_right = RemoveAVLNode(root->_key, root->_right);
	}
	else
	{
		tempAVLNode = root;
		if (root->_left == nullptr)
		{
			root = root->_right;
		}
		else if (root->_right == nullptr)
		{
			root = root->_left;
		}
		delete tempAVLNode;
	}
	if (root == nullptr)
	{
		return root;
	}
	root->_height = MaxFromTwo(GetHeight(root->_left),
		GetHeight(root->_right)) + 1;
	if ((GetHeight(root->_left) - GetHeight(root->_right)) == 2)
	{
		if ((GetHeight(root->_left->_left) -
			GetHeight(root->_right->_right)) == 1)
		{
			return RotateLeft(root);
		}
		else
		{
			return BigRotateLeft(root);
		}
	}
	else if ((GetHeight(root->_right) - GetHeight(root->_left)) == 2)
	{
		if ((GetHeight(root->_right->_right) -
			GetHeight(root->_left->_left)) == 1)
		{
			return RotateRight(root);
		}
		else
		{
			return BigRotateRight(root);
		}
	}
	return root;
}

AVLNode * AVLTree::FindMinimum(AVLNode * root)
{
	if (root == nullptr)
	{
		return nullptr;
	}
	else if (root->_left == nullptr)
	{
		return root;
	}
	else
	{
		FindMinimum(root->_left);
	}
}

void AVLTree::DeleteTree(AVLNode * root)
{
	if (root == nullptr)
	{
		return;
	}
	DeleteTree(root->_left);
	DeleteTree(root->_right);
	delete root;
}

void AVLTree::Insert(int key)
{
	_rotationCounter = 0;
	_root = InsertAVLNode(key, _root);
}

void AVLTree::Delete(int key)
{
	_rotationCounter = 0;
	_root = RemoveAVLNode(key, _root);
}

AVLNode * AVLTree::SearchByKey(int key, AVLNode * root)
{
	if (root == nullptr)
	{
		return nullptr;
	}
	if (key == root->_key)
	{
		return root;
	}
	if (key < root->_key)
	{
		SearchByKey(key, root->_left);
	}
	else if (key > root->_key)
	{
		SearchByKey(key, root->_right);
	}
}

AVLTree::~AVLTree()
{
	DeleteTree(this->_root);
}
