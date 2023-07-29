#pragma once
#ifndef USER_H
#define USER_H
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;

class User
{

	string name;
	string email;
	string RollNumber;
	string loginID;
	string password;
public:
	User(string n = "", string m = "", string rol = "", string id = "", string pass = ""); // User Defined Default Constructor
	// Getters
	string getName() const;
	string getEmail() const;
	string getRollNumber() const;
	string getLoginID() const;
	string getPassword() const;
	// Setters
	void setName(const string &n);
	void setEmail(const string &m);
	void setRollNumber(const string &rol);
	void setLoginID(const string &id);
	void setPassword(const string &pass);
	// Function to save user data to a text file
	void saveUserDataToFile(const string &filename) const;

	// Function to read user data from a text file
	static User readUserDataFromFile(const string &filename);

	// Function to display user data on the terminal
	void displayUserData() const;

	//Function for signup
	void signup();

	//Function for signin
	void signin();
};

#endif // !USER_H
