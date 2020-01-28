#pragma once
#include "HashTable.h"
#include <string>
#include <sstream>

class Dictionary
{
private:
	HashTable AssociativeArray;
public:
	HashTable *GetAssociativeArray()
	{
		return &AssociativeArray;
	}
	void AddKeyValuePair(string key, string value);
	void DeletePairByKey(string key);
	Node * SearchPairByKey(string key);
};