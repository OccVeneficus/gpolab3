#include "DataInOut.h"
#include "Stack.h"
#include "TwoStackQueue.h"

int GetFromTwoStack(TwoStackQueue *queue)
{
	int value;
	if (queue->ToPop.Empty)
	{
		while (!(queue->ToPush.Empty))
		{
			value = StackPop(&queue->ToPush);
			StackPush(&queue->ToPop, value);
		}
	}
	return StackPop(&queue->ToPop);
}

void PushToTwoStack(TwoStackQueue *queue , int value)
{
	StackPush(&queue->ToPush, value);
}