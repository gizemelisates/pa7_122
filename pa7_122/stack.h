#ifndef STACK_H
#define STACK_H
#define _CRT_SECURE_NO_WARNINGS

#include "StackNode.h"

class Stack
{
public:
	Stack();
	Stack(const Stack &copy);
	~Stack();

	bool isEmpty(StackNode *pTop);
	string peek();
	void push(string newDate);
	void pop(string *date);
	void emptyStack();
	void printStack();

	int getSize() const;
	StackNode *getTop() const;

	void setSize();
	void setTop(StackNode *const newTop);
private:
	int mSize;
	StackNode *mpTop;
};

#endif