#include <iostream>
#include <string>
#include "securityStudent.h"
#include "degree.h"
using namespace std;
using std::cout;

SecurityStudent::SecurityStudent() :Student() {
	degreeType = SECURITY;
}

SecurityStudent::SecurityStudent(string ID, string firstName, string lastName, string email, int age, int days[], 
	Degree degreeType) :Student(ID, firstName, lastName, email, age, days, degreeType) {
	degreeType = SECURITY;
}

Degree SecurityStudent::getDegreeProgram() {
	degreeType = SECURITY;
	return degreeType;
}

void SecurityStudent::print() {
	this->Student::print();
	cout << " Degree Program: " << degreeTypeStrings[getDegreeProgram()] << endl;
}

SecurityStudent::~SecurityStudent() {
	Student::~Student();
}




