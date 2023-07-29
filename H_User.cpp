#include<iostream>
#include<string>
#include "User.h"


/////////////////////////////////////////////////////////////////////
/////////////////////////--USER--////////////////////////////////////
/////////////////////////////////////////////////////////////////////

User::User(string r, string n, string m, string id, string pass, string num)
{
    role = r;
    name = n;
    email = m;
    loginID = id;
    password = pass;
    contactNumber = num;
}

// Getter functions
string User::getRole() const
{
    return role;
}
string User::getName() const
{
    return name;
}

string User::getEmail() const
{
    return email;
}

string User::getLoginID() const
{
    return loginID;
}

string User::getPassword() const
{
    return password;
}

// Setter functions
void User::setRole(const string& r)
{
    role = r;
}
void User::setName(const string& n)
{
    name = n;
}

void User::setEmail(const string& m)
{
    email = m;
}

void User::setLoginID(const string& id)
{
    loginID = id;
}

void User::setPassword(const string& pass)
{
    password = pass;
}

User& User::operator=(const User& rhs)
{
    if (this != &rhs)
    {
        name = rhs.name;
        email = rhs.email;
        loginID = rhs.loginID;
        password = rhs.password;
        contactNumber = rhs.contactNumber;
    }
    return *this;
}

/////////////////////////////////////////////////////////////////////
////////////////////////////--STUDENT--//////////////////////////////
/////////////////////////////////////////////////////////////////////

Student::Student( string n, string m, string id, string pass,string num, string rol)
    : User("Student", n, m, id, pass, num), enrolledClasses(nullptr), noEnrolledClasses(0), maxEnrolledClasses(10)
{
    RollNumber = rol;
}

Student::Student(const Student& other)
    : User(other), enrolledClasses(nullptr), noEnrolledClasses(other.noEnrolledClasses), maxEnrolledClasses(other.maxEnrolledClasses)
{
    if (noEnrolledClasses > 0)
    {
        enrolledClasses = new string[maxEnrolledClasses];
        for (int i = 0; i < noEnrolledClasses; i++)
        {
            enrolledClasses[i] = other.enrolledClasses[i];
        }
    }
}

Student::~Student()
{
    delete[] enrolledClasses;
}
Student& Student::operator=(const Student& other)
{
    if (this == &other)
    {
        return *this;
    }

    // Call the base class assignment operator
    User::operator=(other);

    // Deallocate the old memory
    delete[] enrolledClasses;

    // Copy the enrolled classes from other if it is not nullptr
    if (other.enrolledClasses != nullptr)
    {
        noEnrolledClasses = other.noEnrolledClasses;
        maxEnrolledClasses = other.maxEnrolledClasses;

        // Allocate new memory and copy the data
        enrolledClasses = new std::string[maxEnrolledClasses];
        for (int i = 0; i < noEnrolledClasses; i++)
        {
            enrolledClasses[i] = other.enrolledClasses[i];
        }
    }
    else
    {
        // If other.enrolledClasses is nullptr, set enrolledClasses to nullptr as well
        enrolledClasses = nullptr;
        noEnrolledClasses = 0;
        maxEnrolledClasses = 10; // Set the default value for maxEnrolledClasses
    }

    return *this;
}

void Student::setRollNumber(const string& rol)
{
    RollNumber = rol;
}
string Student::getRollNumber() const
{
    return RollNumber;
}

/////////////////////////////////////////////////////////////////////
////////////////////////////--TEACHER--//////////////////////////////
/////////////////////////////////////////////////////////////////////

Teacher::Teacher(string n, string m , string id, string pass, string num , string sub)
    : User("Teacher", n, m, id, pass, num)
{
    subject = sub;
}
