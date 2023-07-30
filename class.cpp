#include "Class.h"
#include <iostream>
#include <string>
using namespace std;

ClassRoom::ClassRoom(string n, Teacher& t)
{
    className = n;
    teacher = &t;
    //maxStudents = 10;
    //noOfStudents = 0;
    //enrolledStudents = new Student[maxStudents];
}
ClassRoom::ClassRoom(const ClassRoom& other) : className(other.className)
//, teacher(other.teacher), noOfStudents(other.noOfStudents), maxStudents(other.maxStudents)
{
    /*enrolledStudents = new Student[maxStudents];
    for (int i = 0; i < noOfStudents; i++)
    {
        enrolledStudents[i] = other.enrolledStudents[i];
    }*/
}
ClassRoom& ClassRoom::operator=(const ClassRoom& other)
{
    if (this == &other)
    {
        return *this;
    }

    //delete[] enrolledStudents;

    // Copy data from the other object
    className = other.className;
    teacher = other.teacher;
    /*noOfStudents = other.noOfStudents;
    maxStudents = other.maxStudents;*/

    // Allocate new memory & copy the students
   /* enrolledStudents = new Student[maxStudents];
    for (int i = 0; i < noOfStudents; i++)
    {
        enrolledStudents[i] = other.enrolledStudents[i];
    }*/

    return *this;
}
ClassRoom::~ClassRoom()
{
    //delete[] enrolledStudents;
}
void ClassRoom::setTeacher(Teacher& t)
{
    teacher = &t;
}
Teacher& ClassRoom::getTeacher() const
{
    return *teacher;
}
//void ClassRoom::enrollStudent(const Student& student)
//{
//    if (noOfStudents >= maxStudents)
//    {
//        // If the array is full, resize it by creating a larger array and copying the elements
//        maxStudents *= 2;
//        Student* temp = new Student[maxStudents];
//        for (int i = 0; i < noOfStudents; i++)
//        {
//            temp[i] = enrolledStudents[i];
//        }
//        delete[] enrolledStudents;
//        enrolledStudents = temp;
//    }
//
//    enrolledStudents[noOfStudents] = student;
//    noOfStudents++;
//}
//void ClassRoom::viewEnrolledStudents() const
//{
//    cout << "Enrolled Students are:-\n";
//    for (int i = 0; i < noOfStudents; ++i)
//    {
//        cout << enrolledStudents[i].getName() << "\n";
//    }
//}

//--Friend Functions--//
std::ostream& operator<<(std::ostream& os, const ClassRoom& classRoom)
{
    os << "Class Name: " << classRoom.className << "\n";
    os << "Teacher: " << classRoom.teacher->getName() << "\n";
    os << "Enrolled Students:\n";
    /*for (int i = 0; i < classRoom.noOfStudents; ++i)
    {
        os << classRoom .enrolledStudents[i].getName() << "\n";
    }*/
    return os;
}

void ClassRoom::setValues()
{
	cout << "Enter the name of the class:";
    cin >> className;
    /*cout<<"Enter expected number of students: ";
    cin>>maxStudents;*/
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
