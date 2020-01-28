#include "DataInOut.h"
bool CheckingForInteger(string value)
{
	int size = value.length();
	if (isdigit((unsigned char)value[0]) || (unsigned char)value[0] == '-')
	{
		for (int i = 1; i < size; i++)
		{
			if (!isdigit((unsigned char)value[i]))
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
}

int ReadingValue()
{
	string inputValue;
	int outputValue;
	while (true)
	{
		getline(cin, inputValue);
		bool intCheckFlag = CheckingForInteger(inputValue);
		istringstream inputStringStream(inputValue);
		int number;
		inputStringStream >> number;
		if (intCheckFlag == false || inputStringStream.fail())
		{
			cout << endl << "Wrong input, try again.You can use only integer:";
			inputValue.clear();
		}
		else
		{
			outputValue = stoi(inputValue);
			return outputValue;
		}
	}
}

void DictionaryMenuTextPrinting()
{
	cout << endl;
	cout << " ______________________________________________________________\n";
	cout << "|                 ||||||DICTIONARY MENU||||||                 |\n";
	cout << "| 1. Add key-value pair                                       |\n";
	cout << "| 2. Delete key                                               |\n";
	cout << "| 3. Search key                                               |\n";
	cout << "| 0. Quit                                                     |\n";
	cout << "|_____________________________________________________________|\n";
}

void HashTableMenuPrinting()
{
	cout << endl;
	cout << " ______________________________________________________________\n";
	cout << "|                 ||||||HASH TABLE MENU||||||                 |\n";
	cout << "| 1. Add key-value pair                                       |\n";
	cout << "| 2. Delete key-value pair                                    |\n";
	cout << "| 3. Search key-value pair                                    |\n";
	cout << "| 0. Quit                                                     |\n";
	cout << "|_____________________________________________________________|\n";
}

string InputString()
{
	string toRead;
	getline(cin, toRead);
	return toRead;
}

void PrintingDeleteFail()
{
	cout << "Failed to delete element from table."<<
		" Perhaps there is no such value.";
}

void PrintingAddFail()
{
	cout << "Value already in this vocalbulary."<<
		" You can`t add a duplicate.\n";
	system("pause");
}

void ReadingKeyValue(string & key, string & value)
{
	ReadingStringKey(key);
	ReadingStringValue(value);
}

void ReadingStringKey(string & key)
{
	cout << "Key: ";
	getline(cin, key);
}

void ReadingStringValue(string & value)
{
	cout << "Value: ";
	getline(cin, value);
}

void MainMenuPrinting()
{
	cout << endl;
	cout << " ______________________________________________________________\n";
	cout << "|                       ||||||MENU||||||                      |\n";
	cout << "| 1. Dictionary                                               |\n";
	cout << "| 2. Hashtable                                                |\n";
	cout << "| 0. Quit program                                             |\n";
	cout << "|_____________________________________________________________|\n";
}
