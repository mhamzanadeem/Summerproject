#include "Assignment.h"

Assignment::Assignment()
{
	title = "Dummy Assignment";
	content = "Dummy Assignment Dummy Assignment Dummy Assignment Dummy Assignment Dummy AssignmentDummy Assignment Dummy Assignment Dummy Assignment Dummy AssignmentDummy AssignmentDummy Assignment Dummy Assignment Dummy Assignment Dummy Assignment Dummy Assignment Dummy Assignment";
	deadline = "7/7/2023";
}
Assignment::Assignment(string t, string c, string d)
{
	title = t;
	content = c;
	deadline = d;
}

Assignment::Assignment(const string& t, const string& c, const string& d)
{
	title = t;
	content = c;
	deadline = d;
}

string Assignment::getTitle() const 
{ 
	return title;
}

void Assignment::setTitle(const string& t) 
{ 
	title = t;
}

string Assignment::getDescription() const 
{ 
	return content;
}

void Assignment::setDescription(const string& d) 
{ 
	content = d;
}

string Assignment::getDueDate() const 
{ 
	return deadline;
}

void Assignment::setDueDate(const string& d) 
{ 
	deadline = d;
}

void Assignment::display() const {
	cout << "Title: " << title << "\t\t\t";
	cout << "Due Date : " << deadline << "\n";
	cout << "Content of Assignment:\n" << content << "\n\n";
	
}
