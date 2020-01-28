#include "RingBuffer.h"
#include "DataInOut.h"

void BufferInitialisation(RingBuffer *bufferParameters)
{
	BufferNode *rootNode = new BufferNode;
	bufferParameters->Head = rootNode;
	bufferParameters->Head->NextBufferNode = bufferParameters->Head;
	bufferParameters->IndexIn = bufferParameters->Head;
	bufferParameters->IndexOut = bufferParameters->Head;
}

void RingBufferCreation(RingBuffer *bufferParameters)
{
	int userBufferSize;
	BufferInitialisation(bufferParameters);
	do
	{
		cout << endl << "Enter buffer size (only positive integer):";
		userBufferSize = ReadingValue();
	} 
	while (userBufferSize <= 0);
	bufferParameters->BufferSize = userBufferSize;
	bufferParameters->FreeSpace = userBufferSize;
	bufferParameters->OccupiedSpace = 0;
	BufferNode *node = bufferParameters->Head;
	for (int i = 0; i < userBufferSize - 1; i++)
	{
		BufferNode *addedNode = new BufferNode;
		BufferNode *tempNode = node->NextBufferNode;
		node->NextBufferNode = addedNode;
		addedNode->NextBufferNode = tempNode;
		node = addedNode;
	}
}

void RingBufferPut(RingBuffer *bufferParameters, int value)
{
	bufferParameters->IndexIn->Data = value;
	bufferParameters->IndexIn->Useful = true;
	bufferParameters->IndexIn = bufferParameters->IndexIn->NextBufferNode;
	bufferParameters->FreeSpace--;
	bufferParameters->OccupiedSpace++;
	if (bufferParameters->OccupiedSpace > bufferParameters->BufferSize)
	{
		bufferParameters->FreeSpace = 0;
		bufferParameters->OccupiedSpace = bufferParameters->BufferSize;
		bufferParameters->IndexOut = bufferParameters->IndexOut->NextBufferNode;
	}
}

int RingBufferGet(RingBuffer *bufferParameters)
{
	BufferNode *tempNode = bufferParameters->IndexOut;
	bufferParameters->IndexOut->Useful = false;
	bufferParameters->IndexOut = bufferParameters->IndexOut->NextBufferNode;
	bufferParameters->FreeSpace++;
	bufferParameters->OccupiedSpace--;
	return tempNode->Data;
}

void RingBufferDeleting(RingBuffer *bufferParameters)
{
	BufferNode *nodeToDelete = bufferParameters->Head;
	for (int i = 0; i < bufferParameters->BufferSize; i++)
	{
		nodeToDelete = nodeToDelete->NextBufferNode;
		delete bufferParameters->Head;
		bufferParameters->Head = nodeToDelete;
	}
}
