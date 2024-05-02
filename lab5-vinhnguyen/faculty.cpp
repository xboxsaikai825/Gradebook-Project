#include "faculty.h"

Faculty::Faculty() {
	facultyId = "";;
	firstName = "";
	lastName = "";
	department = "";
	address = "";
	city = "";
	state = "";
	zip = "";
	email = "";
	phone = "";
}

Faculty::Faculty(string id, string first, string last, string depart, string add, string ci, string st, string zi, string em, string ph) {
	facultyId = id;
	firstName = first;
	lastName = last;
	department = depart;
	address = add;
	city = ci;
	state = st;
	zip = zi;
	email = em;
	phone = ph;
}

// Set methods
void Faculty::set_facultyId(string id) {
	facultyId = id;
}

void Faculty::set_firstName(string first) {
	firstName = first;
}

void Faculty::set_lastName(string last) {
	lastName = last;
}

void Faculty::set_department(string depart) {
	department = depart;
}

void Faculty::set_address(string add) {
	address = add;
}

void Faculty::set_city(string ci) {
	city = ci;
}

void Faculty::set_state(string st) {
	state = st;
}

void Faculty::set_zip(string zi) {
	zip = zi;
}

void Faculty::set_email(string em) {
	email = em;
}

void Faculty::set_phone(string ph) {
	phone = ph;
}

// Get methods
string Faculty::get_facultyId() const {
	return facultyId;
}

string Faculty::get_firstName() const {
	return firstName;
}

string Faculty::get_lastName() const {
	return lastName;
}

string Faculty::get_department() const {
	return department;
}

string Faculty::get_address() const {
	return address;
}

string Faculty::get_city() const {
	return city;
}

string Faculty::get_state() const {
	return state;
}

string Faculty::get_zip() const {
	return zip;
}

string Faculty::get_email() const {
	return email;
}

string Faculty::get_phone() const {
	return phone;
}

// Compare operators overload
bool Faculty::operator<(Faculty& other_assign) {
	return this->facultyId < other_assign.facultyId;
}

bool Faculty::operator>(Faculty& other_assign) {
	return this->facultyId > other_assign.facultyId;
}

// cout operator overload
ostream& operator<<(ostream& os, const Faculty& person) {
	os << person.facultyId << " " << person.firstName << " " << person.lastName << endl;
	return os;
}