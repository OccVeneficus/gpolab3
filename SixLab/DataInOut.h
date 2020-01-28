#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime> 
#include "RedBlackTree.h"
#include "AVLTree.h"

const int EXIT_MENU_ITEM = 0;

using namespace std;

bool CheckingForInteger(string value);
int ReadingValue();
void TreePrinting(string prefix, RedBlackNode *node, bool isLeft);
void TreePrinting(RedBlackNode * node);
void AVLTreePrinting(string prefix, AVLNode *node, bool isLeft);
void AVLTreePrinting(AVLNode * node);
void MainMenuPrinting();
void RBTMenuPrinting();
void AVLMenuPrinting();
int GetMenuItem();