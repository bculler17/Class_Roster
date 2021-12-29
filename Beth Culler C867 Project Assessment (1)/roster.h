#ifndef ROSTER_H
#define ROSTER_H
#include "degree.h"
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include <string>
#include <iostream>
using namespace std;

class Roster {
public:
	Roster();
	Roster(int capacity);
	Student* getStudentAt(int index);
	void parseThenAdd(string datarow);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1,
		int daysInCourse2, int daysInCourse3, Degree degreeType);
	void remove(string studentID);
	void printAll();
	void printInvalidEmails();
	void printAvgDays(string studentID);
	void printByDegreeProgram(Degree d);
	~Roster(); 

private:
	int lastIndex;
	int capacity;
	Student** classRosterArray;                          
};

#endif
