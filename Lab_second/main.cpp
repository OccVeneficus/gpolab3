#include "LinkedLists.h"
#include "DataInputOutput.h"
#include <cstdlib>

const int EXIT_MENU_ITEM = 8;

int main()
{
	List listParameters;
	int menuItem;
	cout << "Enter Head and Tail of new list." << endl;
	Initialisation(&listParameters);
	do
	{
		ListPrinting(&listParameters);
		MenuPrinting();
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
				PositionChoosing(&listParameters);
				DeletingElement(&listParameters);
				break;
			}
			case 2:
			{
				system("cls");
				cout << "Enter value you want to add in the begining of list:";
				AddingElement(ReadingValue(), &listParameters,
					listParameters.Head);
				break;
			}
			case 3:
			{
				system("cls");
				cout << "Enter value you want to add in the end of list: ";
				AddingElement(ReadingValue(), &listParameters,
					listParameters.Tail);
				break;
			}
			case 4:
			{
				system("cls");
				if (PositionChoosing(&listParameters) == false)
				{
					cout << "There is no elements in list yet.";
					break;
				}
				cout << endl << "Enter value: ";
				AddingElement(ReadingValue(), &listParameters,
					listParameters.CurrentNode);
				break;
			}
			case 5:
			{
				system("cls");
				if (PositionChoosing(&listParameters) == false)
				{
					cout << "There is no elements in list yet.";
					break;
				}
				cout << endl << "Enter value: ";
				AddingElement(ReadingValue(), &listParameters,
					listParameters.CurrentNode->Previous);
				break;
			}
			case 6:
			{
				system("cls");
				BubbleSort(&listParameters);
				break;
			}
			case 7:
			{
				system("cls");
				cout << "Enter value you want to find." << endl;
				SearchingElement(&listParameters, ReadingValue());
				break;
			}
		}
	} 
	while (menuItem != EXIT_MENU_ITEM);
	DeletingAllList(&listParameters);
	return 0;
}