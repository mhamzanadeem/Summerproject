#include "User.h"

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

/////////////////////////////////////////////////////////////////////
////////////////////////////--STUDENT--//////////////////////////////
/////////////////////////////////////////////////////////////////////

Student::Student(string n, string m, string id, string pass, string rol)
    : User(n, m, id, pass), enrolledClasses(nullptr), noEnrolledClasses(0), maxEnrolledClasses(10)
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
    RollNumber = other.getRollNumber();
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
void Student::signup()
{
    ofstream mail("S_mail.txt", ios::app);
    ofstream roll("S_rollNumber.txt", ios::app);
    ofstream nam("S_name.txt", ios::app);
    ofstream Id("S_id.txt", ios::app);
    ofstream pass("S_Password.txt", ios::app);
    cout << "\n\t\t*********** Sign Up ***********\n";
    cout << "\n\t\tEnter your name : ";
    string name;
    //cin.ignore();
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
    _getwch();
    system("cls");

    nam << name << "\n";
    mail << email << "\n";
    roll << rollnumber << "\n";
    Id << id << "\n";
    pass << password << "\n";

    cout << "Saved To Database!\n"; // Corrected the typo in the cout statement
}

void Student::Login()
{
    ifstream mailFile("S_mail.txt");
    ifstream rollFile("S_rollNumber.txt");
    ifstream namFile("S_name.txt");
    ifstream idFile("S_id.txt");
    ifstream passFile("S_Password.txt");

    cout << "\t\tWelcome Member, Please Enter Your Username and Password:\n\n";
    cout << "Enter your Login ID: ";
    string id;
    //cin.ignore();
    getline(cin, id);

    cout << "Enter you Password: ";
    string inputPassword;
    getline(cin, inputPassword);


    string namLine;
    string mailLine;
    string rolLine;
    string idLine;
    string passLine;
    while (getline(idFile, idLine) && getline(passFile, passLine) && getline(namFile, namLine) && getline(rollFile, rolLine) && getline(mailFile, mailLine))
    {
        if (idLine == id && passLine == inputPassword)
        {
            this->setName(namLine);
            this->setEmail(mailLine);
            this->setRollNumber(rolLine);
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
    : User(n, m, id, pass),
     subject(sub),numberOfClasses(0),maxNumberOfClasses(5) 
{
    ClassRooms = new ClassRoom * [maxNumberOfClasses];
}

Teacher::~Teacher()
{
    for (int i = 0; i < numberOfClasses; ++i)
    {
        delete ClassRooms[i]; //Deallocate each ClassRoom object from Array
    }
    delete[] ClassRooms; //Delete array of ClassRoom object
}
void Teacher::signup()
{
    ofstream mail("T_mail.txt", ios::app);
    ofstream sub("T_subject.txt", ios::app);
    ofstream nam("T_name.txt", ios::app);
    ofstream ID("T_id.txt", ios::app);
    ofstream pass("T_Password.txt", ios::app);
    cout << "\n\t\t*********** Sign Up ***********\n";
    cout << "\n\t\tEnter your name : ";
    string name;
    //cin.ignore();
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
    _getwch();
    system("cls");

    nam << name << "\n";
    mail << email << "\n";
    sub << subject << "\n";
    ID << id << "\n";
    pass << password << "\n";

    cout << "Saved To Database!\n"; // Corrected the typo in the cout statement
}
void Teacher::Login()
{
    ifstream mailFile("T_mail.txt");
    ifstream subFile("T_subject.txt");
    ifstream namFile("T_name.txt");
    ifstream idFile("T_id.txt");
    ifstream passFile("T_Password.txt");

    cout << "Welcome Member, Please Enter Your Username and Password:\n\n";
    cout << "ID: ";
    string id;
    //cin.ignore();
    getline(cin, id);

    cout << "Password: ";
    string inputPassword;
    getline(cin, inputPassword);

    string mailLine;
    string subLine;
    string namLine;
    string idLine;
    string passLine;
    while (getline(idFile, idLine) && getline(passFile, passLine) && getline(namFile, namLine) && getline(subFile, subLine) && getline(mailFile, mailLine))
    {
        if (idLine == id && passLine == inputPassword)
        {
            this->setName(namLine);
            this->setEmail(mailLine);
            this->setSubject(subLine);
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

void Teacher::setSubject(const string& sub)
{
    subject = sub;
}
string Teacher::getSubject() const
{
    return subject;
}

void Teacher::createClassRoom()
{
    if (numberOfClasses >= maxNumberOfClasses)
    {
        // If the array is full, resize it by creating a larger array and copying the elements
        maxNumberOfClasses *= 2;
        ClassRoom** temp = new ClassRoom * [maxNumberOfClasses];
        for (int i = 0; i < numberOfClasses; i++)
        {
            temp[i] = ClassRooms[i];
        }
        delete[] ClassRooms;
        ClassRooms = temp;
    }

    cout << "Enter the name of the class: ";
    string className;
    //cin.ignore(); // Ignore the newline character in the input buffer
    getline(cin, className);
    string code;
    cout << "Enter the GCR code you want: ";
    getline(cin, code);
    

    ClassRooms[numberOfClasses] = new ClassRoom(className, this, code);
    numberOfClasses++;

    string n = className + ".txt";
    ofstream classFile(n, ios::app);

    classFile << className << "\n";
    classFile << code << "\n";

    
    cout << "Classroom created successfully!" << endl;
}
void Teacher::viewClassRoom()
{
    cout << "List of created ClassRooms:\n";
    for (int i = 0; i < numberOfClasses; i++)
    {
        cout << ClassRooms[i] << endl;
    }
}
