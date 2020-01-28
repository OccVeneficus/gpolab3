#include "DataInOut.h"
#include "Menus.h"

int main()
{
	srand(time(nullptr));
	RedBlackTree userTree;
	AVLTree userAVLTree;
	int menuItem;
	do
	{
		system("cls");
		MainMenuPrinting();
		do
		{
			cout << "Enter menu item from list above (integer only):";
			menuItem = ReadingValue();
			cout << endl;
		} 
		while (menuItem > 2 && menuItem < 0);
		switch (menuItem)
		{
			case 1:
			{
				RBTMenu(&userTree);
				break;
			}
			case 2:
			{
				AVLMenu(&userAVLTree);
				break;
			}
		}
	} 
	while (menuItem != EXIT_MENU_ITEM);
	system("cls");
	return 0;
}