#include "Menus.h"

void MainMenu()
{
	BinaryTree userTree;
	Treap userTreap;
	int menuItem;
	do
	{
		MainMenuPrinting();
		do
		{
			cout << "Choose number from list above(integer only):";
			menuItem = ReadingValue();
		} 
		while (menuItem > 2 || menuItem < 0);
		switch (menuItem)
		{
		case 1:
			{
				system("cls");
				BinaryTreeMenu(&userTree);
				system("cls");
				break;
			}
		case 2:
			{
				system("cls");
				TreapMenu(&userTreap);
				system("cls");
				break;
			}
		}
	} 
	while (menuItem != EXIT_MENU_ITEM);
	system("cls");
}

void BinaryTreeMenu(BinaryTree *userTree)
{
	int menuItem;
	Node *toShow;
	do
	{
		int value;
		system("cls");
		TreePrinting(userTree->GetRoot());
		BinaryMenuPrinting();
		do
		{
			cout << "Choose number from list above(integer only):";
			menuItem = ReadingValue();
		}
		while (menuItem > 5 || menuItem < 0);
		switch (menuItem)
		{
		case 1:
			{
				cout << "Enter value you want to add: ";
				value = ReadingValue();
				userTree->AddNode(value);
				break;
			}
		case 2:
			{
				cout << "Enter value you want to delete:";
				value = ReadingValue();
				Node *root = userTree->GetRoot();
				userTree->DeleteNode(value, root);
				break;
			}
		case 3:
			{
				cout << "Enter value you want to search:";
				value = ReadingValue();
				if ((toShow = userTree->SearchNode(value, userTree->GetRoot()))
					!= nullptr)
				{
					cout << "Finded: " << toShow->GetData();
					system("pause");
					break;
				}
				cout << "There is no " << value << " in this tree.";
				system("pause");
				break;
			}
		case 4:
			{
				if (userTree->GetRoot() == nullptr)
				{
					cout << "No elements in this tree. ";
					system("pause");
					break;
				}
				cout << "Minimum element = " << 
					userTree->SearchMin()->GetData() << " .";
				system("pause");
				break;
			}
		case 5:
			{
				if (userTree->GetRoot() == nullptr)
				{
					cout << "No elements in this tree. ";
					system("pause");
					break;
				}
				cout << "Maximum element = " <<
					userTree->SearchMax()->GetData() << " .";
				system("pause");
				break;
			}
		}
	} 
	while (menuItem != EXIT_MENU_ITEM);
	system("cls");
}

void TreapMenu(Treap *userTreap)
{
	int menuItem;
	TreapNode *toShow;
	do
	{
		int value;
		system("cls");
		TreapPrinting(userTreap->GetRoot());
		TreapMenuPrinting();
		do
		{
			cout << "Choose number from list above(integer only):";
			menuItem = ReadingValue();
		} 
		while (menuItem > 5 || menuItem < 0);
		switch (menuItem)
		{
		case 1:
			{
				cout << "Enter value you want to add: ";
				value = ReadingValue();
				userTreap->Add(value);
				break;
			}
		case 2:
			{
				cout << "Enter value you want to delete:";
				value = ReadingValue();
				userTreap->Remove(value);
				break;
			}
		case 3:
		{
			cout << "Enter value you want to search:";
			value = ReadingValue();
			if ((toShow = userTreap->Search(value, userTreap->GetRoot()))
				!= nullptr)
			{
				cout << "Finded: " << toShow->GetKey();
				system("pause");
				break;
			}
			cout << "There is no " << value << " in this tree.";
			system("pause");
			break;
		}
		case 4:
		{
			cout << "Enter value you want to add: ";
			value = ReadingValue();
			TreapNode *newNode = new TreapNode(value, rand()%100);
			toShow = userTreap->GetRoot();
 			userTreap->OptimisedAdd(toShow, newNode);
			break;
		}
		case 5:
		{
			cout << "Enter value you want to delete:";
			value = ReadingValue();
			toShow = userTreap->GetRoot();
			userTreap->OptimisedRemove(value, toShow);
			break;
		}
		}
	} while (menuItem != EXIT_MENU_ITEM);
	system("cls");
}