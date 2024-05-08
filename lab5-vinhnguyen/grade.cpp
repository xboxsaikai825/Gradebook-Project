#include "grade.h"

Grade::Grade() {
	groupId = "";
	section = "";
	description = "";
	weight = 0;
}

Grade::Grade(string id, string sect, string desc, int wei) {
	groupId = id;
	section = sect;
	description = desc;
	weight = wei;
}

// Set methods
void Grade::set_groupId(string id) {
	groupId = id;
}

void Grade::set_section(string sect) {
	section = sect;
}

void Grade::set_description(string desc) {
	description = desc;
}

void Grade::set_weight(int wei) {
	weight = wei;
}

// Get methods
string Grade::get_groupId() const {
	return groupId;
}

string Grade::get_section() const {
	return section;
}

string Grade::get_description() const {
	return description;
}

int Grade::get_weight() const {
	return weight;
}

// Compare operators overload
bool Grade::operator<(Grade& other_grade) {
	return this->description < other_grade.description;
}

bool Grade::operator>(Grade& other_grade) {
	return this->description > other_grade.description;
}

// Cout operator overload
ostream& operator<<(ostream& os, const Grade& grade) {
	os << grade.description << ": "  << grade.weight << "%" << endl;
	return os;
}

// operator== overload
bool Grade::operator==(Grade& other) {
	return this->description == other.description;
}