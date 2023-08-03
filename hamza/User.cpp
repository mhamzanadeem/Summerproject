#include "User.h"
#include <fstream>

string encryptPassword(const string &password)
{
    string encryptedPassword = password;
    int shiftValue = 5; // Replace 5 with any number you want to add
    for (char &c : encryptedPassword)
    {
        // Add the shift value to each character
        c += shiftValue;
    }
    return encryptedPassword;
}
string decryptPassword(const string &encryptedPassword)
{
    string decryptedPassword = encryptedPassword;
    int shiftValue = 5; // Replace 5 with the same number used during encryption
    for (char &c : decryptedPassword)
    {
        // Subtract the shift value from each character to decrypt
        c -= shiftValue;
    }
    cout << "decryptedPassword: " << decryptedPassword << endl;
    return decryptedPassword;
}

/////////////////////////////////////////////////////////////////
/////////////////////////////--User--///////////////////////////
///////////////////////////////////////////////////////////////
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
    enrolledClasses = new ClassRoom *[maxEnrolledClasses];
    for (int i = 0; i < noEnrolledClasses; i++)
    {
        enrolledClasses[i] = nullptr;
    }
}
Student::Student(const Student &other)
    : User(other), enrolledClasses(nullptr), noEnrolledClasses(other.noEnrolledClasses), maxEnrolledClasses(other.maxEnrolledClasses)
{
    if (noEnrolledClasses > 0)
    {
        enrolledClasses = new ClassRoom *[maxEnrolledClasses];
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
    RollNumber = other.getRollNumber();
    // Deallocate the old memory
    delete[] enrolledClasses;

    // Copy the enrolled classes from other if it is not nullptr
    if (other.enrolledClasses != nullptr)
    {
        noEnrolledClasses = other.noEnrolledClasses;
        maxEnrolledClasses = other.maxEnrolledClasses;

        // Allocate new memory and copy the data
        enrolledClasses = new ClassRoom *[maxEnrolledClasses];
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
    ofstream mail("S_mail.txt", ios::app);
    ofstream roll("S_rollNumber.txt", ios::app);
    ofstream nam("S_name.txt", ios::app);
    ofstream Id("S_id.txt", ios::app);
    ofstream pass("S_Password.txt", ios::app);
    cout << "\n\t\t*********** Sign Up ***********\n";
    cout << "\n\t\tEnter your name : ";
    string name;
    // cin.ignore();
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
    password = encryptPassword(password);
    setPassword(password);

    cout << "\n\t\tAccount created successfully :)\n";
    getch();
    system("cls");

    nam << name << "\n";
    mail << email << "\n";
    roll << rollnumber << "\n";
    Id << id << "\n";
    pass << password << "\n";

    nam.close();
    mail.close();
    roll.close();
    Id.close();
    pass.close();
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
    // cin.ignore();
    getline(cin, id);

    cout << "Enter you Password: ";
    string inputPassword;
    getline(cin, inputPassword);
    // inputPassword =  decryptPassword(inputPassword);

    string namLine;
    string mailLine;
    string rolLine;
    string idLine;
    string passLine;
    while (getline(idFile, idLine) && getline(passFile, passLine) && getline(namFile, namLine) && getline(rollFile, rolLine) && getline(mailFile, mailLine))
    {
        passLine = decryptPassword(passLine);
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
void Student::JoinClassRoom()
{
    string nameOfClass, codeOfClass;
    cout << "Enter the name of the Class you want to join: ";
    getline(cin, nameOfClass);
    cout << "Enter the code of the classroom: ";
    getline(cin, codeOfClass);
    ifstream RecordFile("classRoomRecord.txt");
    while (!RecordFile.eof())
    {
        string checkName, checkCode;
        RecordFile >> checkName;
        RecordFile >> checkCode;
        if (checkName == nameOfClass && checkCode == codeOfClass)
        {
            nameOfClass += ".txt";
            ofstream data(nameOfClass, ios::app);
            data << " " << this->RollNumber << " ";
            data << this->name << " ";
            data << this->email << " ";
            data << "0";
            cout << "ClassRoom Joined Successfully." << endl;
            /* ClassRoom StudentInterfaceClassRoom;*/

            getch();
            system("cls");
        }
    }
}
void Student::ViewClassRoom()
{
    string rollNo;
    string name;
    cout << "Enter the name of the classRoom you want to view: ";
    cin >> name;
    name += ".txt";
    ifstream myFile(name);
    bool flag = false;
    while (!myFile.eof())
    {
        myFile >> rollNo;
        if (rollNo == this->RollNumber)
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        string printData;
        myFile.seekg(0, ios::beg);
        cout << "\n\nClass Subject: \t";
        myFile >> printData;
        cout << printData << endl;
        cout << "Teacher Mail: \t";
        myFile >> printData;
        cout << printData << endl;
        cout << "Teacher Name: \t";
        myFile >> printData;
        cout << printData << endl
             << endl;
        cout << "\t\t\t\t\"Student Data\"\n\n";
        string rollNumberStudent = "";
        string nameStudent = "";
        string mailStudent = "";
        cout << "\"Roll Number\"\t\t\t\"Student Name\"\t\t\t \"Student Mail\"\n";
        while (!myFile.eof())
        {
            myFile >> rollNumberStudent;
            myFile >> nameStudent;
            myFile >> mailStudent;
            if (rollNumberStudent == "0" || nameStudent == "0" || mailStudent == "0")
                break;
            cout << rollNumberStudent << "\t\t\t\t  " << nameStudent << "\t\t\t" << mailStudent << endl;
        }
         // Open the text file
        std::ifstream infile("classRoomRecord.txt");

        if (!infile.is_open())
        {
            std::cout << "Error: Unable to open the file.\n";
            return;
        }

        // Read the entire line from the file
        std::string line;
        std::getline(infile, line);

        // Close the file
        infile.close();

        // Create a stringstream to extract words from the line
        std::stringstream ss(line);

        // Store words in a vector of strings
        std::vector<std::string> words;
        std::string word;
        while (ss >> word)
        {
            words.push_back(word);
        }
        std::string courseCode;
        std::string assignmentNumber;
        std::string filename;
        // Now you can access individual words from the vector.
        if (words.size() >= 3)
        {
            courseCode = words[0];
            assignmentNumber = words[1];
            filename = words[2];

            // Output the variables
            // std::cout << "Course Code: " << courseCode << std::endl;
            // std::cout << "Assignment Number: " << assignmentNumber << std::endl;
            // std::cout << "Filename: " << filename << std::endl;
        }

        ifstream ReadAssignment(filename);
        string line1;
        cout<<"----------------------------------\n";
        while (getline(ReadAssignment, line1))
        {
            cout << line1 << endl;
        }
    
    }
    else
    {
        cout << "Error:\t The name of the class you entered either does not exist or you are not enrolled in it!!!" << endl;
    }
    getch();
}
/////////////////////////////////////////////////////////////////////
////////////////////////////--TEACHER--//////////////////////////////
/////////////////////////////////////////////////////////////////////

Teacher::Teacher(string n, string m, string id, string pass, string sub)
    : User(n, m, id, pass),
      subject(sub), numberOfClasses(0), maxNumberOfClasses(5)
{
    ClassRooms = new ClassRoom *[maxNumberOfClasses];
    for (int i = 0; i < numberOfClasses; i++)
    {
        ClassRooms[i] = nullptr;
    }
}

Teacher::~Teacher()
{
    for (int i = 0; i < numberOfClasses; ++i)
    {
        delete ClassRooms[i]; // Deallocate each ClassRoom object from Array
    }
    delete[] ClassRooms; // Delete array of ClassRoom object
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
    // cin.ignore();
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

    nam << name << "\n";
    mail << email << "\n";
    sub << subject << "\n";
    ID << id << "\n";
    pass << password << "\n";

    nam.close();
    mail.close();
    sub.close();
    ID.close();
    pass.close();
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
    // cin.ignore();
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
void Teacher::setSubject(const string &sub)
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
        ClassRoom **temp = new ClassRoom *[maxNumberOfClasses];
        for (int i = 0; i < numberOfClasses; i++)
        {
            temp[i] = ClassRooms[i];
        }
        delete[] ClassRooms;
        ClassRooms = temp;
    }

    ofstream classRecord("classRoomRecord.txt", ios::app);
    cout << "Enter the name of the class: ";
    string className;
    // cin.ignore(); // Ignore the newline character in the input buffer
    getline(cin, className);

    string code;
    cout << "Enter the GCR code you want: ";
    classRecord << className << " ";
    getline(cin, code);
    classRecord << code << "\n";
    ClassRooms[numberOfClasses] = new ClassRoom(className, this, code);
    numberOfClasses++;
    string n = className + ".txt";
    ofstream classFile(n, ios::app);
    classFile << this->subject << " ";
    classFile << this->email << " ";
    classFile << this->name << " \n";
    classFile.close();
    cout << "Classroom created successfully!" << endl;
}
void Teacher::viewClassRoom()
{
    /*  cout << "List of created ClassRooms:\n";
      for (int i = 0; i < numberOfClasses; i++)
      {
          cout << i + 1 << ". " << ClassRooms[i]->getClassName() << endl;
      }*/
    string teacherNameCheck;
    string name;
    cout << "Enter the name of the classRoom you want to view: ";
    cin >> name;
    name += ".txt";
    ifstream myFile(name);
    bool flag = false;
    while (!myFile.eof())
    {
        myFile >> teacherNameCheck;
        if (teacherNameCheck == this->name)
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {   system("cls");
        string printData;
        myFile.seekg(0, ios::beg);
        cout << "\n\nClass Subject: \t";
        myFile >> printData;
        cout << printData << endl;
        cout << "Teacher Mail: \t";
        myFile >> printData;
        cout << printData << endl;
        cout << "Teacher Name: \t";
        myFile >> printData;
        cout << printData << endl
             << endl;
        cout << "\t\t\t\t\"Student Data\"\n\n";
        string rollNumberStudent = "";
        string nameStudent = "";
        string mailStudent = "";
        cout << "\"Roll Number\"\t\t\t\"Student Name\"\t\t\t \"Student Mail\"\n";
        while (!myFile.eof())
        {
            myFile >> rollNumberStudent;
            myFile >> nameStudent;
            myFile >> mailStudent;
            if (rollNumberStudent == "0" || nameStudent == "0" || mailStudent == "0")
                break;
            cout << rollNumberStudent << "\t\t\t\t  " << nameStudent << "\t\t\t" << mailStudent << endl;
        }

        // Open the text file
        std::ifstream infile("classRoomRecord.txt");

        if (!infile.is_open())
        {
            std::cout << "Error: Unable to open the file.\n";
            return;
        }

        // Read the entire line from the file
        std::string line;
        std::getline(infile, line);

        // Close the file
        infile.close();

        // Create a stringstream to extract words from the line
        std::stringstream ss(line);

        // Store words in a vector of strings
        std::vector<std::string> words;
        std::string word;
        while (ss >> word)
        {
            words.push_back(word);
        }
        std::string courseCode;
        std::string assignmentNumber;
        std::string filename;
        // Now you can access individual words from the vector.
        if (words.size() >= 3)
        {
            courseCode = words[0];
            assignmentNumber = words[1];
            filename = words[2];

            // Output the variables
            // std::cout << "Course Code: " << courseCode << std::endl;
            // std::cout << "Assignment Number: " << assignmentNumber << std::endl;
            // std::cout << "Filename: " << filename << std::endl;
        }

        ifstream ReadAssignment(filename);
        string line1;
        cout<<"----------------------------------\n";
        while (getline(ReadAssignment, line1))
        {
            cout << line1 << endl;
        }
    }
    else
    {
        cout << "Error:\t The name of the class you entered either does not exist or you are not enrolled in it!!!" << endl;
    }
    getch();
}
void Teacher::addAssignment()
{
    string title;
    string content;
    string deadline;
    string filename;

    cout << "Title of Assignment: ";
    getline(cin, title);
    cout << "Content of Assignment: ";
    getline(cin, content);
    cout << "Deadline of Assignment: ";
    getline(cin, deadline);
    cout << "File name of Assignment: ";
    getline(cin, filename);

    Assignment A1(title, content, deadline, filename);
    A1.txtfile();
}