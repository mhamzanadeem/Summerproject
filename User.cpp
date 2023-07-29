#include "user.h"

User::User(string n, string m, string id, string pass)
{
    name = n;
    email = m;
    loginID = id;
    password = pass;
}

// Getter functions
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
void User::setName(const string &n)
{
    name = n;
}

void User::setEmail(const string &m)
{
    email = m;
}

void User::setLoginID(const string &id)
{
    loginID = id;
}

void User::setPassword(const string &pass)
{
    password = pass;
}

/////////////////////////////////////////////////////////////////////
////////////////////////////--STUDENT--//////////////////////////////
/////////////////////////////////////////////////////////////////////

Student::Student(string n, string m, string id, string pass, string rol)
    : User(n, m, id, pass), enrolledClasses(nullptr), noEnrolledClasses(0), maxEnrolledClasses(10)
{
    RollNumber = rol;
}

Student::Student(const Student &other)
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
Student &Student::operator=(const Student &other)
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

void Student::setRollNumber(const string &rol)
{
    RollNumber = rol;
}
string Student::getRollNumber() const
{
    return RollNumber;
}
void Student::signup()
{   
    
    ofstream Id("id.txt", ios::app);
    ofstream pass("Password.txt", ios::app);
    cout << "\n\t\t*********** Sign Up ***********\n";
    cout << "\n\t\tEnter your name : ";
    string name;
    cin.ignore();
    getline(cin, name);
    setName(name);

    cout << "\n\t\tEnter your email : ";
    string email;
    getline(cin, email);
    setEmail(email);

    cout << "\n\t\tEnter your roll number : ";
    string rollnumber;
    getline(cin, rollnumber);
    setRollNumber(rollnumber);

    cout << "\n\t\tEnter your login ID : ";
    string id;
    getline(cin, id);
    setLoginID(id);

    cout << "\n\t\tEnter your password : ";
    string password;
    getline(cin, password);
    setPassword(password);

    cout << "\n\t\tAccount created successfully :)\n";
    getch();
    system("cls");

    Id << id << "\n";
    pass << password << "\n\n";

    cout << "Saved To Database!\n"; // Corrected the typo in the cout statement
}

void Student::signin()
{

    ifstream idFile("id.txt");
    ifstream passFile("Password.txt");

    cout << "Welcome Member, Please Enter Your Username and Password:\n\n";
    cout << "ID: ";
    string id;
    cin.ignore();
    getline(cin, id);

    cout << "Password: ";
    string inputPassword;
    getline(cin, inputPassword);

    string idLine;
    string passLine;
    while (getline(idFile, idLine) && getline(passFile, passLine))
    {
        if (idLine == id && passLine == inputPassword)
        {
            cout << "\nLogin Successful!\n";
            return; // Exit the function after successful login
        }
    }

    cout << "\nLogin Failed. Incorrect ID or Password.\n";
}

void Student::displayUserData() const
{
    cout << "Name: " << name << "\n";
    cout << "Email: " << email << "\n";
    cout << "Roll Number: " << RollNumber << "\n";
    cout << "Login ID: " << loginID << "\n";
    cout << "Password: " << password << "\n";
}

/////////////////////////////////////////////////////////////////////
////////////////////////////--TEACHER--//////////////////////////////
/////////////////////////////////////////////////////////////////////

Teacher::Teacher(string n, string m, string id, string pass, string sub)
    : User(n, m, id, pass)
{
    subject = sub;
}


void Teacher::signup()
{
    
    ofstream ID("id.txt", ios::app);
    ofstream pass("Password.txt", ios::app);
    cout << "\n\t\t*********** Sign Up ***********\n";
    cout << "\n\t\tEnter your name : ";
    string name;
    cin.ignore();
    getline(cin, name);
    setName(name);

    cout << "\n\t\tEnter your email : ";
    string email;
    getline(cin, email);
    setEmail(email);

    cout << "\n\t\tEnter your subject : ";
    string subject;
    getline(cin, subject);
    setSubject(subject);

    cout << "\n\t\tEnter your login ID : ";
    string id;
    getline(cin, id);
    setLoginID(id);

    cout << "\n\t\tEnter your password : ";
    string password;
    getline(cin, password);
    setPassword(password);

    cout << "\n\t\tAccount created successfully :)\n";
    getch();
    system("cls");

    ID << id << "\n";
    pass << password << "\n\n";

    cout << "Saved To Database!\n"; // Corrected the typo in the cout statement
}
void Teacher::signin()
{
    ifstream idFile("id.txt");
    ifstream passFile("Password.txt");

    cout << "Welcome Member, Please Enter Your Username and Password:\n\n";
    cout << "ID: ";
    string id;
    cin.ignore();
    getline(cin, id);

    cout << "Password: ";
    string inputPassword;
    getline(cin, inputPassword);

    string idLine;
    string passLine;
    while (getline(idFile, idLine) && getline(passFile, passLine))
    {
        if (idLine == id && passLine == inputPassword)
        {
            cout << "\nLogin Successful!\n";
            return; // Exit the function after successful login
        }
    }

    cout << "\nLogin Failed. Incorrect ID or Password.\n";
}
void Teacher::displayUserData() const
{
    cout << "Name: " << name << "\n";
    cout << "Email: " << email << "\n";
    cout << "Subject: " << subject << "\n";
    cout << "Login ID: " << loginID << "\n";
    cout << "Password: " << password << "\n";
}

void Teacher::setSubject(const string &sub)
{
    subject = sub;
}
string Teacher::getSubject() const
{
    return subject;
}
