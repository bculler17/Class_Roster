#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H
#include "student.h"
#include "degree.h"
#include <string>
using namespace std;

class SoftwareStudent : public Student {
public:
	SoftwareStudent();
	SoftwareStudent(string ID, string firstName, string lastName, string email, int age, int days[], Degree degreeType);
	Degree getDegreeProgram();
	void print();
	~SoftwareStudent();
};

#endif
