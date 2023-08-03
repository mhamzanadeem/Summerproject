#pragma once
#ifndef CLASS_H
#define CLASS_H


#include <iostream>
#include <string>
#include "Assignment.h"
//#include "User.h"
using namespace std;

class Teacher;
class Student;
class Assignment;

class ClassRoom
{
	string className;
	Teacher* teacher;
	string code;
	Student** enrolledStudents;
	int noOfStudents;
	int maxStudents;
	Assignment* assignment;
	bool hasAssignment;

	//int noOfTeachers;
	//int maxTeachers;
public:
	ClassRoom();
	ClassRoom(string n, Teacher* teach, string code);
	ClassRoom(const ClassRoom& other); // Copy constructor
	~ClassRoom();

	//Setters
	void setClassName(const string& n);
	void setCode(const string& c);
	void setTeacher(Teacher& t); //teacher
	void setNoOfStudents(int count);
	void setMaxStudents(int max);

	//Getters
	string getClassName() const;
	Teacher& getTeacher() const;
	string getCode() const;
	int getNoOfStudents() const;
	int getMaxStudents() const;


	void enrollStudent(const Student& student); //Enrollment
	void viewEnrolledStudents() const; //View Students

	//Assignment

	void addAssignment(const Assignment& assignment);
	void displayAssignment() const;


	//Operator Overloading
	ClassRoom& operator=(const ClassRoom& other);
	friend ostream& operator<<(ostream& os, const ClassRoom& classRoom);
	//friend bool operator==(const ClassRoom& lhs, const ClassRoom& rhs);
};

#endif // !CLASS_H
