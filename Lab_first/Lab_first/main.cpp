#include "DynamicArray.h"

int main()
{
	srand(time(nullptr));
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
		system("cls");
		switch (menuItem)
		{
			case 1:
			{
				DeletingElement(arrayParameters);
				break;
			}
			case 2:
			{
				AddingAfterIndex(arrayParameters, 0);
				break;
			}
			case 3:
			{
				AddingAfterIndex(arrayParameters, arrayParameters.Length);
				break;
			}
			case 4:
			{
				int index;
				do
					{
						cout << "Enter index of element after witch";
						cout << "you want to put new element: ";
						index = ReadingValue() + 1;
					} 
				while (index < 0 || index >= arrayParameters.Length);
				AddingAfterIndex(arrayParameters, index);
				break;
			}
			case 5:
			{
				SortingArray(arrayParameters);
				break;
			}
			case 6:
			{
				LinearSearching(arrayParameters);
				break;
			}
			case 7:
			{
				BinarSearching(arrayParameters);
				break;
			}
		}
	} 
	while (menuItem != EXIT_MENU_ITEM);
	DeletingArray(arrayParameters.Array);
	cout << "Ending session...";
	return 0;
}