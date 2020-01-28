#pragma once
#include "Chain.h"

class HashTable
{
private:
	//TODO: naming(done)
	int _growthFactor;
	int _tableSize;
	Chain *_pairArray;
	int _nodeCounter;

	//TODO: RSDN(done)
	bool CheckGrowthFactor();
	void ReHash();
	int Hash(string key);
public:
	HashTable(int tableSize = 5);
	~HashTable();
	int GetTableSize();
	Chain * GetChain(int index);
	bool AddKeyValuePair(string key, string value);
	Node *Search(string key, string value);
	Node *Search(string key);
	bool DeletePairByKey(string key, string value);
	bool DeletePairByKey(string key);
};