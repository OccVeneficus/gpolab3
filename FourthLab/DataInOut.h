#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <stdlib.h>

typedef unsigned int uint;

using namespace std;

const int EXIT_MENU_ITEM = 0;

bool CheckingForInteger(string );
int ReadingValue();
void DictionaryMenuTextPrinting();
void HashTableMenuPrinting();
string InputString();
void PrintingDeleteFail();
void PrintingAddFail();
void ReadingKeyValue(string &key, string &value);
void ReadingStringKey(string &);
void ReadingStringValue(string &);
void MainMenuPrinting();