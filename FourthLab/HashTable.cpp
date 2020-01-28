#include "HashTable.h"

HashTable::HashTable(int tableSize)
{
	_tableSize = tableSize;
	_pairArray = new Chain[_tableSize];
	_growthFactor = (int)4 * _tableSize / 3;
	_nodeCounter = 0;
}

HashTable::~HashTable()
{
	delete[] _pairArray;
}

int HashTable::GetTableSize()
{
	return this->_tableSize;
}

Chain * HashTable::GetChain(int index)
{
	if (index < _tableSize)
	{
		return &this->_pairArray[index];
	}
	return nullptr;
}

int HashTable::Hash(string key)
{
	int hash = (_tableSize- 1) * 2;
	int simpleNumber = _tableSize - 1;
	for (int i = 0; i < key.size(); i++)
	{
		hash = (hash * simpleNumber + key[i]) % _tableSize;
	}
	return abs(hash);
}

bool HashTable::AddKeyValuePair(string key, string value)
{
	if (CheckGrowthFactor())
	{
		ReHash();
	}
	int hashNumber = Hash(key);
	if (_pairArray[hashNumber].Search(key, value) != nullptr)
	{
		return false;
	}
	_pairArray[hashNumber].AddToEnd(key, value);
	_nodeCounter++;
	return true;
}

Node *HashTable::Search(string key, string value)
{
	Node *findedValue = nullptr;
	for (int i = 0; i < _tableSize; i++)
	{
		if (_pairArray[i].Search(key, value) != nullptr)
		{
			findedValue = _pairArray[i].Search(key, value);
		}
	}
	return findedValue;
}

Node * HashTable::Search(string key)
{
	Node *findedValue = nullptr;
	for (int i = 0; i < _tableSize; i++)
	{
		if (_pairArray[i].Search(key) != nullptr)
		{
			findedValue = _pairArray[i].Search(key);
		}
	}
	return findedValue;
}

bool HashTable::DeletePairByKey(string key, string value)
{
	Node *toDelete;
	int hashNumber = Hash(key);
	if ((toDelete = _pairArray[hashNumber].Search(key, value)) != nullptr)
	{
		_pairArray[hashNumber].DeleteNode(toDelete);
		_nodeCounter--;
		return true;
	}
	return false;
}

bool HashTable::DeletePairByKey(string key)
{
	Node *toDelete;
	for (int i = 0; i < _tableSize; i++)
	{
		if ((toDelete = _pairArray[i].Search(key)) != nullptr)
		{
			int j = 0;
			while (j != _pairArray[i].GetSize())
			{
				_pairArray[i].DeleteNode(toDelete);
				_nodeCounter--;
			}
			return true;
		}
	}
	return false;
}

bool HashTable::CheckGrowthFactor()
{
	if (_nodeCounter >= _growthFactor)
	{
		return true;
	}
	return false;
}

void HashTable::ReHash()
{
	int newTableSize = _tableSize * 2;
	HashTable tempTable(_tableSize);
	tempTable._nodeCounter = this->_nodeCounter;
	Node *toReHash;
	for (int i = 0; i < _tableSize; i++)
	{
		for (int j = 0; j < this->_pairArray[i].GetSize(); j++)
		{
			toReHash = this->_pairArray[i].GetNode(j);
			tempTable._pairArray[i].AddToEnd(toReHash->GetKey(),
			toReHash->GetValue());
		}
	}
	delete[] this->_pairArray;
	this->_tableSize = newTableSize;
	this->_pairArray = new Chain[_tableSize];
	this->_growthFactor = (int)4 * newTableSize / 3;
	for (int i = 0; i < tempTable._tableSize; i++)
	{
		for (int j = 0; j < tempTable._pairArray[i].GetSize(); j++)
		{
			toReHash = tempTable._pairArray[i].GetNode(j);
			this->AddKeyValuePair(toReHash->GetKey(), toReHash->GetValue());
		}
	}
	this->_nodeCounter = tempTable._nodeCounter;
}
