#include "DataInOut.h"
#include "Stack.h"
#include "TwoStackQueue.h"


void StackCreation(Stack *stackParameters)
{
	stackParameters->Buffer = new int[BUFFER];
	stackParameters->BufferSize = BUFFER;
	stackParameters->TopIndex = -1;
	stackParameters->Empty = true;
}

void StackBufferRecreation(Stack *stackParameters)
{
	int newSize = stackParameters->BufferSize*1.5;
	stackParameters->BufferSize = newSize;
	int *newBuffer = new int[newSize];
	for (int i = 0; i <= stackParameters->TopIndex; i++)
	{
		newBuffer[i] = stackParameters->Buffer[i];
	}
	delete[] stackParameters->Buffer;
	stackParameters->Buffer = newBuffer; 
}

void StackPush(Stack *stackParameters, int valueToPush)
{
	if (stackParameters->BufferSize == stackParameters->TopIndex + 1)
	{
		cout << "Stack is full." << endl;
	}
	else
	{
		stackParameters->TopIndex++;
		stackParameters->Buffer[stackParameters->TopIndex] = valueToPush;
		stackParameters->Empty = false;
	}
}

void DeletingStack(Stack *stackParameters)
{
	delete[] stackParameters->Buffer;
	StackCreation(stackParameters);
}

int StackPop(Stack *stackParameters)
{
	int valueToPop = stackParameters->Buffer[stackParameters->TopIndex];
	stackParameters->TopIndex--;
	if (stackParameters->TopIndex == -1)
	{
		stackParameters->Empty = true;
	}
	return valueToPop;
}