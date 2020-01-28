#pragma once
#include "DataInOut.h"
#include "TwoStackQueue.h"
#include "Stack.h"

struct TwoStackQueue
{
	Stack ToPush;
	Stack ToPop;
};

int GetFromTwoStack(TwoStackQueue *);
void PushToTwoStack(TwoStackQueue * , int);