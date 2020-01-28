#include "DataInOut.h"
#include "Stack.h"
#include "RingBuffer.h"

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
	cout << "| Choose ADT from list below by typing it number.             |\n";
	cout << "| 1. Stack                                                    |\n";
	cout << "| 2. Ring Buffer Queue                                        |\n";
	cout << "| 3. Two stacks Queue                                         |\n";
	cout << "| 4. Ring Buffer Queue                                        |\n";
	cout << "| 0. Quit program                                             |\n";
	cout << "|_____________________________________________________________|\n";
}

void StackMenuPrinting()
{
	cout << endl;
	cout << " ______________________________________________________________\n";
	cout << "|                    ||||||STACK MENU||||||                   |\n";
	cout << "| Choose action from list below by typing it number.          |\n";
	cout << "| 1. Push value in stack                                      |\n";
	cout << "| 2. Pop value from stack                                     |\n";
	cout << "| 3. Delete current stack                                     |\n";
	cout << "| 0. Previous menu                                            |\n";
	cout << "|_____________________________________________________________|\n";
}

void BufferMenuPrinting()
{
	cout << endl;
	cout << " ______________________________________________________________\n";
	cout << "|                ||||||RING BUFFER MENU||||||                 |\n";
	cout << "| Choose action from list below by typing it number.          |\n";
	cout << "| 1. Show free space                                          |\n";
	cout << "| 2. Show occupied space                                      |\n";
	cout << "| 3. Add element to buffer                                    |\n";
	cout << "| 4. Delete element from buffer                               |\n";
	cout << "| 0. Previous menu (buffer will be deleted)                   |\n";
	cout << "|_____________________________________________________________|\n";
}

void TwoStackQueueMenuPrinting()
{
	cout << endl;
	cout << " ______________________________________________________________\n";
	cout << "|              ||||||TWO STACK QUEUE MENU||||||               |\n";
	cout << "| Choose action from list below by typing it number.          |\n";
	cout << "| 1. Add element to queue                                     |\n";
	cout << "| 2. Delete element from queue                                |\n";
	cout << "| 0. Previous menu (queue will be deleted)                    |\n";
	cout << "|_____________________________________________________________|\n";
}

void RingQueueMenuPrinting()
{
	cout << endl;
	cout << " ______________________________________________________________\n";
	cout << "|            ||||||RING BUFFER QUEUE MENU||||||               |\n";
	cout << "| Choose action from list below by typing it number.          |\n";
	cout << "| 1. Add element to queue                                     |\n";
	cout << "| 2. Delete element from queue                                |\n";
	cout << "| 0. Previous menu (queue will be deleted)                    |\n";
	cout << "|_____________________________________________________________|\n";
}

void TwoStackQueuePrinting(Stack *stackToPop, Stack *stackToPush)
{
	cout << "Current stack: ";
	if ((stackToPush->Empty) && (stackToPop->Empty))
	{
		cout << "Empty." << endl;
	}
	else
	{
		for (int j = stackToPop->TopIndex; j >= 0; j--)
		{
			cout << stackToPop->Buffer[j] << ' ';
		}
		for (int i = 0; i <= stackToPush->TopIndex; i++)
		{
			cout << stackToPush->Buffer[i] << ' ';
		}
	}
}

void StackPrinting(Stack *stackParameters)
{
	cout << "Current stack: ";
	if (stackParameters->Empty == true)
	{
		cout << "\aEmpty." << endl;
	}
	else
	{
		for (int i = 0; i <= stackParameters->TopIndex; i++)
		{
			cout << stackParameters->Buffer[i] << ' ';
		}
	}
}

void BufferPrinting(RingBuffer *bufferparameters)
{
 	BufferNode *nodeToPrint = bufferparameters->Head;
	for(int i = 0; i < bufferparameters->BufferSize; i++)
	{
		if (nodeToPrint->Useful)
		{
			cout << ' ' << nodeToPrint->Data << ' ';
		}
		nodeToPrint = nodeToPrint->NextBufferNode;
	}
}