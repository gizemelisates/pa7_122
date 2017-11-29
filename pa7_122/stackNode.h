#ifndef STACKNODE_H
#define STACKNODE_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class StackNode
{
public:
	StackNode(string newDate);
	StackNode(const StackNode &copy);
	~StackNode();

	string getDate() const;
	StackNode *getNext() const;

	void setDate(const string newDate);
	void setNext(StackNode *const newNext);

public:
	string mDate;
	StackNode *mpNext;
};

#endif