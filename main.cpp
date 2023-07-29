#include "user.h"
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

// Function to display the main menu and get user choice
int mainMenu() {
    int option;
    cout << "\n\t*********** FAST CLASSROOM MANAGEMENT SYSTEM ***********\n";
    cout << "\n\t\t>>Please Choose One Option \n";
    cout << "\n\t\t1.Student\n\n\t\t2.Teacher\n\n\t\t3.Close Application\n";
    cout << "\n\t\tEnter your choice : ";
    cin >> option;
    return option;
}

// Function to display the student menu and get student choice
int studentMenu() {
    int option;
    cout << "\n\t\t*********** Student ***********\n";
    cout << "\n\t\t1.Sign Up\n\n\t\t2.Sign In\n\n\t\t3.Back\n";
    cout << "\n\t\tEnter your choice : ";
    cin >> option;
    return option;
}

// Function to display the teacher menu and get teacher choice
int teacherMenu() {
    int option;
    cout << "\n\t\t*********** Teacher ***********\n";
    cout << "\n\t\t1.Sign Up\n\n\t\t2.Sign In\n\n\t\t3.Back\n";
    cout << "\n\t\tEnter your choice : ";
    cin >> option;
    return option;
}

int main() {
    while (true) {
        int mainOption = mainMenu();
        switch (mainOption) {
        case 1:
        {system("cls");
            int studentOption = studentMenu();
            switch (studentOption) {
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
                s1.signin();
                getch();
                system("cls");
                break;
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
        case 2:
        {system("cls");
            int teacherOption = teacherMenu();
            switch (teacherOption) {
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
                
                t1.signin();
                getch();
                system("cls");
                break;
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
