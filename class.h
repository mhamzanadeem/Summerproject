#include <iostream>
#include <string>
#include "user.h"
using namespace std;

class ClassRoom
{
	string className;
	Teacher teacher;
	Student* enrolledStudents;
	int noOfStudents;
	int maxStudents;
public:
	ClassRoom(string n, Teacher& teach);
	ClassRoom(const ClassRoom& other); // Copy constructor
	~ClassRoom();

	void setTeacher(const Teacher& t); //teacher
	void enrollStudent(const Student& student); //Enrollment
	void viewEnrolledStudents() const; //View Students

	//Operator Overloading
	ClassRoom& operator=(const ClassRoom& other);
	friend ostream& operator<<(ostream& os, const ClassRoom& classRoom);
	//friend bool operator==(const ClassRoom& lhs, const ClassRoom& rhs);
};

