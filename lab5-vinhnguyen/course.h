#pragma once
#include <string>
#include <iostream>

using namespace std;

class Course
{
public:
	Course();

	Course(string ter, string sec, string name, int uni, string facId);

    // Set methods
    void set_term(string ter);
    void set_section(string sec);
    void set_courseName(string name);
    void set_units(int uni);
    void set_facultyId(string facId);

    // Get methods
    string get_term() const;
    string get_section() const;
    string get_courseName() const;
    int get_units() const;
    string get_facultyId() const;

    // Compare operators overloads
    bool operator<(Course& course);

    bool operator>(Course& course);

    // Cout operator overload
    friend ostream& operator<<(ostream& os, const Course& course);

private:
	string term;
	string section;
	string courseName;
	int units;
	string facultyId;
};

