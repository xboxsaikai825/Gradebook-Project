#pragma once
#include <string>
#include <iostream>

using namespace std;

class Faculty
{
public:
	Faculty();

	Faculty(string, string first, string last, string depart, string add, string ci, string st, string zi, string em, string ph);

    // Set methods
    void set_facultyId(string id);
    void set_firstName(string first);
    void set_lastName(string last);
    void set_department(string depart);
    void set_address(string add);
    void set_city(string ci);
    void set_state(string st);
    void set_zip(string zi);
    void set_email(string em);
    void set_phone(string ph);

    // Get methods
    string get_facultyId() const;
    string get_firstName() const;
    string get_lastName() const;
    string get_department() const;
    string get_address() const;
    string get_city() const;
    string get_state() const;
    string get_zip() const;
    string get_email() const;
    string get_phone() const;

    // Compare operators overload
    bool operator<(Faculty& other_assign);

    bool operator>(Faculty& other_assign);

    // cout operator overload
    friend ostream& operator<<(ostream& os, const Faculty& person);

private:
	string facultyId;
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

