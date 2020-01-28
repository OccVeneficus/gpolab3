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

void MainMenuPrinting()
{
	cout << endl;
	cout << " ______________________________________________________________\n";
	cout << "|                       ||||||MENU||||||                      |\n";
	cout << "| Choose option from list below by typing it number.          |\n";
	cout << "| 1. Binary Search Tree                                       |\n";
	cout << "| 2. Treap                                                    |\n";
	cout << "| 0. Quit program                                             |\n";
	cout << "|_____________________________________________________________|\n";
}

void BinaryMenuPrinting()
{
	cout << endl;
	cout << " ______________________________________________________________\n";
	cout << "|                    ||||||BINARY TREE||||||                  |\n";
	cout << "| Choose option from list below by typing it number.          |\n";
	cout << "| 1. Add value                                                |\n";
	cout << "| 2. Delete value                                             |\n";
	cout << "| 3. Search value                                             |\n";
	cout << "| 4. Search minimum                                           |\n";
	cout << "| 5. Search maximum                                           |\n";
	cout << "| 0. Quit program                                             |\n";
	cout << "|_____________________________________________________________|\n";
}

void TreapMenuPrinting()
{
	cout << endl;
	cout << " ______________________________________________________________\n";
	cout << "|                       ||||||TREAP||||||                     |\n";
	cout << "| Choose option from list below by typing it number.          |\n";
	cout << "| 1. Add value (split, merge x 2)                             |\n";
	cout << "| 2. Delete value (split x2, merge)                           |\n";
	cout << "| 3. Search value                                             |\n";
	cout << "| 4. Add value (optimised)                                    |\n";
	cout << "| 5. Delete value (optimised)                                 |\n";
	cout << "| 0. Quit program                                             |\n";
	cout << "|_____________________________________________________________|\n";
}

void TreePrinting(string prefix, Node *node, bool isLeft)
{
	if (node != nullptr)
	{
		cout << prefix;
		wcout << (isLeft ? "|-- " : "\\-- ");
		cout << node->GetData() << endl;
		TreePrinting(prefix + (isLeft ? "|   " : "    "),
			node->GetLeft(), true);
		TreePrinting(prefix + (isLeft ? "|   " : "    "),
			node->GetRight(), false);
	}
}

void TreePrinting(Node * node)
{
	TreePrinting("", node, false);
}

void TreapPrinting(string prefix, TreapNode *node, bool isLeft)
{
	if (node != nullptr)
	{
		cout << prefix;
		wcout << (isLeft ? "|-- " : "\\-- ");
		cout << node->GetKey() <<" ; "<< node->GetPriority()<<  endl;
		TreapPrinting(prefix + (isLeft ? "|   " : "    "),
			node->GetLeft(), true);
		TreapPrinting(prefix + (isLeft ? "|   " : "    "),
			node->GetRight(), false);
	}
}

void TreapPrinting(TreapNode *node)
{
	TreapPrinting("", node, false);
}
