#include "List.h"

List::List()
{
	mpHead = nullptr;
}

List::List(const List &copy)
{
	Node *pMem = nullptr, *pCur = nullptr;
	Stack dates;
	int number = 0, ID = 0, units = 0, absence = 0;
	string names = "", email = "", program = "", level = "";

	mpHead = new Node(dates); 
	pMem = mpHead;
	pCur = copy.getHead();

	pMem->setNumber(pCur->getNumber());
	pMem->setID(pCur->getID());
	pMem->setUnits(pCur->getUnits());
	pMem->setAbsence(pCur->getAbsence());
	pMem->setName(pCur->getName());
	pMem->setEmail(pCur->getEmail());
	pMem->setProgram(pCur->getProgram());
	pMem->setLevel(pCur->getLevel());
	pMem->setDates(pCur->getDates());
	pCur = pCur->getNext(); 

	while (pCur != nullptr) 
	{
		
		number = pCur->getNumber();
		ID = pCur->getID();
		units = pCur->getUnits();
		absence = pCur->getAbsence();
		names = pCur->getName();
		email = pCur->getEmail();
		program = pCur->getProgram();
		level = pCur->getLevel();
		pMem->setNext(new Node(dates, number, ID, units, absence, names, email, program, level));
																	 
		pMem = pMem->getNext();
		pCur = pCur->getNext();
	}
}

List::~List()
{
	destroyList();
}

List &List::operator = (const List &rhs)
{
	Node *pMem = nullptr, *pCur = nullptr;
	Stack dates;
	int number = 0, ID = 0, units = 0, absence = 0;
	string names = "", email = "", program = "", level = "";

	mpHead = new Node(dates); 
	pMem = mpHead;
	pCur = rhs.getHead();

	pMem->setNumber(pCur->getNumber());
	pMem->setID(pCur->getID());
	pMem->setUnits(pCur->getUnits());
	pMem->setAbsence(pCur->getAbsence());
	pMem->setName(pCur->getName());
	pMem->setEmail(pCur->getEmail());
	pMem->setProgram(pCur->getProgram());
	pMem->setLevel(pCur->getLevel());
	pMem->setDates(pCur->getDates());
	pCur = pCur->getNext(); 

	while (pCur != nullptr) 
	{
		number = pCur->getNumber();
		ID = pCur->getID();
		units = pCur->getUnits();
		absence = pCur->getAbsence();
		names = pCur->getName();
		email = pCur->getEmail();
		program = pCur->getProgram();
		level = pCur->getLevel();
		pMem->setNext(new Node(dates, number, ID, units, absence, names, email, program, level)); 
												  
		pMem = pMem->getNext();
		pCur = pCur->getNext();
	}

	return (*this);
}

Node *List::makeNode(const Stack newDates, const int newNumber, const int newID, const int newUnits, const int newAbsence, const string newName, const string newEmail, const string newProgram, const string newLevel)
{
	Node *pMem = nullptr;

	pMem = new Node(newDates, newNumber, newID, newUnits, newAbsence, newName, newEmail, newProgram, newLevel);

	return pMem;
}

bool List::isEmpty()
{
	if (mpHead == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void List::insertFront(const Stack newDates, const int newNumber, const int newID, const int newUnits, const int newAbsence, const string newName, const string newEmail, const string newProgram, const string newLevel)
{
	Node *pMem = nullptr;

	pMem = makeNode(newDates, newNumber, newID, newUnits, newAbsence, newName, newEmail, newProgram, newLevel);

	if (pMem != nullptr)
	{
		pMem->setNext(mpHead);
		mpHead = pMem;
	}
}

void List::insertOrder(const Stack newDates, const int newNumber, const int newID, const int newUnits, const int newAbsence, const string newName, const string newEmail, const string newProgram, const string newLevel)
{
	Node *pCur = nullptr, *pPrev = nullptr, *insert = nullptr;

	pCur = mpHead;
	insert = makeNode(newDates, newNumber, newID, newUnits, newAbsence, newName, newEmail, newProgram, newLevel);

	if (pCur == nullptr)
	{
		mpHead = insert;
		pCur = pCur->getNext();
	}
	else
	{
		while ((pCur != nullptr) && (newNumber > pCur->getNumber()))
		{
			pPrev = pPrev;
			pCur = pCur->getNext();
		}
		if (pCur == nullptr)
		{
			pPrev->setNext(insert);
		}
		else if (pPrev != nullptr)
		{
			insert->setNext(pCur);
			pPrev->setNext(insert);
		}
		else
		{
			insert->setNext(mpHead);
			mpHead = insert;
		}
	}
}

void List::insertBack(const Stack newDates, const int newNumber, const int newID, const int newUnits, const int newAbsence, const string newName, const string newEmail, const string newProgram, const string newLevel)
{
	Node *pCur = nullptr, *insert = nullptr;

	pCur = mpHead;
	insert = makeNode(newDates, newNumber, newID, newUnits, newAbsence, newName, newEmail, newProgram, newLevel);

	if (pCur == nullptr)
	{
		mpHead = insert;
	}
	else
	{
		while (pCur->getNext() != nullptr)
		{
			pCur = pCur->getNext();
		}
		pCur->setNext(insert);
	}
}

void List::deleteFront()
{
	Node *deleteNode = nullptr;

	deleteNode = mpHead;

	if (mpHead != nullptr)
	{
		mpHead = mpHead->getNext();
		delete deleteNode;
	}
}

void List::deleteNode(const string searchName)
{
	Node *pCur = nullptr, *pPrev = nullptr;

	pCur = mpHead;

	if (mpHead != nullptr)
	{
		while ((pCur != nullptr) && (pCur->getName() != searchName))
		{
			pPrev = pCur;
			pCur = pCur->getNext();
		}

		if (pCur != nullptr)
		{
			if (pPrev != nullptr)
			{
				pPrev->setNext(pCur->getNext());
				delete pCur;
			}
			else
			{
				mpHead = mpHead->getNext();
				delete pCur;
			}
		}
	}
}

void List::deleteBack()
{
	Node *pCur = nullptr, *pPrev = nullptr;

	if (mpHead != nullptr)
	{
		pCur = mpHead;
		pPrev = mpHead;

		while (pCur->getNext() != nullptr)
		{
			pPrev = pCur;
			pCur = pCur->getNext();
		}

		if (pCur != mpHead)
		{
			delete pCur;
			pPrev->setNext(nullptr);
		}
		else
		{
			delete pCur;
			mpHead = nullptr;
		}
	}
}

void List::printList()
{
	cout << mpHead;
}

void List::destroyList()
{
	destroyList(mpHead);
}

void List::destroyList(Node *const pMem)
{
	if (pMem != nullptr)
	{
		destroyList(pMem->getNext());
		delete pMem;
	}
}

Node *List::getHead() const
{
	return mpHead;
}

void List::setHead(Node *const newHead)
{
	mpHead = newHead;
}

ostream &operator << (ostream &lhs, List &rhs)
{
	Node *pCur = nullptr;

	pCur = rhs.getHead();
	lhs << "Number, ID, Units, Absence, Name, Email, Program, Level" << endl;

	while (pCur != nullptr)
	{
		lhs << pCur->getNumber() << ',' << pCur->getID() << ',' << pCur->getUnits() << ',' << pCur->getAbsence() << ',' << pCur->getName() << ',' << pCur->getEmail() << ',' << pCur->getProgram() << ',' << pCur->getLevel() << endl;
		pCur = pCur->getNext();
	}

	return lhs;
}