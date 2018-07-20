#include "stack.h"

/******************************************************/
Stack::Stack(int size)
{

	stackArray = new char[size];
	stackSize = size;
	top = -1;
}
/******************************************************/
void Stack::push(char ch)
{

	if (isFull())
		cout << "The stack is full.\n";
	else
	{
		top++;
		stackArray[top] = ch;
	}
}
/******************************************************/
void Stack::pop(char &ch)
{

	if (isEmpty())
		cout << "The stack is empty.\n";
	else
	{
		ch = stackArray[top];
		top--;
	}
}
/******************************************************/
bool Stack::isFull(void)
{

	bool status;

	if (top == stackSize - 1)
		status = true;
	else
		status = false;

	return status;
}
/******************************************************/
bool Stack::isEmpty(void)
{
	bool status;

	if (top == -1)
		status = true;
	else
		status = false;

	return status;
}
/******************************************************/
char Stack::Top() { return stackArray[top]; }
/******************************************************/

/******************************************************/
