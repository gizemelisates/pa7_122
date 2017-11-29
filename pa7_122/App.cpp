#include "App.h"

App::App()
{
	mInFile.open("classList.csv", ios::in);
	mInMaster.open("masterList.csv", ios::in);
}

App::~App()
{
	if (mInFile.is_open()) 
	{
		mInFile.close(); 
	}
	if (mInMaster.is_open())
	{
		mInMaster.close(); 
	}
}

int App::printMenu()
{
	int choice = 0;

	do
	{
		system("cls");
		cout << "1. Import List" << endl;
		cout << "2. Load" << endl;
		cout << "3. Store" << endl;
		cout << "4. Mark Absences" << endl;
		cout << "5. Edit Absences" << endl;
		cout << "6. Generate Report" << endl;
		cout << "7. Exit" << endl;

		cin >> choice; 
	} while ((choice < 1) || (choice > 7));

	return choice; 
}

int App::printSubMenu()
{
	int choice = 0;

	do
	{
		system("cls");
		cout << "***Generate Report Menu***" << endl;
		cout << "1. Generate a report for all students" << endl;
		cout << "2. Generate a report for students matching or exceeding a specific number of absences" << endl;
		cout << "3. Go back" << endl;

		cin >> choice;
	} while ((choice < 1) || (choice > 3));

	return choice; 
}

void App::runApp()
{
	int choice = 0;

	choice = printMenu(); 

	switch (choice)
	{
	case 1:
		mInFile >> mList;
		cout << mList; 
		system("pause"); 
		runApp(); 
		break;
	case 2:
		mInMaster > mList;
		readDates(); 
		cout << mList; 
		system("pause"); 
		runApp(); 
		break;
	case 3:
		storeMaster();
		saveDates(); 
		runApp(); 
		break;
	case 4:
		markAbsent();
		runApp(); 
		break;
	case 5:
		editAbsences(); 
		system("pause");
		runApp(); 
		break;
	case 6:
		generateReport(); 
		runApp(); 
		break;
	case 7:
		break;
	}
}

void App::storeMaster()
{
	ofstream outfile("masterList.csv"); 

	outfile << mList; 

	outfile.close(); 
}

void App::markAbsent()
{
	Node *pCur = nullptr;
	Stack dates;
	int choice = 0;
	string date = "";

	pCur = mList.getHead(); 

	if (pCur == nullptr) 
	{
		cout << "List not found!" << endl; 
	}
	else
	{
		while (pCur != nullptr) 
		{
			do
			{
				system("cls");
				cout << "Is" << pCur->getName() << "absent today?" << endl;
				cout << "Press 1 for yes" << endl;
				cout << "Press 2 for no" << endl;
				cin >> choice;
			} while ((choice < 1) || (choice > 2));

			if (choice == 1)
			{
				date = generateDate(); 
				dates = pCur->getDates(); 
				dates.push(date); 
				pCur->setDates(dates); 
				pCur->incrementAbsence(); 
				dates = pCur->getDates(); 
				dates.printStack(); 
				system("pause");
			}
			pCur = pCur->getNext(); 
		}
	}
}

void App::saveDates()
{
	Node *pCur = nullptr;
	StackNode *pMem = nullptr;
	Stack dates;
	ofstream outfile("dateList.csv");

	pCur = mList.getHead(); 

	while (pCur != nullptr) 
	{
		dates = pCur->getDates(); 
		outfile << pCur->getNumber() << ','; 
		outfile << dates; 
		pCur = pCur->getNext(); 
	}

	outfile.close(); 
}

void App::readDates()
{
	Node *pCur = nullptr;
	ifstream infile("dateList.csv"); 
	Stack date, erase;
	int number = 0;
	char line[100] = "";

	pCur = mList.getHead(); 

	while (pCur != nullptr) 
	{
		infile.getline(line, 100, ',');
		number = atoi(line); 
		if (number == pCur->getNumber()) 
		{
			infile >> date; 
			pCur->setDates(date); 
		}
		cout << pCur->getNumber() << ':' << ' '; 
		if (!pCur->getDates().isEmpty(pCur->getDates().getTop())) 
		{
			pCur->getDates().printStack(); 
		}
		else 
		{
			cout << "Empty" << endl; 
		}
		date = erase; 
		pCur = pCur->getNext(); 
	}

	infile.close(); 
}


void App::reportAll()
{
	ofstream outfile("report.txt"); 
	Node *pCur = nullptr;

	pCur = mList.getHead(); 
	outfile << "****Report****" << endl; 

	while (pCur != nullptr) 
	{
		outfile << "Name: " << pCur->getName() << "   Absent: " << pCur->getAbsence() << endl; 
		outfile << "Dates Absent: ";
		outfile << pCur->getDates(); 
		outfile << endl; 
		pCur = pCur->getNext(); 
	}

	outfile.close(); 
}

void App::reportAbsences(const int absence)
{
	ofstream outfile("reportAbsence.txt"); 
	Node *pCur = nullptr;

	pCur = mList.getHead(); 
	outfile << "****Report*****" << endl; 
	outfile << "--Report for students with " << absence << " or more absences.--" << endl; 

	while (pCur != nullptr) 
	{
		if (pCur->getAbsence() >= absence) 
		{
			outfile << "Name: " << pCur->getName() << "   Absent: " << pCur->getAbsence() << endl; 
			outfile << "Dates Absent: ";
			outfile << pCur->getDates(); 
			outfile << endl; 
		}
		pCur = pCur->getNext(); 
	}

	outfile.close(); 
}

void App::generateReport()
{
	int choice = 0, absence = 0;

	choice = printSubMenu(); 

	switch (choice)
	{
	case 1:
		reportAll(); 
		break;
	case 2:
		cout << "Please set the number of absences: ";
		cin >> absence; 
		reportAbsences(absence); 
		break;
	case 3:
		runApp(); 
		break;
	}
}

void App::editAbsences()
{
	Node *pCur = nullptr;
	Stack dates;
	StackNode *pMem = nullptr;
	string newDate = "";
	int searchID = 0, position = 0, index = 0;
	bool found = false;

	cout << mList; 
	pCur = mList.getHead(); 
	cout << "Enter the ID number of the student: ";
	cin >> searchID; 
	system("cls"); 

	while (found != true) 
	{
		if (pCur->getID() == searchID) 
		{
			dates = pCur->getDates(); 
			pMem = dates.getTop();
			if (!dates.isEmpty(dates.getTop())) 
			{
				dates.printStack(); 
				cout << "Which date would you like to edit: ";
				cin >> position;
				system("cls"); 
				for (index = 0; index < position; index++) 
				{
					pMem = pMem->getNext(); 
				}
				cout << "Enter a new date: ";
				cin >> newDate; 
				pMem->setDate(newDate);
			}
			found = true;
		}
		pCur = pCur->getNext(); 
	}
}

string App::generateDate() const
{
	string day = "", month = "", year = "", date = "";
	char line[50] = "";
	time_t t = time(0);
	struct tm *now = localtime(&t);

	_itoa(now->tm_mday, line, 10);
	day = line;
	_itoa((now->tm_mon + 1), line, 10);
	month = line;
	_itoa((now->tm_year + 1900), line, 10);
	year = line;
	date = day + "/" + month + "/" + year; 

	return date;
}

ifstream &operator >> (ifstream &lhs, List &rhs)
{
	Stack dates;
	int number = 0, ID = 0, units = 0;
	char line[100] = "", temp[100] = "";
	string name = "", email = "", program = "", level = "";

	lhs.getline(line, 100); 

	while (!lhs.eof())
	{
		lhs.getline(line, 100, ',');
		number = atoi(line);
		lhs.getline(line, 100, ',');
		ID = atoi(line);
		lhs.getline(line, 100, ',');
		lhs.getline(temp, 100, ',');
		strcat(line, temp);
		name = line;
		lhs.getline(line, 100, ',');
		email = line;
		lhs.getline(line, 100, ',');
		units = atoi(line);
		lhs.getline(line, 100, ',');
		program = line;
		lhs.getline(line, 100);
		level = line;

		rhs.insertBack(dates, number, ID, units, 0, name, email, program, level); 
	}

	return lhs;
}

ifstream &operator > (ifstream &lhs, List &rhs)
{
	Stack dates;
	int number = 0, ID = 0, units = 0, absence = 0;
	char line[100] = "", temp[100] = "";
	string name = "", email = "", program = "", level = "";

	lhs.getline(line, 100); 

	while (!lhs.eof())
	{
		lhs.getline(line, 100, ',');
		number = atoi(line);
		lhs.getline(line, 100, ',');
		ID = atoi(line);
		lhs.getline(line, 100, ',');
		units = atoi(line);
		lhs.getline(line, 100, ',');
		absence = atoi(line);
		lhs.getline(line, 100, ',');
		name = line;
		lhs.getline(line, 100, ',');
		email = line;
		lhs.getline(line, 100, ',');
		program = line;
		lhs.getline(line, 100);
		level = line;

		rhs.insertBack(dates, number, ID, units, absence, name, email, program, level); 
	}

	return lhs;
}

ifstream &operator >> (ifstream &lhs, Stack &rhs)
{
	vector<string> dates;
	string date = "";
	int index = 0, count = 0, position = 0, size = 0;
	char line[100] = "", temp[100] = "";

	lhs.getline(line, 100); 

	while ((line[index] != '\0') && (index < 100))
	{
		if (line[index] != ',') 
		{
			temp[count] = line[index];
			count++; 
		}
		else if (line[index] == ',') 
		{
			date = temp;
			dates.push_back(date);
			for (position = 0; position < 100; position++) 
			{
				temp[position] = '\0'; 
			}
			count = 0; 
		}
		index++; 
	}

	dates.push_back(temp); 
	reverse(dates.begin(), dates.end()); 
	size = dates.size(); 

	for (index = 0; index < size; index++) 
	{
		rhs.push(dates[index]); 
	}

	return lhs;
}

ofstream &operator << (ofstream &lhs, List &rhs)
{
	Node *pCur = nullptr;

	pCur = rhs.getHead(); 
	lhs << "Number, ID, Units, Absence, Name, Email, Program, Level" << endl; 

	while (pCur != nullptr) 
	{
		lhs << pCur->getNumber() << ',' << pCur->getID() << ',' << pCur->getUnits() << ',' << pCur->getAbsence() << ',' << pCur->getName() << ',' << pCur->getEmail() << ',' << pCur->getProgram() << ',' << pCur->getLevel() << endl; // Write the data into the file.
		pCur = pCur->getNext(); 
	}

	return lhs;
}

ofstream &operator << (ofstream &lhs, Stack &rhs)
{
	StackNode *pCur = nullptr;

	pCur = rhs.getTop(); 

	while (pCur != nullptr) 
	{
		if (pCur->getNext() != nullptr) 
		{
			lhs << pCur->getDate() << ','; 
		}
		else
		{
			lhs << pCur->getDate() << endl; 
		}
		pCur = pCur->getNext(); 
	}

	return lhs;
}