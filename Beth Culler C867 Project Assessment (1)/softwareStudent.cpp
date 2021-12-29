#include <iostream>
#include <string>
#include "softwareStudent.h"
#include "degree.h"
using namespace std;
using std::cout;

SoftwareStudent::SoftwareStudent() : Student() {
	degreeType = SOFTWARE;
}

SoftwareStudent::SoftwareStudent(string ID, string firstName, string lastName, string email, int age, int days[],
	Degree degreeType) : Student(ID, firstName, lastName, email, age, days, degreeType) {
	degreeType = SOFTWARE;
}

Degree SoftwareStudent::getDegreeProgram() {
	degreeType = SOFTWARE;
	return degreeType;
}

void SoftwareStudent::print() {
	this->Student::print();
	cout << " Degree Program: " << degreeTypeStrings[getDegreeProgram()] << endl;
}

SoftwareStudent::~SoftwareStudent() {
	Student::~Student();
}