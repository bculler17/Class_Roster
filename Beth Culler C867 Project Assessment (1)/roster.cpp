#include "roster.h"
#include "degree.h"
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include <string>
#include <iostream>
using namespace std;

Roster::Roster() {
	this->capacity = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}

Roster::Roster(int capacity) {
	this->capacity = capacity;
	this->lastIndex = -1;
	this->classRosterArray = new Student*[capacity];
}

Student* Roster::getStudentAt(int index) {
	return classRosterArray[index];
}

void Roster::parseThenAdd(string datarow) {
	if (lastIndex < capacity) {
		lastIndex++;
		Degree degreeType;

		int rhs = datarow.find(",");
		string ID = datarow.substr(0, rhs);

		int lhs = rhs + 1;
		rhs = datarow.find(",", lhs);
		string firstName = datarow.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = datarow.find(",", lhs);
		string lastName = datarow.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = datarow.find(",", lhs);
		string email = datarow.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = datarow.find(",", lhs);
		int age = stoi(datarow.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = datarow.find(",", lhs);
		int daysCourse1 = stoi(datarow.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = datarow.find(",", lhs);
		int daysCourse2 = stoi(datarow.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = datarow.find(",", lhs);
		int daysCourse3 = stoi(datarow.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		string program = datarow.substr(lhs, datarow.length() - lhs);

		if (program == "SECURITY") {
			degreeType = SECURITY;
		}
		else if (program == "NETWORK") {
			degreeType = NETWORKING;
		}
		else if (program == "SOFTWARE") {
			degreeType = SOFTWARE;
		}
		else {
			cerr << "ERROR! DEGREE PROGRAM DOES NOT EXIST" << endl;
			cerr << "EXITING NOW" << endl;
			exit(-1);
		}
	add(ID, firstName, lastName, email, age, daysCourse1, daysCourse2, daysCourse3, degreeType);
	}
	else {
		cerr << "ERROR! LIST HAS EXCEEDED MAXIMUM CAPACITY" << endl;
		cerr << "EXITING NOW" << endl;
		exit(-1);
	}
}

void Roster::add(string ID, string firstName, string lastName, string email, int age, int daysInCourse1,
	int daysInCourse2, int daysInCourse3, Degree degreeType) {
	int days[Student::dayArraySize];
	days[0] = daysInCourse1;
	days[1] = daysInCourse2;
	days[2] = daysInCourse3;
	if (degreeType == SECURITY) classRosterArray[lastIndex] = new SecurityStudent(ID, firstName, lastName, email, age, days, degreeType);
	else if (degreeType == NETWORKING) classRosterArray[lastIndex] = new NetworkStudent(ID, firstName, lastName, email, age, days, degreeType);
	else classRosterArray[lastIndex] = new SoftwareStudent(ID, firstName, lastName, email, age, days, degreeType);
}

void Roster::printAll() {
	for (int i = 0; i < capacity; ++i) {
		(this->classRosterArray)[i]->print();
	}
}

void Roster::printAvgDays(string studentID) {
	bool found = false;
	for (int i = 0; i <= lastIndex; ++i) {
		if (this->classRosterArray[i]->GetStudentID() == studentID) {
			found = true;
			int* d = classRosterArray[i]->GetNumDays();
			cout << "Average number of days in course for studentID " << classRosterArray[i]->GetStudentID() << ": ";
			cout << static_cast<double>(d[0] + d[1] + d[2])/3 << endl;
		}
	}
	if (!found) cerr << "STUDENT NOT FOUND!" << endl;
}

void Roster::printInvalidEmails() {
	bool any = false;
	for (int i = 0; i <= lastIndex; ++i) {
		any = false;
		string e = classRosterArray[i]->GetEmail();
		if (e.find('@') == string::npos || e.find('.') == string::npos || e.find(" ") != string::npos) {
			any = true;
			cout << "StudentID " << classRosterArray[i]->GetStudentID() << ": ";
			cout << classRosterArray[i]->GetEmail() << endl;
		}
	}
}

void Roster::printByDegreeProgram(Degree d) {
	cout << "Printing by Degree Program: " << degreeTypeStrings[d] << endl;
	for (int i = 0; i <= lastIndex; ++i) {
		if (this->classRosterArray[i]->getDegreeProgram() == d) this->classRosterArray[i]->print();
	}
}

void Roster::remove(string studentID) {
	bool found = false;
	for (int i = 0; i <= lastIndex; ++i) {
		if (this->classRosterArray[i]->GetStudentID() == studentID) {
			found = true;
			delete this->classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[i + 1];
			this->classRosterArray[i + 1] = this->classRosterArray[lastIndex];
			capacity--;
			cout << "DONE" << endl;
		}
	}
	if (!found) cerr << "STUDENT_ID DOES NOT EXIST!" << endl;
}

Roster::~Roster() {
	for (int i = 0; i < capacity; ++i) {
		delete this->classRosterArray[i];
	}
	delete this->classRosterArray;
}

int main() {
	cout << "Course Title: Scripting and Programming Applications - C867" << endl;
	cout << "Programming Language Used: C++" << endl;
	cout << "Student ID: #001003662" << endl;
	cout << "Name: Beth Culler" << endl;

	int numStudents = 5;
	string studentData[5] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Beth,Culler,bculle2@wgu.edu,31,30,36,25,SOFTWARE"
	};

	Roster* classRoster = new Roster(numStudents);

	cout << "Parsing data and adding students" << endl;
	for (int i = 0; i < numStudents; ++i) {
		classRoster->parseThenAdd(studentData[i]);
	}
	cout << "DONE" << endl;
	
	cout << "Displaying all students" << endl;
	classRoster->printAll();

	cout << endl;
	cout << "Printing invalid email addresses:" << endl;
	classRoster->printInvalidEmails();

	cout << endl;
	for (int i = 0; i < numStudents; ++i) {
		classRoster->printAvgDays(classRoster->getStudentAt(i)->GetStudentID());
	}
	
	cout << endl;
	for (int d = 0; d < 3; ++d) classRoster->printByDegreeProgram((Degree) d);

	cout << endl;
	cout << "Removing studentID A3:" << endl;
	classRoster->remove("A3");
	classRoster->printAll();
    
	cout << "Removing studentID A3:" << endl;
	classRoster->remove("A3");
	
	cout << "C867 PROJECT IS COMPLETE" << endl;
	classRoster->~Roster();          //Destructor called per project instructions
	return 0;
}