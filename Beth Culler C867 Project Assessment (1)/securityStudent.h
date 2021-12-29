#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H
#include "student.h"
#include "degree.h"
#include <string>
using namespace std;

class SecurityStudent : public Student {
public:
	SecurityStudent();
	SecurityStudent(string ID, string firstName, string lastName, string email, int age, int days[], Degree degreeType);
	Degree getDegreeProgram();
	void print();
	~SecurityStudent();
};

#endif