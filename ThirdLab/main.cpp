#include "DataInOut.h"
#include "Stack.h"
#include "RingBuffer.h"
#include "TwoStackQueue.h"
#include "Menus.h"

int main()
{
	Stack currentStack;
	currentStack.Empty = true;
	StackCreation(&currentStack);
	int menuItem;
	do
	{
		MainMenuPrinting();
		do
		{
			cout << ">";
			menuItem = ReadingValue();
		} 
		while (menuItem > 4 || menuItem < 0);
		switch (menuItem)
		{
			case 1:
			{
				system("cls");
				StackMenu(&currentStack);
				break;
			}
			case 2:
			{
				system("cls");
				RingBufferMenu();
				break;
			}
			case 3:
			{
				system("cls");
				TwoStackQueueMenu();
				break;
			}
			case 4:
			{
				system("cls");
				RingBufferQueueMenu();
				break;
			}
		}
	} 
	while (menuItem != EXIT_MENU_ITEM);
	DeletingStack(&currentStack);
	return 0;
}