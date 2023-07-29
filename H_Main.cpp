#include <iostream>
#include "User.h"
#include"Class.h"
#include <string>

using namespace std;

int main()
{
	//User U1("Hassan", "naqvihassan205@gmail.com", "22I-0797", "fast", "03123456789");
	//cout << U1.getEmail() <<endl;
	Student S1("Hassan", "naqvihassan205@gmail.com", "22I-0797", "fast", "03123456789");
	S1.setEmail("naqvihassan205@gmail.com");
	cout << S1.getEmail() << endl;
	Student S2(S1);
	S2.setName("Rafay");
	Teacher T1("Sir Jawad", "jawad.hassan@nu.edu.pk", "0786","Professor", "03012345678", "OOP");
	cout << T1.getLoginID() <<endl;
	ClassRoom C1("OOP", T1);
	C1.enrollStudent(S1);
	C1.enrollStudent(S2);
	C1.viewEnrolledStudents();

    return 0;
}
