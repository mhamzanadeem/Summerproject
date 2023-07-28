#pragma once
#ifndef USER_H
#define USER_H
#include <iostream>
using namespace std;
#include <string>
class User
{
	string name;
	string email;
	string RollNumber;
	string loginID;
	string password;
public:
	User(string n = "", string m = "", string rol = "", string id = "", string pass = ""); // User Defined Default Constructor
////Getters
	string getName() const;
	string getEmail() const;
	string getRollNumber() const;
	string getLoginID() const;
	string getPassword() const;
////Setters
	void setName(const string& n);
	void setEmail(const string& m);
	void setRollNumber(const string& rol);
	void setLoginID(const string& id);
	void setPassword(const string& pass);
};


#endif // !USER_H
