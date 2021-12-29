#include "student.h"
#include <iostream>
using namespace std;

void Student::SetStudentID(string ID) {
	studentID = ID;
}

string Student::GetStudentID() const {
	return studentID;
}

void Student::SetFirstName(string firstName) {
	this->firstName = firstName;
}

string Student::GetFirstName() const {
	return firstName;
}

void Student::SetLastName(string lastName) {
	this->lastName = lastName;
}

string Student::GetLastName() const {
	return lastName;
}

void Student::SetEmail(string email) {
	emailAddress = email;
}

string Student::GetEmail() const {
	return emailAddress;
}

void Student::SetAge(int age) {
	this->age = age;
}

int Student::GetAge() const {
	return age;
}

void Student::SetNumDays(int days[], int length) {
	length = 3;
	for (int i = 0; i < length; ++i) {
		this->daysInCourse[i] = days[i];
	}
}
		
int* Student::GetNumDays() {
	return daysInCourse;
}

Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 00;
	for (int i = 0; i < dayArraySize; ++i) this->daysInCourse[i] = 0;
	degreeType = Degree::NETWORKING;
}

Student::Student(string ID, string firstName, string lastName, string email, int age, int days[], Degree degreeType) {
	this->studentID = ID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = email;
	this->age = age;
	for (int i = 0; i < dayArraySize; ++i) this->daysInCourse[i] = days[i];
	this->degreeType = degreeType;
}

void Student::print() {
	cout << " First Name: " << GetFirstName();
	cout << " Last Name: " << GetLastName();
	cout << " Age: " << GetAge();
	cout << " daysInCourse: {" << GetNumDays()[0] << "," << GetNumDays()[1] << "," << GetNumDays()[2] << "}";
}

Student::~Student() {
	//not needed, no dymanic allocation occurred in this Class; required per class instructions. 
}