#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int EXIT_MENU_ITEM = 8;

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