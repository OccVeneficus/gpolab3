#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <ctime> 
#include "BinaryTree.h"
#include "Treap.h"

const int EXIT_MENU_ITEM = 0;

using namespace std;

void TreePrinting(string prefix, Node *node, bool isLeft);
void TreePrinting(Node *node);
void TreapPrinting(string prefix, TreapNode *node, bool isLeft);
void TreapPrinting(TreapNode *node);
bool CheckingForInteger(string);
int ReadingValue();
void MainMenuPrinting();
void BinaryMenuPrinting();
void TreapMenuPrinting();