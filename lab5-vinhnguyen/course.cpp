#include "course.h"

Course::Course() {
	term = "";
	section = "";
	courseName = "";
	units = 0;
	facultyId = "";
}

Course::Course(string ter, string sec, string name, int uni, string facId) {
	term = ter;
	section = sec;
	courseName = name;
	units = uni;
	facultyId = facId;
}

// Set methods
void Course::set_term(string ter) {
	term = ter;
}

void Course::set_section(string sec) {
	section = sec;
}

void Course::set_courseName(string name) {
	courseName = name;
}

void Course::set_units(int uni) {
	units = uni;
}

void Course::set_facultyId(string facId) {
	facultyId = facId;
}

// Get methods
string Course::get_term() const {
	return term;
}

string Course::get_section() const {
	return section;
}

string Course::get_courseName() const {
	return courseName;
}

int Course::get_units() const {
	return units;
}

string Course::get_facultyId() const {
	return facultyId;
}

// Compare operators overload

bool Course::operator<(Course& course) {
	return this->section < course.section;
}

bool Course::operator>(Course& course) {
	return this->section > course.section;
}

// Cout operator overload
ostream& operator<<(ostream& os, const Course& course) {
	os << course.section << endl;
	return os;
}