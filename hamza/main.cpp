#include "User.h"
#include "Class.h"
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

// Function to get an integer input with validation
int getIntInput()
{
    int input;
    while (true)
    {
        cin >> input;
        if (cin.fail())
        {
            cout << "\n\t\tInvalid input. Please enter a valid integer: ";
            cin.clear();
            cin.ignore(256, '\n');
        }
        else
        {
            cin.ignore(256, '\n');
            return input;
        }
    }
}

// Function to display the main menu and get user choice
int mainMenu()
{
    int option;
    cout << "\n\t*********** FAST CLASSROOM MANAGEMENT SYSTEM ***********\n";
    cout << "\n\t\t>>Please Choose One Option\n";
    cout << "\n\t\t1.Student\n";
    cout << "\n\t\t2.Teacher\n";
    cout << "\n\t\t3.Close Application\n";
    cout << "\n\t\tEnter your choice : ";
    option = getIntInput();
    return option;
}

// Function to display the basic start menu and get choice
int startMenu()
{
    int option;
    cout << "\n\t\t1.Sign Up\n\n\t\t2.Login\n\n\t\t3.Back\n";
    cout << "\n\t\tEnter your choice : ";
    option = getIntInput();
    return option;
}
// Function to display the student to perform actions
int studentMenu()
{
    int option;
    cout << "\n\t\t*********** Student ***********\n";
    cout << "\n\t\t1.Join a ClassRoom\n\n\t\t2.View a ClassRoom \n\n\t\t3.Leave a ClassRoom\n";
    option = getIntInput();
    return option;
}
// Function to display the teacher to perform actions
int teacherMenu()
{
    int option;
    cout << "\n\t\t*********** Teacher ***********\n";
    cout << "\n\t\t1.Create a ClassRoom\n\n\t\t2.View  ClassRoom\n\n\t\t3.Add Assignment\n\n\t\t4.View a ClassRoom\n\n\t\t5.Logout\n";
    option = getIntInput();
    return option;
}

int main()
{
    while (true)
    {
        int mainOption = mainMenu();
        switch (mainOption)
        {
        case 1:
        {
            system("cls");
            cout << "\n\t\t*********** Student ***********\n";
            int choice = startMenu();
            switch (choice)
            {
            case 1:
            {
                system("cls");
                Student s1;
                s1.signup();
                system("cls");
                break;
            }
            case 2:
            {
                system("cls");
                Student s1;
                s1.Login();
                // cout << s1.getRollNumber() << endl;
                getch();
                system("cls");
                int studentOption = studentMenu();
                if (studentOption == 1)
                {
                    s1.JoinClassRoom();
                }
                else if (studentOption == 2)
                {
                    s1.ViewClassRoom();
                }
                break;
            }
            case 3:
                system("cls");
                break;
            default:
                cout << "\n\t\tPlease enter a correct option :( ";
                getch();
                system("cls");
                break;
            }
            break;
        }
        case 2:
        {
            system("cls");
            cout << "\n\t\t*********** Teacher ***********\n";
            int choice = startMenu();
            switch (choice)
            {
            case 1:
            {
                system("cls");
                Teacher t1;
                t1.signup();
                system("cls");
                break;
            }
            case 2:
            {
                system("cls");
                Teacher t1;
                t1.Login();
                getch();
                system("cls");
                int teacherOption = teacherMenu();
                switch (teacherOption)
                {
                case 1:
                {
                    t1.createClassRoom();
                    getch();
                    break;
                }
                case 2:
                {
                    t1.viewClassRoom();
                    break;
                }
                case 3:
                {
                    t1.addAssignment();
                    break;
                }
                case 4:
                {
                    t1.viewClassRoom();
                    break;
                }
                case 5:
                {
                    cout << "Teacher is logged out\n";
                    break;
                }
                default:
                    cout << "Invalid input!\n";
                }
            }
            case 3:
                system("cls");
                break;
            default:
                cout << "\n\t\tPlease enter a correct option :(";
                getch();
                system("cls");
                break;
            }
            break;
        }
        case 3:
            exit(0);
            break;
        default:
            cout << "\n\t\tPlease enter a correct option :(";
            getch();
            system("cls");
            break;
        }
    }

    return 0;
}
