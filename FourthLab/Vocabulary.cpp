#include "Vocabulary.h"
#include "DataInOut.h"

void Dictionary::AddKeyValuePair(string key, string value)
{
	if (AssociativeArray.Search(key) != nullptr)
	{
		PrintingAddFail();
	}
	else
	{
		AssociativeArray.AddKeyValuePair(key, value);
	}
}

void Dictionary::DeletePairByKey(string key)
{
	if (!AssociativeArray.DeletePairByKey(key))
	{
		PrintingDeleteFail();
	}
}

Node *Dictionary::SearchPairByKey(string key)
{
	return AssociativeArray.Search(key);
}