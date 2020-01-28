#include "DataInputOutput.h"
#include "LinkedLists.h"
#include <string>
#include <sstream>

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

void ListPrinting(List *listParameters)
{
	cout << endl;
	struct Node *elementToPrint;
	elementToPrint = listParameters->Head;
	for(int i = 0; i < listParameters->ListLength; i++)
	{
		cout << elementToPrint->Field << ' ';
		elementToPrint = elementToPrint->Next;
	}
	cout << endl;
}

void MenuPrinting()
{
	cout << " ______________________________________________________________\n";
	cout << "|                       ||||||MENU||||||                      |\n";
	cout << "|List of available functions:                                 |\n";
	cout << "|(To choose function type it number from list below)          |\n";
	cout << "| 1. Delete element from list.                                |\n";
	cout << "| 2. Add element to begin of list.                            |\n";
	cout << "| 3. Add element to end of list .                             |\n";
	cout << "| 4. Add element after specific element in list.              |\n";
	cout << "| 5. Add element before specific element in list.             |\n";
	cout << "| 6. Sort list.                                               |\n";
	cout << "| 7. Linear search.                                           |\n";
	cout << "| 8. Exit                                                     |\n";
	cout << "|_____________________________________________________________|\n";
}

bool PositionChoosing(List *ListParameters)
{
	int positionOfElement;
	if (ListParameters->ListLength == 0)
	{
		return false;
	}
	do
	{
		cout << "Enter position of element(from 1 to " <<
			ListParameters->ListLength <<"):";
		positionOfElement = ReadingValue();
	} while (positionOfElement > ListParameters->ListLength ||
		positionOfElement <= 0);
	clock_t begin = clock();
	if (positionOfElement <= ListParameters->ListLength / 2)
	{
		ListParameters->CurrentNode = ListParameters->Head;
		for (int i = 1; i < positionOfElement; i++)
		{
			ListParameters->CurrentNode = ListParameters->CurrentNode->Next;
		}
		clock_t end = clock();
		double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		cout << elapsed_secs;
		system("pause");
		return true;
	}
	else
	{
		ListParameters->CurrentNode = ListParameters->Tail;
		for (int i = ListParameters->ListLength; i > positionOfElement; i--)
		{
			ListParameters->CurrentNode = ListParameters->CurrentNode->Previous;
		}
		clock_t end = clock();
		double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		cout << elapsed_secs;
		system("pause");
		return true;
	}
}