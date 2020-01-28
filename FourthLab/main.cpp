#include "DataInOut.h"
#include "ClassesOutput.h"
#include "Chain.h"
#include "Node.h"
#include "HashTable.h"
#include "Vocabulary.h"
#include "Menus.h"
#include <windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int menuItem;
	Dictionary userDictionary;
	HashTable userTable;
	do
	{
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
				DictionaryMenu(&userDictionary);
				system("cls");
				break;
			}
			case 2:
			{
				HashTableMenu(&userTable);
				system("cls");
				break;
			}
		}
	}
	while (menuItem != EXIT_MENU_ITEM);
	return 0;
}