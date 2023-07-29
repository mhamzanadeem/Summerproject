#include "User.h"

User::User(string n, string m, string rol, string id, string pass)
{
    name = n;
    email = m;
    RollNumber = rol;
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

string User::getRollNumber() const
{
    return RollNumber;
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

void User::setRollNumber(const string &rol)
{
    RollNumber = rol;
}

void User::setLoginID(const string &id)
{
    loginID = id;
}

void User::setPassword(const string &pass)
{
    password = pass;
}

void User::saveUserDataToFile(const string &filename) const
{
    ofstream outFile(filename);
    if (outFile.is_open())
    {
        outFile << "Name: " << name << "\n";
        outFile << "Email: " << email << "\n";
        outFile << "Roll Number: " << RollNumber << "\n";
        outFile << "Login ID: " << loginID << "\n";
        outFile << "Password: " << password << "\n";
        outFile.close();
        cout << "User data saved to " << filename << " successfully.\n";
    }
    else
    {
        cout << "Unable to open file: " << filename << endl;
    }
}

void User::signup()
{
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
}

void User::signin()
{

    cout << "\n\t\t*********** Sign In ***********\n";
    cout << "\n\t\tEnter your login ID : ";
    string loginID;
    cin.ignore();
    getline(cin, loginID);

    cout << "\n\t\tEnter your password : ";
    string pass;
    getline(cin, pass);

    if (loginID == getLoginID() && pass == getPassword())
    {
        cout << "\n\t\tLogin successfully :)\n";
    }
    else
    {
        cout << "\n\t\tLogin failed. Invalid login ID or password.\n";
    }

}
User User::readUserDataFromFile(const string &filename)
{
    ifstream inFile(filename);
    if (inFile.is_open())
    {
        string n, m, rol, id, pass;
        getline(inFile, n);    // Read Name line
        getline(inFile, m);    // Read Email line
        getline(inFile, rol);  // Read Roll Number line
        getline(inFile, id);   // Read Login ID line
        getline(inFile, pass); // Read Password line

        // Extracting the actual values from the lines
        n = n.substr(6);        // Remove "Name: " from the beginning
        m = m.substr(7);        // Remove "Email: " from the beginning
        rol = rol.substr(13);   // Remove "Roll Number: " from the beginning
        id = id.substr(10);     // Remove "Login ID: " from the beginning
        pass = pass.substr(11); // Remove "Password: " from the beginning

        inFile.close();
        return User(n, m, rol, id, pass);
    }
    else
    {
        cout << "Unable to open file: " << filename << endl;
        return User("", "", "", "", ""); // Return an empty user object
    }
}

void User::displayUserData() const
{
    cout << "Name: " << name << "\n";
    cout << "Email: " << email << "\n";
    cout << "Roll Number: " << RollNumber << "\n";
    cout << "Login ID: " << loginID << "\n";
    cout << "Password: " << password << "\n";
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
