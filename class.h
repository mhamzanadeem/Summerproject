#pragma once
#include <iostream>
#include <string>
#include "User.h"
using namespace std;

class ClassRoom
{
	string className;
	Teacher* teacher;
	//Student* enrolledStudents;
	//int noOfStudents;
	//int noOfTeachers;
	//int maxTeachers;
	//int maxStudents;
public:
	ClassRoom(string n, Teacher& teach);
	ClassRoom(const ClassRoom& other); // Copy constructor
	~ClassRoom();

	void setTeacher(Teacher& t); //teacher
	//void enrollStudent(const Student& student); //Enrollment
	//void viewEnrolledStudents() const; //View Students

	Teacher& getTeacher() const;

	void setValues();
	//Operator Overloading
	ClassRoom& operator=(const ClassRoom& other);
	friend ostream& operator<<(ostream& os, const ClassRoom& classRoom);
	//friend bool operator==(const ClassRoom& lhs, const ClassRoom& rhs);
};
