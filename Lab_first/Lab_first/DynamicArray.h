#pragma once
#include <iostream>


using namespace std;

struct DynamicArray
{
	int Length;
	int Capacity;
	int *Array;
};

void DeletingArray(int*);
void CreatingArray(DynamicArray &);
void PrintingArray(DynamicArray &);
void PrintingMenuText();
void DeletingElement(DynamicArray &);
void AddingAfterIndex(DynamicArray &, int);
void SortingArray(DynamicArray &);
void LinearSearching(DynamicArray &);
void BinarSearching(DynamicArray &);
void RecreatingArray(DynamicArray &);
int ReadingValue();