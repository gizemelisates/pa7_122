#include "Stack.h"

Stack::Stack()
{
	mSize = 0;
	mpTop = nullptr;
}

Stack::Stack(const Stack &copy)
{
	mSize = copy.getSize();
	mpTop = copy.getTop();
}

Stack::~Stack()
{
}

bool Stack::isEmpty(StackNode *pTop)
{
	if (pTop == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

string Stack::peek()
{
	return (mpTop->getDate());
}

void Stack::push(string newDate)
{
	StackNode *pMem = nullptr;

	pMem = new StackNode(newDate);

	if (pMem != nullptr)
	{
		pMem->setNext(mpTop);
		mpTop = pMem;
	}
}

void Stack::pop(string *date)
{
	StackNode *pTemp = nullptr;

	pTemp = getTop();

	*date = pTemp->getDate();
	setTop(mpTop->getNext());
	delete pTemp;
}

void Stack::emptyStack()
{
	string date = "";

	while (!isEmpty(mpTop))
	{
		if (mpTop != nullptr)
		{
			pop(&date);
		}
	}
}

void Stack::printStack()
{
	while (!isEmpty(mpTop))
	{
		if (mpTop != nullptr)
		{
			cout << mpTop->getDate() << endl;
			mpTop = mpTop->getNext();
		}
	}
}

int Stack::getSize() const
{
	return mSize;
}

StackNode *Stack::getTop() const
{
	return mpTop;
}

void Stack::setSize()
{
	int index = 0;
	StackNode *pCur = nullptr;

	pCur = mpTop;

	while (pCur != nullptr)
	{
		pCur = pCur->getNext();
		index++;
	}

	mSize = index;
}

void Stack::setTop(StackNode *const newTop)
{
	mpTop = newTop;
}