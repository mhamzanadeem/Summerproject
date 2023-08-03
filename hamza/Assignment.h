#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Assignment
{
	string title;
	string content;
	string deadline;
	string filename;
public:
	Assignment();
	Assignment(string , string , string, string);
	Assignment(const string& title, const string& description, const string& dueDate);

	string getTitle() const;
	void setTitle(const string& t);

	string getDescription() const;
	void setDescription(const  string& d);

	string getDueDate() const;
	void setDueDate(const string& d);

	void txtfile() ;

};
