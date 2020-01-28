#include "RingBufferQueue.h"

void RingBufferQueueCreation(RingBufferQueue *queueParameters)
{
	RingBufferCreation(&queueParameters->Queue);
	queueParameters->IsFull = false;
}

void RingQueuePut(RingBufferQueue *queueParameters, int data)
{
	if (queueParameters->IsFull)
	{
		int newSize = queueParameters->Queue.BufferSize * 1.5;
		RingBufferQueue newQueue;
		int userBufferSize;
		BufferInitialisation(&newQueue.Queue);
		newQueue.Queue.BufferSize = newSize;
		newQueue.Queue.OccupiedSpace = 0;
		newQueue.Queue.FreeSpace = newSize;
		BufferNode *node = newQueue.Queue.Head;
		for (int i = 0; i < newSize - 1; i++)
		{
			BufferNode *addedNode = new BufferNode;
			BufferNode *tempNode = node->NextBufferNode;
			node->NextBufferNode = addedNode;
			addedNode->NextBufferNode = tempNode;
			node = addedNode;
		}
		while (queueParameters->Queue.OccupiedSpace != 0)
		{
			RingBufferPut(&newQueue.Queue, RingBufferGet(&queueParameters->Queue));
		}
		queueParameters->Queue = newQueue.Queue;
	}
	RingBufferPut(&queueParameters->Queue, data);
	if (queueParameters->Queue.OccupiedSpace == queueParameters->Queue.BufferSize)
	{
		queueParameters->IsFull = true;
	}
	else
	{
		queueParameters->IsFull = false;
	}
}

int RingQueueGet(RingBufferQueue *queueParameters)
{
	return RingBufferGet(&queueParameters->Queue);
}
