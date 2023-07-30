#pragma once
#ifndef USER_H
#define USER_H
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <conio.h>
#include "Class.h"

using namespace std;

class User
{
public:
	string name;
	string email;
	string loginID;
	string password;

	User(string n = "", string m = "", string id = "", string pass = ""); // User Defined Default Constructor
	// Getters
	string getName() const;
	string getEmail() const;
	string getLoginID() const;
	string getPassword() const;
	// Setters
	void setName(const string& n);
	void setEmail(const string& m);
	void setLoginID(const string& id);
	void setPassword(const string& pass);

	// Function to display user data on the terminal
	virtual void displayUserData() const = 0;

	// Function for signup
	virtual void signup() = 0;

	// Function for Login
	virtual void Login() = 0;

	virtual ~User() = default;
};
///////////////////////////--STUDENT--///////////////////////////////////

class Student : public User
{
public:
	string RollNumber;
	string* enrolledClasses;
	int noEnrolledClasses;
	int maxEnrolledClasses;

	Student(string n = "", string m = "", string id = "", string pass = "", string rol = "");
	Student(const Student& other);
	void setRollNumber(const string& rol);
	string getRollNumber() const;
	~Student();
	//// Enroll in a class
	//void newEnrollment(const string& className);

	//// View enrolled classes
	//void viewEnrolledClasses() const;

	// Operator Overloading
	// Assignment Operator
	Student& operator=(const Student& other);

	// Function to display user data on the terminal
	void displayUserData() const override;

	// Function for signup
	void signup() override;

	// Function for Login
	void Login() override;
};

///////////////////////////--TEACHER--///////////////////////////////////
class Teacher : public User
{
	string subject;
	ClassRoom ** ClassRooms;
	int numberOfClasses;
	int maxNumberOfClasses;

public:
	
	Teacher(string n = "", string m = "", string id = "", string pass = "", string sub = "");
	~Teacher();
	void setSubject(const string& sub);
	string getSubject() const;


	// Function to display user data on the terminal
	void displayUserData() const override;

	// Function for signup
	void signup() override;

	// Function for Login
	void Login();

	void createClass();
	Teacher readTeacherDataFromFile(const std::string& filename);
};

#endif // !USER_H
