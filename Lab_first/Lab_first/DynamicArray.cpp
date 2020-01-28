#include "DynamicArray.h"

void CreatingArray(DynamicArray &arrayParameters)
{
	arrayParameters.Length = 8;
	arrayParameters.Capacity = 8;
	arrayParameters.Array = new int[arrayParameters.Capacity];
	for (int i = 0; i < arrayParameters.Length; i++)
	{
		arrayParameters.Array[i] = rand() % 10;
	}
}

void PrintingArray(DynamicArray &arrayParameters)
{
	cout << "Current array: ";
	for (int i = 0; i < arrayParameters.Length; i++)
	{
		cout << " " << arrayParameters.Array[i] << " ";
	}
	cout << "\n";
}

void PrintingMenuText()
{
	cout << " ______________________________________________________________\n";
	cout << "|                       ||||||MENU||||||                      |\n";
	cout << "|List of available functions:                                 |\n";
	cout << "|(To choose function type it number from list below)          |\n";
	cout << "| 1. Delete element from array.                               |\n";
	cout << "| 2. Add element to begin of array.                           |\n";
	cout << "| 3. Add element to end of array.                             |\n";
	cout << "| 4. Add element after specific element in array.             |\n";
	cout << "| 5. Sort array.                                              |\n";
	cout << "| 6. Linear search.                                           |\n";
	cout << "| 7. Binar search.                                            |\n";
	cout << "| 8. Exit                                                     |\n";
	cout << "|_____________________________________________________________|\n";
}

void DeletingElement(DynamicArray &arrayParameters)
{
	PrintingArray(arrayParameters);
	cout << "\n";
	int indexToDelete;
	do
	{
		cout << "Enter index of element you want to delete: ";
		indexToDelete = ReadingValue();
	} while (indexToDelete < 0 || indexToDelete >= arrayParameters.Length);
	for (int i = indexToDelete; i < arrayParameters.Length; i++)
	{
		arrayParameters.Array[i] = arrayParameters.Array[i + 1];
	}
	--arrayParameters.Length;
}

void AddingAfterIndex(DynamicArray &arrayParameters, int index) 
{
	PrintingArray(arrayParameters);
	if (arrayParameters.Length == arrayParameters.Capacity)
	{
		RecreatingArray(arrayParameters);
	}
	cout << "\n";
	cout << "Enter value you want to add to array: ";
	int value = ReadingValue();
	for (int i = arrayParameters.Length - 1; i >= index; i--)
	{
		arrayParameters.Array[i + 1] = arrayParameters.Array[i];
	}
	arrayParameters.Array[index] = value;
	++arrayParameters.Length;
}

void SortingArray(DynamicArray &arrayParameters)
{
	for (int i = 1; i < arrayParameters.Length; i++)
	{
		for (int j = i; j > 0 && arrayParameters.Array[j - 1] >
			arrayParameters.Array[j]; j--)
		{
			swap(arrayParameters.Array[j - 1], arrayParameters.Array[j]);
		}
	}
	cout << "\n";
	cout << "Sorted array\n";
}

void LinearSearching(DynamicArray &arrayParameters)
{
	PrintingArray(arrayParameters);
	cout << "\n";
	cout << "Enter value you want to find: ";
	int valueToSearch = ReadingValue();
	int index = -1;
	for (int i = 0; i < arrayParameters.Length; i++)
	{
		if (arrayParameters.Array[i] == valueToSearch)
		{
			index = i;
		}
	}
	if (index != -1)
	{
		cout << "\n";
		cout << "There is at least 1 element ";
		cout << valueToSearch;
		cout << " in array. Index: ";
		cout << index;
		cout << "\n";
	}
	else
	{
		cout << "\n";
		cout << "There is no ";
		cout << valueToSearch;
		cout << " in current Array.";
		cout << "\n";
	}
}

void BinarSearching(DynamicArray &arrayParameters)
{
	SortingArray(arrayParameters);
	PrintingArray(arrayParameters);
	cout << "\n";
	cout << "What value you want to find: ";
	int valueToSearch = ReadingValue();
	int leftEnd = 0;
	int rightEnd = arrayParameters.Length;
	int middleOfArray;
	bool flag = false;
	while (flag == false && leftEnd <= rightEnd)
	{
		middleOfArray = (leftEnd + rightEnd) / 2;

		if (arrayParameters.Array[middleOfArray] == valueToSearch)
		{
			flag = true;
		}
		if (arrayParameters.Array[middleOfArray] > valueToSearch)
		{
			rightEnd = middleOfArray - 1;
		}
		else
		{
			leftEnd = middleOfArray + 1;
		}
	}
	if (flag)
	{
		cout << "\n";
		cout << "There is at least 1 element ";
		cout << valueToSearch;
		cout << " in array. Index: ";
		cout<< middleOfArray;
		cout << "\n";
	}
	else
	{
		cout << "\n";
		cout << "There is no ";
		cout << valueToSearch;
		cout << " in current Array.";
		cout << "\n";
	}
}

void DeletingArray(int *currentArray) 
{
	delete[] currentArray;
}

void RecreatingArray(DynamicArray &arrayParameters)
{
	const int buffer = 8;
	int *newArray = new int[arrayParameters.Capacity + buffer];
	for (int i = 0; i < arrayParameters.Length; i++)
	{
		newArray[i] = arrayParameters.Array[i];
	}
	DeletingArray(arrayParameters.Array);
	arrayParameters.Array = newArray;
}

int ReadingValue()
{
	int taxableIncome;
	while(true) 
	{
		if (cin >> taxableIncome) 
		{
			break;
		}
		else 
		{
			cout << "You can enter only an integer: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	return taxableIncome;
}