#pragma once
#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>

using namespace std;

///////////////////////////--USER--////////////////////////////////////////
class User
{
	string role;
	string name;
	string email;
	string loginID;
	string password;
	string contactNumber;
public:
	User(string r = "", string n = "", string m = "", string id = "", string pass = "", string num = ""); // User Defined Default Constructor
////Getters
	string getRole() const;
	string getName() const;
	string getEmail() const;
	string getLoginID() const;
	string getPassword() const;
////Setters
	void setRole(const string& r);
	void setName(const string& n);
	void setEmail(const string& m);
	void setLoginID(const string& id);
	void setPassword(const string& pass);
////Operators
	User& operator=(const User& rhs);
};


///////////////////////////--STUDENT--///////////////////////////////////

class Student :public User
{
	string RollNumber;
	string* enrolledClasses;
	int noEnrolledClasses;
	int maxEnrolledClasses;
public:
	Student(string n = "", string m = "", string id = "", string pass = "",string num = "", string rol = "");
	Student(const Student& other);
	void setRollNumber(const string& rol);
	string getRollNumber() const;
	~Student();
	//// Enroll in a class
	//void newEnrollment(const string& className);

	//// View enrolled classes
	//void viewEnrolledClasses() const;


	//Operator Overloading
	//Assignment Operator
	Student& operator=(const Student& other);

};


///////////////////////////--TEACHER--///////////////////////////////////
class Teacher :public User
{
	string subject;
public:
	Teacher(string n = "", string m = "", string id = "", string pass = "",string num = "", string sub = "");

};

#endif // !USER_H
