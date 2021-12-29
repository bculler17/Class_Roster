#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H
#include "student.h"
#include "degree.h"
#include <string>
using namespace std;

class NetworkStudent : public Student {
public:
	NetworkStudent();
	NetworkStudent(string ID, string firstName, string lastName, string email, int age, int days[], Degree degreeType);
	Degree getDegreeProgram();
	void print();
	~NetworkStudent();
};

#endif
