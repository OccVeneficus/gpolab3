#include "ClassesOutput.h"

void PrintNode(Node *toPrint)
{
	cout << "| Key: " << toPrint->GetKey() << " Value: " <<
		toPrint->GetValue() << " | -> ";
}

void PrintChain(Chain *toPrint)
{
	if (toPrint->GetSize() == 0)
	{
		cout << "<empty>";
		return;
	}
	Node *nodeToPrint = toPrint->GetNode(0);
	for (int i = 0; i < toPrint->GetSize(); i++)
	{
		PrintNode(nodeToPrint);
		nodeToPrint = nodeToPrint->GetNext();
	}
}

void PrintTable(HashTable *toPrint)
{
	for (int i = 0; i < toPrint->GetTableSize(); i++)
	{
		cout << i << ": ";
		PrintChain(toPrint->GetChain(i));
		cout << endl;
	}
	cout << endl;
}

void PrintDictionary(Dictionary *toPrint)
{
	HashTable *gettedHashTable = toPrint->GetAssociativeArray();
	Chain *gettedChain;
	for (int i = 0; i < gettedHashTable->GetTableSize(); i++)
	{
		if ((gettedChain = gettedHashTable->GetChain(i)) != nullptr)
		{
			for (int j = 0; j < gettedChain->GetSize(); j++)
			{
				PrintNode(gettedChain->GetNode(j));
				cout << endl;
			}
		}
	}
}