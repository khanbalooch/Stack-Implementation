#ifndef INTSTACK_H
#define INTSTACK_H
#include <iostream>
#include <string>
using namespace std;
class Stack
{
  private:
	char *stackArray;
	int stackSize;
	int top;

  public:
	Stack(int);
	void push(char);
	void pop(char &);
	char Top(void);
	bool isFull(void);
	bool isEmpty(void);
};

#endif
