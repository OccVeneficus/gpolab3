#pragma once

class Node
{
private:
	int _data;
	Node *_left;
	Node *_right;
	Node *_parent;
	friend class BinaryTree;
public:
	Node(int data, Node *parent = nullptr);
	Node *GetLeft();
	Node *GetRight();
	Node operator=(const Node &other);
	int GetData();
	~Node();
};