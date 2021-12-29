#include <iostream>
#include <string>
#include "networkStudent.h"
#include "degree.h"
using namespace std;
using std::cout;

NetworkStudent::NetworkStudent() :Student() {
	degreeType = NETWORKING;
}

NetworkStudent::NetworkStudent(string ID, string firstName, string lastName, string email, int age, int days[],
	Degree degreeType) : Student(ID, firstName, lastName, email, age, days, degreeType) {
	degreeType = NETWORKING;
}

Degree NetworkStudent::getDegreeProgram() {
	degreeType = NETWORKING;
	return degreeType;
}

void NetworkStudent::print() {
	this->Student::print();
	cout << " Degree Program: " << degreeTypeStrings[getDegreeProgram()] << endl;
}

NetworkStudent::~NetworkStudent() {
	Student::~Student();
}