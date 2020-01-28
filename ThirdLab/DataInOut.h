#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include "Stack.h"
#include "RingBuffer.h"

const int EXIT_MENU_ITEM = 0;
const int BUFFER = 8;

using namespace std;
bool CheckingForInteger(string);
int ReadingValue();
void MainMenuPrinting();
void StackMenuPrinting();
void StackPrinting(Stack *);
void BufferMenuPrinting();
void BufferPrinting(RingBuffer *);
void TwoStackQueuePrinting(Stack *,Stack *);
void TwoStackQueueMenuPrinting();
void RingQueueMenuPrinting();