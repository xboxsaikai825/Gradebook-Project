#pragma once
#include <string>

using namespace std;

class Faculty
{
public:
	Faculty();

	Faculty(int, string first, string last, string depart, string add, string ci, string st, string zi, string em, string ph);
private:
	int facultyId;
	string firstName;
	string lastName;
	string department;
	string address;
	string city;
	string state;
	string zip;
	string email;
	string phone;
};

