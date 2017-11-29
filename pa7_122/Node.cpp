#include "Node.h"

Node::Node(Stack newDates, int newNumber, int newID, int newUnits, int newAbsence, string newName, string newEmail, string newProgram, string newLevel)
{
	mNumber = newNumber;
	mID = newID;
	mUnits = newUnits;
	mAbsence = newAbsence;
	mName = newName;
	mEmail = newEmail;
	mProgram = newProgram;
	mLevel = newLevel;
	mDates = newDates;
	mpNext = nullptr;
}

Node::Node(const Node &copy)
{
	mNumber = copy.getNumber();
	mID = copy.getID();
	mUnits = copy.getUnits();
	mName = copy.getName();
	mEmail = copy.getEmail();
	mProgram = copy.getProgram();
	mLevel = copy.getLevel();
	mDates = copy.getDates();
	mpNext = copy.getNext();
}

Node::~Node()
{
}

int Node::getNumber() const
{
	return mNumber;
}

int Node::getID() const
{
	return mID;
}

int Node::getUnits() const
{
	return mUnits;
}

int Node::getAbsence() const
{
	return mAbsence;
}

string Node::getName() const
{
	return mName;
}

string Node::getEmail() const
{
	return mEmail;
}

string Node::getProgram() const
{
	return mProgram;
}

string Node::getLevel() const
{
	return mLevel;
}

Stack Node::getDates() const
{
	return mDates;
}

Node *Node::getNext() const
{
	return mpNext;
}

void Node::setNumber(const int newNumber)
{
	mNumber = newNumber;
}

void Node::setID(const int newID)
{
	mID = newID;
}

void Node::setUnits(const int newUnits)
{
	mUnits = newUnits;
}

void Node::setAbsence(const int newAbsence)
{
	mAbsence = newAbsence;
}

void Node::incrementAbsence()
{
	mAbsence++;
}

void Node::setName(const string newName)
{
	mName = newName;
}

void Node::setEmail(const string newEmail)
{
	mEmail = newEmail;
}

void Node::setProgram(const string newProgram)
{
	mProgram = newProgram;
}

void Node::setLevel(const string newLevel)
{
	mLevel = newLevel;
}

void Node::setDates(const Stack newDates)
{
	mDates = newDates;
}

void Node::setNext(Node *const newNext)
{
	mpNext = newNext;
}