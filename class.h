#pragma once
#ifndef CLASS_H
#define CLASS_H


#include <iostream>
#include <string>
//#include "User.h"
using namespace std;

class Teacher;

class ClassRoom
{
	string className;
	Teacher* teacher;
	string code;
	//Student* enrolledStudents;
	//int noOfStudents;
	//int noOfTeachers;
	//int maxTeachers;
	//int maxStudents;
public:
	ClassRoom(string n, Teacher * teach, string code);
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

#endif // !CLASS_H
