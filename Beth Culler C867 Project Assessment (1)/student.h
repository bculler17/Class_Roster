#ifndef STUDENT_H
#define STUDENT_H 
#include "degree.h"
#include <string>
using namespace std;

class Student {
public:
	const static int dayArraySize = 3;
	void SetStudentID(string ID);
	string GetStudentID() const;
	void SetFirstName(string firstName);
	string GetFirstName() const;
	void SetLastName(string lastName);
	string GetLastName() const;
	void SetEmail(string email);
	string GetEmail() const;
	void SetAge(int age);
	int GetAge() const;
	void SetNumDays(int days[], int length);
	int* GetNumDays();
	Student();
	Student(string ID, string firstName, string lastName, string email, int age, int days[], Degree degreeType);
	virtual void print() = 0;
	virtual Degree getDegreeProgram() = 0;
	~Student();

protected:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[dayArraySize];
	Degree degreeType;
};
#endif