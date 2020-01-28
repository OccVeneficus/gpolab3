#pragma once

struct BufferNode
{
	int Data;
	BufferNode *NextBufferNode;
	bool Useful = false;
};