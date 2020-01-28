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
	while (true)
	{
		string inputValue;
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
			return stoi(inputValue);
		}
	}
}

void TreePrinting(string prefix, RedBlackNode *node, bool isLeft)
{
	if (node != nullptr)
	{
		cout << prefix;
		wcout << (isLeft ? "|-- " : "\\-- ");
		cout << node->GetKey() << (node->IsRed() ? ": Red" : ": Black") << endl;
		TreePrinting(prefix + (isLeft ? "|   " : "    "),
			node->GetLeft(), true);
		TreePrinting(prefix + (isLeft ? "|   " : "    "),
			node->GetRight(), false);
	}
}

void TreePrinting(RedBlackNode * node)
{
	TreePrinting("", node, false);
}

void AVLTreePrinting(string prefix, AVLNode * node,  bool isLeft)
{
	if (node != nullptr)
	{
		cout << prefix;
		wcout << (isLeft ? "|-- " : "\\-- ");
		cout << node->GetKey() << endl;
		AVLTreePrinting(prefix + (isLeft ? "|   " : "    "),
			node->GetLeft(), true);
		AVLTreePrinting(prefix + (isLeft ? "|   " : "    "),
			node->GetRight(), false);
	}
}

void AVLTreePrinting(AVLNode * node)
{
	AVLTreePrinting("", node, false);
}

void MainMenuPrinting()
{
	cout << endl;
	cout << " ______________________________________________________________\n";
	cout << "|                       ||||||MENU||||||                      |\n";
	cout << "| Choose tree from list below by typing it number.            |\n";
	cout << "| 1. Red-black tree                                           |\n";
	cout << "| 2. AVL-Tree                                                 |\n";
	cout << "| 0. Quit program                                             |\n";
	cout << "|_____________________________________________________________|\n";
}

void RBTMenuPrinting()
{
	cout << endl;
	cout << " ______________________________________________________________\n";
	cout << "|                   ||||||RBTree MENU||||||                   |\n";
	cout << "| Choose action from list below by typing it number.          |\n";
	cout << "| 1. Add value                                                |\n";
	cout << "| 2. Delete value                                             |\n";
	cout << "| 3. Search value                                             |\n";
	cout << "| 0. Quit                                                     |\n";
	cout << "|_____________________________________________________________|\n";
}

void AVLMenuPrinting()
{
	cout << endl;
	cout << " ______________________________________________________________\n";
	cout << "|                  ||||||AVL Tree MENU||||||                  |\n";
	cout << "| Choose action from list below by typing it number.          |\n";
	cout << "| 1. Add value                                                |\n";
	cout << "| 2. Delete value                                             |\n";
	cout << "| 3. Search value                                             |\n";
	cout << "| 0. Quit                                                     |\n";
	cout << "|_____________________________________________________________|\n";
}

int GetMenuItem()
{
	int menuItem;
	do
	{
		cout << "Enter menu item from list above (integer only):";
		menuItem = ReadingValue();
		cout << endl;
	} 
	while (menuItem > 4 && menuItem < 0);
	return menuItem;
}

