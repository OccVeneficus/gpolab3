#pragma once
#include <iostream>
#include <ctime>

struct Node
{
	int Field;
	struct Node * Previous;
	struct Node * Next;
};

struct List
{
	int ListLength;
	Node *Head;
	Node *Tail;
	Node *CurrentNode;
};

void Initialisation(List *);
void AddingElement(int , List *, Node *);
void DeletingElement(List *);
void BubbleSort(List*);
void SwapNode(List*, Node*);
void SearchingElement(struct List *, int);
void DeletingAllList(List *);
void AddingElementes(int, List *, Node *);