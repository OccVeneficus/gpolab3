#include "RedBlackTree.h"


RedBlackTree::RedBlackTree()
{
	this->_root = nullptr;
}

RedBlackNode * RedBlackTree::GetRoot()
{
	return this->_root;
}

RedBlackNode *RedBlackTree::InsertBST(RedBlackNode *&root, RedBlackNode *&toInsert)
{
	if (root == nullptr)
	{
		return toInsert;
	}
	if (toInsert->_key < root->_key)
	{
		root->_left = InsertBST(root->_left, toInsert);
		root->_left->_parent = root;
	}
	else
	{
		root->_right = InsertBST(root->_right, toInsert);
		root->_right->_parent = root;
	}
	return root;
}

RedBlackNode *RedBlackTree::ReplaceBST(RedBlackNode *toReplace)
{
	if (toReplace->_left != nullptr && toReplace->_right != nullptr)
	{
		return FindSuccessor(toReplace->_right);
	}
	if (toReplace->_left == nullptr && toReplace->_right == nullptr)
	{
		return nullptr;
	}
	if (toReplace->_left != nullptr)
	{
		return toReplace->_left;
	}
	else
	{
		return toReplace->_right;
	}
}

RedBlackNode *RedBlackTree::FindSuccessor(RedBlackNode *root)
{
	RedBlackNode *successor = root;
	while (successor->_left != nullptr)
	{
		successor = successor->_left;
	}
	return successor;
}

RedBlackNode *RedBlackTree::MinimumKeyNode(RedBlackNode *root)
{
	RedBlackNode *minNode = root;
	while (minNode->_left != nullptr)
	{
		minNode = minNode->_left;
	}
	return minNode;
}

RedBlackNode * RedBlackTree::SearchByKey(RedBlackNode *root, int key)
{
	if (root == nullptr)
	{
		return nullptr;
	}
	if (root->_key == key)
	{
		return root;
	}
	if (root->_key > key)
	{
		SearchByKey(root->_left, key);
	}
	else
	{
		SearchByKey(root->_right, key);
	}
}

void RedBlackTree::RotateLeft(RedBlackNode *&toRotate)
{
	_rotationCounter++;
	RedBlackNode *rightChild = toRotate->_right;
	toRotate->_right = rightChild->_left;
	if (toRotate->_right != nullptr)
	{
		toRotate->_right->_parent = toRotate;
	}
	rightChild->_parent = toRotate->_parent;
	if (toRotate->_parent == nullptr)
	{
		_root = rightChild;
	}
	else if (toRotate == toRotate->_parent->_left)
	{
		toRotate->_parent->_left = rightChild;
	}
	else
	{
		toRotate->_parent->_right = rightChild;
	}
	rightChild->_left = toRotate;
	toRotate->_parent = rightChild;
}

void RedBlackTree::RotateRight(RedBlackNode *&toRotate)
{
	_rotationCounter++;
	RedBlackNode *leftChild = toRotate->_left;
	toRotate->_left = leftChild->_right;
	if (toRotate->_left != nullptr)
	{
		toRotate->_left->_parent = toRotate;
	}
	leftChild->_parent = toRotate->_parent;
	if (toRotate->_parent == nullptr)
	{
		_root = leftChild;
	}
	else if (toRotate == toRotate->_parent->_left)
	{
		toRotate->_parent->_left = leftChild;
	}
	else
	{
		toRotate->_parent->_right = leftChild;
	}
	leftChild->_right = toRotate;
	toRotate->_parent = leftChild;
}

void RedBlackTree::InsertNode(int key, RedBlackNode *root)
{
	_rotationCounter = 0;
	if (SearchByKey(root, key) != nullptr)
	{
		return;
	}
	RedBlackNode *toInsert = new RedBlackNode(key,true);
	_root = InsertBST(_root, toInsert);
	FixInsert(toInsert);
}

void RedBlackTree::FixInsert(RedBlackNode *&insertedNode)
{
	while (insertedNode != _root && insertedNode->_isRed
		&& insertedNode->_parent->_isRed)
	{
		RedBlackNode *parent = insertedNode->_parent;
		RedBlackNode *grandParent = parent->_parent;
		if (parent == grandParent->_left)
		{
			RedBlackNode *uncle = grandParent->_right;
			if (uncle->IsRed())
			{
				uncle->_isRed = false;
				parent->_isRed = false;
				grandParent->_isRed = true;
				insertedNode = grandParent;
			}
			else
			{
				if (insertedNode == parent->_right)
				{
					RotateLeft(parent);
					insertedNode = parent;
					parent = insertedNode->_parent;
				}
				RotateRight(grandParent);
				bool tempColor;
				tempColor = parent->_isRed;
				parent->_isRed = grandParent->_isRed;
				grandParent->_isRed = tempColor;
				insertedNode = parent;
			}
		}
		else
		{
			RedBlackNode *uncle = grandParent->_left;
			if (uncle->IsRed())
			{
				uncle->_isRed = false;
				parent->_isRed = false;
				grandParent->_isRed = true;
				insertedNode = grandParent;
			}
			else
			{
				if (insertedNode == parent->_left)
				{
					RotateRight(parent);
					insertedNode = parent;
					parent = insertedNode->_parent;
				}
				RotateLeft(grandParent);
				bool tempColor;
				tempColor = parent->_isRed;
				parent->_isRed = grandParent->_isRed;
				grandParent->_isRed = tempColor;
				insertedNode = parent;
			}
		}
	}
	_root->_isRed = false;
}

void RedBlackTree::DeleteNode(RedBlackNode *&toDelete)
{
	RedBlackNode *replacedNode = ReplaceBST(toDelete);
	bool doubleBlack = ((replacedNode == nullptr || replacedNode->_isRed == false)
		&& (toDelete->_isRed == false));
	RedBlackNode *parent = toDelete->_parent;
	if (replacedNode == nullptr)
	{
		if (toDelete == _root)
		{
			_root = nullptr;
		}
		else
		{
			if (doubleBlack)
			{
				FixDoubleBlack(toDelete);
			}
			else
			{
				if (toDelete->GetBrother() != nullptr)
				{
					toDelete->GetBrother()->_isRed = true;
				}
			}
			if (toDelete->IsOnLeft())
			{
				parent->_left = nullptr;
			}
			else
			{
				parent->_right = nullptr;
			}
		}
		delete toDelete;
		return;
	}
	if (toDelete->_left == nullptr || toDelete->_right == nullptr)
	{
		if (toDelete == _root)
		{
			toDelete->_key = replacedNode->_key;
			toDelete->_left = nullptr;
			toDelete->_right = nullptr;
			delete replacedNode;
		}
		else
		{
			if (toDelete->IsOnLeft())
			{
				parent->_left = replacedNode;
			}
			else
			{
				parent->_right = replacedNode;
			}
			replacedNode->_parent = parent;
			if (doubleBlack)
			{
				FixDoubleBlack(replacedNode);
			}
			else
			{
				replacedNode->_isRed = false;
			}
		}
		return;
	}
	int temp = replacedNode->_key;
	replacedNode->_key = toDelete->_key;
	toDelete->_key = temp;
	DeleteNode(replacedNode);
}

void RedBlackTree::DeleteByKey(int key)
{
	_rotationCounter = 0;
	if (_root == nullptr)
	{
		return;
	}
	RedBlackNode *toDelete = SearchByKey(_root, key);
	if (toDelete == nullptr)
	{
		return;
	}
	DeleteNode(toDelete);
}

int RedBlackTree::GetRotationCounter()
{
	return this->_rotationCounter;
}

void RedBlackTree::DeleteTree(RedBlackNode *root)
{
	if (root == nullptr)
	{
		return;
	}
	DeleteTree(root->_left);
	DeleteTree(root->_right);
	delete root;
}

void RedBlackTree::FixDoubleBlack(RedBlackNode * toFix)
{
	if (toFix == _root)
	{
		return;
	}
	RedBlackNode *brother = toFix->GetBrother();
	RedBlackNode *parent = toFix->_parent;
	if (brother == nullptr)
	{
		FixDoubleBlack(parent);
	}
	else
	{
		if (brother->_isRed)
		{
			parent->_isRed = true;
			brother->_isRed = false;
			if (brother->IsOnLeft())
			{
				RotateRight(parent);
			}
			else
			{
				RotateLeft(parent);
			}
			FixDoubleBlack(toFix);
		}
		else
		{
			if (brother->_left->IsRed() || brother->_right->IsRed())
			{
				if (brother->_left != nullptr && brother->_left->_isRed == true)
				{
					if (brother->IsOnLeft())
					{
						brother->_left->_isRed = parent->_isRed;
						brother->_isRed = parent->_isRed;
						RotateRight(parent);
					}
					else
					{
						brother->_left->_isRed = parent->_isRed;
						RotateRight(brother);
						RotateLeft(parent);
					}
				}
				else
				{
					if (brother->IsOnLeft())
					{
						brother->_right->_isRed = parent->_isRed;
						RotateLeft(brother);
						RotateRight(parent);
					}
					else
					{
						brother->_right->_isRed = brother->_isRed;
						brother->_isRed = parent->_isRed;
						RotateLeft(parent);
					}
				}
				parent->_isRed = false;
			}
			else
			{
				brother->_isRed = true;
				if (parent->_isRed == false)
				{
					FixDoubleBlack(parent);
				}
				else
				{
					parent->_isRed = false;
				}
			}
		}
	}
}


RedBlackTree::~RedBlackTree()
{
	DeleteTree(this->_root);
}
