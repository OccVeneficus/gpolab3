#pragma once
#include "BufferNode.h"

struct RingBuffer
{
	BufferNode *IndexIn;
	BufferNode *IndexOut;
	int BufferSize;
	BufferNode *Head;
	int FreeSpace;
	int OccupiedSpace;
};

void RingBufferCreation(RingBuffer *);
void BufferInitialisation(RingBuffer *);
void RingBufferPut(RingBuffer *, int);
int RingBufferGet(RingBuffer *);
void RingBufferDeleting(RingBuffer *);