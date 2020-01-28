#pragma once

struct Stack
{
	int *Buffer;
	int BufferSize;
	int TopIndex;
	bool Empty;
};

void StackCreation(Stack *);
void StackPush(Stack *, int);
void DeletingStack(Stack *);
int StackPop(Stack *);