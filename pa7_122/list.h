#ifndef LIST_H
#define LIST_H
#define _CRT_SECURE_NO_WARNINGS

#include "Node.h"

using std::ostream;

class List
{
public:
	List(); 
	List(const List &copy); 
	~List(); 

	List &operator = (const List &rhs);

	Node *makeNode(const Stack newDates, const int newNumber, const int newID, const int newUnits, const int newAbsence, const string newName, const string newEmail, const string newProgram, const string newLevel);
	bool isEmpty();
	void insertFront(const Stack newDates, const int newNumber, const int newID, const int newUnits, const int newAbsence, const string newName, const string newEmail, const string newProgram, const string newLevel);
	void insertOrder(const Stack newDates, const int newNumber, const int newID, const int newUnits, const int newAbsence, const string newName, const string newEmail, const string newProgram, const string newLevel);
	void insertBack(const Stack newDates, const int newNumber, const int newID, const int newUnits, const int newAbsence, const string newName, const string newEmail, const string newProgram, const string newLevel);
	void deleteFront();
	void deleteNode(const string searchName);
	void deleteBack();
	void printList();

	Node *getHead() const;

	void setHead(Node *const newHead);
private:
	Node *mpHead;
	void destroyList();
	void destroyList(Node *const pMem);
};

ostream &operator << (ostream &lhs, List &rhs);

#endif