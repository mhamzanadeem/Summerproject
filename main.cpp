// #include "User.h"
// #include <iostream>
// #include <conio.h>
// #include <string>
// using namespace std;
// int main()
// {
//   while(1){ 
//   int option;
//   User U1;
//   cout << "\n\t*********** FAST CLASSROOM MANAGEMENT SYSTEM ***********\n";
//   cout << "\n\t\t>>Please Choose One Option \n";
//   cout << "\n\t\t1.Student\n\n\t\t2.Teacher\n\n\t\t3.Close Application\n";

//   while (1)
//   {
//     cout << "\n\t\tEnter your choice : ";
//     cin >> option;

//     switch (option)
//     {
//     case 1:
//       while (1)
//       {
//         system("cls");
//         cout << "\n\t\t*********** Student ***********\n";
//         cout << "\n\t\t1.Sign Up\n\n\t\t2.Sign In\n\n\t\t3.Back\n";
//         cout << "\n\t\tEnter your choice : ";
//         cin >> option;

//         switch (option)
//         {
//         case 1:

//           system("cls");
//           U1.signup();
          
//           break;

//         case 2:
//           system("cls");
//           U1.signin();
//           break;

//         case 3:
//           system("cls");
//           break;

//         default:
//           cout << "\n\t\tPlease enter correct option :(";
//           getch();
//           system("CLS");
//           break;
//         }

//         break;
//       }
//     case 2:
//       system("cls");
//       system("cls");
//       cout << "\n\t\t*********** Teacher ***********\n";
//       cout << "\n\t\t1.Sign Up\n\n\t\t2.Sign In\n\n\t\t3.Back\n";
//       cout << "\n\t\tEnter your choice : ";
//       cin >> option;

//       switch (option)
//       {
//       case 1:
//         system("cls");
//         U1.signup();
//         getch();
//         system("cls");
//         break;

//       case 2:
//         system("cls");
//         U1.signin();
//         getch();
//         system("cls");
//         break;

//       case 3:
//         system("cls");
//         break;

//       default:
//         cout << "\n\t\tPlease enter correct option :(";
//         getch();
//         system("CLS");
//         break;
//       }
//       break;

//     case 3:
//       exit(0);
//       break;

//     default:
//       cout << "\n\t\tPlease enter correct option :(";
//       getch();
//       system("CLS");
//       break;
//     }
//   }
//   }
//   return 0;
// }
// User U1("Hassan", "naqvihassan205@gmail.com", "22I-0797", "i220797@nu.edu.pk", "fast");
//  Save user data to a text file
// U1.saveUserDataToFile("user_data.txt");

// Read user data from the text file and display it on the terminal
// User userFromFile = User::readUserDataFromFile("user_data.txt");
// userFromFile.displayUserData();

#include "User.h"
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
                User U1;
                U1.signup();
                system("cls");
                U1.saveUserDataToFile("user_data.txt");
                break;
            }
            case 2:
            {
                system("cls");
                User U1;
                U1.signin();
                // if (U1.signin()) {
                //     cout << "\n\t\tLogin successfully :)\n";
                // } else {
                //     cout << "\n\t\tLogin failed. Invalid login ID or password.\n";
                // }
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
                User U1;
                
                U1.signup();
                system("cls");
                U1.saveUserDataToFile("user_data.txt");
                break;
            }
            case 2:
            {
                system("cls");
                User U1;
                
                U1.signin();
                // if (U1.signin()) {
                //     cout << "\n\t\tLogin successfully :)\n";
                // } else {
                //     cout << "\n\t\tLogin failed. Invalid login ID or password.\n";
                // }
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
