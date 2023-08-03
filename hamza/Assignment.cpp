#include "Assignment.h"

Assignment::Assignment()
{
	title = "Dummy Assignment";
	content = "Dummy Assignment Dummy Assignment Dummy Assignment Dummy Assignment Dummy AssignmentDummy Assignment Dummy Assignment Dummy Assignment Dummy AssignmentDummy AssignmentDummy Assignment Dummy Assignment Dummy Assignment Dummy Assignment Dummy Assignment Dummy Assignment";
	deadline = "7/7/2023";
	filename="";
}
Assignment::Assignment(string t, string c, string d, string f)
{
	title = t;
	content = c;
	deadline = d;
	filename = f;
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

void Assignment::txtfile() {
	// Open a file in append mode
    ofstream outfile("OOP_assignment.txt", ios::app);

    if (outfile.is_open())
    {
        // Write the assignment details to the file
        outfile << "Title: " << title << endl;
        outfile << "Content: " << content << endl;
        outfile << "Deadline: " << deadline << endl;
        outfile << "File name: " << filename << endl;
        outfile << "-----------------------------------" << endl;

        cout << "Assignment added successfully and saved to file.\n";

        // Close the file
        outfile.close();
    }
    else
    {
        cout << "Error: Unable to open the file.\n";
    }
}
