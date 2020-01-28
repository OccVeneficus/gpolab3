#include "DynamicArray.h"
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(NULL));
	int index;
	DynamicArray arrayParameters;
	CreatingArray(arrayParameters);
	cout << "\n";
	int menuItem;
	do 
	{
		PrintingArray(arrayParameters);
		cout << endl;
		PrintingMenuText();
		do
		{
			cout << "Enter menu item(you can only use numbers from 1 to 8): ";
			menuItem = ReadingValue();
		} 
		while (menuItem > 8 || menuItem <= 0);
		switch (menuItem)
		{
		case 1:
			{
			system("cls");
			DeletingElement(arrayParameters);
			break;
			}
		case 2:
			{
			system("cls");
			AddingAfterIndex(arrayParameters, 0);
			break;
			}
		case 3:
			{
			system("cls");
			AddingAfterIndex(arrayParameters, arrayParameters.Length);
			break;
			}
		case 4:
			{
			system("cls");
			do
			{
				cout << "Enter index of element after witch";
				cout << "you want to put new element: ";
				index = ReadingValue() + 1;
			} while (index < 0 || index >= arrayParameters.Length);
			AddingAfterIndex(arrayParameters, index);
			break;
			}
		case 5:
			{
			system("cls");
			SortingArray(arrayParameters);
			break;
			}
		case 6:
			{
			system("cls");
			LinearSearching(arrayParameters);
			break;
		}
		case 7:
			{
			system("cls");
			BinarSearching(arrayParameters);
			break;
			}
		}
	} while (menuItem != 8);
	DeletingArray(arrayParameters.Array);
	cout << "Ending session...";
	return 0;
}