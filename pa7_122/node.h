#ifndef NODE_H
#define NODE_H
#define _CRT_SECURE_NO_WARNINGS

#include "Stack.h"

class Node
{
public:
	Node(Stack newDates, int newNumber = 0, int newID = 0, int newUnits = 0, int newAbsence = 0, string newName = "", string newEmail = "", string newProgram = "", string newLevel = "");
	Node(const Node &copy);
	~Node();

	int getNumber() const;
	int getID() const;
	int getUnits() const;
	int getAbsence() const;
	string getName() const;
	string getEmail() const;
	string getProgram() const;
	string getLevel() const;
	Stack getDates() const;
	Node *getNext() const;

	void setNumber(const int newNumber);
	void setID(const int newID);
	void setUnits(const int newUnits);
	void setAbsence(const int newAbsence);
	void incrementAbsence();
	void setName(const string newName);
	void setEmail(const string newEmail);
	void setProgram(const string newProgram);
	void setLevel(const string newLevel);
	void setDates(const Stack newDate);
	void setNext(Node *const newNext);
private:
	int mNumber;
	int mID;
	int mUnits;
	int mAbsence;
	string mName;
	string mEmail;
	string mProgram;
	string mLevel;
	Stack mDates;
	Node *mpNext;
};

#endif