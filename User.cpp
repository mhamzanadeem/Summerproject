#include "User.h"

User::User(string n , string m , string rol , string id , string pass)
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
void User::setName(const string& n)
{
    name = n;
}

void User::setEmail(const string& m)
{
    email = m;
}

void User::setRollNumber(const string& rol)
{
    RollNumber = rol;
}

void User::setLoginID(const string& id)
{
    loginID = id;
}

void User::setPassword(const string& pass)
{
    password = pass;
}
