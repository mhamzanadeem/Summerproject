#include "Class.h"
#include "User.h"
#include <iostream>
#include <string>
using namespace std;

ClassRoom::ClassRoom():assignment(nullptr)
{
	className = "";
	teacher = nullptr;
	code = "";
	maxStudents = 10;
	noOfStudents = 0;
	enrolledStudents = new Student * [maxStudents]; //memory
	for (int i = 0; i < maxStudents; i++)
	{
		enrolledStudents[i] = nullptr;
	}

}
ClassRoom::ClassRoom(string n, Teacher* t, string c) : teacher(t), assignment(nullptr)
{
	className = n;
	code = c;
	maxStudents = 10;
	noOfStudents = 0;
	enrolledStudents = new Student * [maxStudents]; //memory
	for (int i = 0; i < maxStudents; i++)
	{
		enrolledStudents[i] = nullptr;
	}
}
ClassRoom::ClassRoom(const ClassRoom& other) : className(other.className), teacher(other.teacher), noOfStudents(other.noOfStudents), maxStudents(other.maxStudents), code(other.code)
{
	enrolledStudents = new Student * [maxStudents];
	for (int i = 0; i < noOfStudents; i++)
	{
		enrolledStudents[i] = new Student(*other.enrolledStudents[i]);
	}
	assignment = other.assignment;
}

//Assignments
void ClassRoom::addAssignment(const Assignment& newAssignment) {
	if (hasAssignment) {
		delete assignment; // Deallocate the existing Assignment object
	}
	assignment = new Assignment(newAssignment); // Copy the Assignment object
	hasAssignment = true;
}

void ClassRoom::displayAssignment() const {
	if (hasAssignment) {
		std::cout << "Assignment: ";
		assignment->display();
	}
	else {
		cout << "No assignment found for this class." << endl;
	}
}

ClassRoom& ClassRoom::operator=(const ClassRoom& other)
{
	if (this == &other)
	{
		return *this;
	}

	for (int i = 0; i < noOfStudents; i++)
	{
		delete enrolledStudents[i];
	}
	delete[] enrolledStudents;

	// Copy data from the other object
	className = other.className;
	teacher = other.teacher;
	code = other.code;
	noOfStudents = other.noOfStudents;
	maxStudents = other.maxStudents;

	// Allocate new memory & copy the students
	enrolledStudents = new Student * [maxStudents];
	for (int i = 0; i < noOfStudents; i++)
	{
		enrolledStudents[i] = new Student(*other.enrolledStudents[i]);
	}

	return *this;
}
ClassRoom::~ClassRoom()
{
	for (int i = 0; i < noOfStudents; i++)
	{
		delete enrolledStudents[i];
	}
	delete[] enrolledStudents;
}

void ClassRoom::setClassName(const string& n)
{
	className = n;
}
void ClassRoom::setCode(const string& c)
{
	code = c;
}
void ClassRoom::setTeacher(Teacher& t)
{
	teacher = &t;
}
void ClassRoom::setNoOfStudents(int count)
{
	noOfStudents = count;
}
void ClassRoom::setMaxStudents(int max)
{
	maxStudents = max;
}
string ClassRoom::getClassName() const
{
	return className;
}
Teacher& ClassRoom::getTeacher() const
{
	return *teacher;
}
int  ClassRoom::getNoOfStudents() const
{
	return noOfStudents;
}
int  ClassRoom::getMaxStudents() const
{
	return maxStudents;
}
string ClassRoom::getCode() const
{
	return code;
}
void ClassRoom::enrollStudent(const Student& student)
{
	if (noOfStudents >= maxStudents)
	{
		// If the array is full, resize it by creating a larger array and copying the elements
		maxStudents *= 2;
		Student* temp = new Student[maxStudents];
		for (int i = 0; i < noOfStudents; i++)
		{
			temp[i] = *enrolledStudents[i];
		}
		for (int i = 0; i < noOfStudents; i++)
		{
			delete enrolledStudents[i];
		}
		delete[] enrolledStudents;
		*enrolledStudents = temp;
	}
	*enrolledStudents[noOfStudents] = student;
	noOfStudents++;
}
void ClassRoom::viewEnrolledStudents() const
{
	cout << "Enrolled Students are:\n";
	for (int i = 0; i < noOfStudents; ++i)
	{
		enrolledStudents[i]->displayUserData();
	}
}

//--Friend Functions--//
std::ostream& operator<<(std::ostream& os, const ClassRoom& classRoom)
{
	os << "Class Name: " << classRoom.className << "\n";
	os << "Teacher: " << classRoom.teacher->getName() << "\n";
	os << "Enrolled Students:\n";
	for (int i = 0; i < classRoom.noOfStudents; ++i)
		/*{
			os << *(classRoom.enrolledStudents[i]) << "\n";
		}*/
		return os;
}

//bool operator==(const ClassRoom& lhs, const ClassRoom& rhs)
//{
//    if (lhs.className != rhs.className || lhs.teacher != rhs.teacher || lhs.noOfStudents != rhs.noOfStudents)
//    {
//        return false;
//    }
//
//    for (int i = 0; i < lhs.noOfStudents; ++i)
//    {
//        if (lhs.enrolledStudents[i] != rhs.enrolledStudents[i])
//        {
//            return false;
//        }
//    }
//
//    return true;
//}
