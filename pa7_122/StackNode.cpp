#include "StackNode.h"

StackNode::StackNode(string newDate)
{
	mDate = newDate;
	mpNext = nullptr;
}

StackNode::StackNode(const StackNode &copy)
{
	mDate = copy.getDate();
	mpNext = copy.getNext();
}

StackNode::~StackNode()
{
}

string StackNode::getDate() const
{
	return mDate;
}

StackNode *StackNode::getNext() const
{
	return mpNext;
}

void StackNode::setDate(const string newDate)
{
	mDate = newDate;
}

void StackNode::setNext(StackNode *const newNext)
{
	mpNext = newNext;
}