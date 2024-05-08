#include "assignment.h"

Assignment::Assignment() {
	id = "";
	groupId = "";
	description = "";
	int possiblePoints = 0;
	int totalPoints = 0;
}

Assignment::Assignment(string i, string gid, string desc, DateTime st, DateTime en, int poss, int tot) {
	id = i;
	groupId = gid;
	description = desc;
	start = st;
	end = en;
	possiblePoints = poss;
	totalPoints = tot;
}

// Set methods
void Assignment::set_id(string i) {
    id = i;
}

void Assignment::set_groupId(string gid) {
    groupId = gid;
}

void Assignment::set_description(string desc) {
    description = desc;
}

void Assignment::set_start(string st) {
    start.setDateTime(st);
}

void Assignment::set_end(string en) {
    end.setDateTime(en);
}

void Assignment::set_possiblePoints(int poss) {
    possiblePoints = poss;
}

void Assignment::set_totalPoints(int tot) {
    totalPoints = tot;
}

// Get methods
string Assignment::get_id() const {
    return id;
}

string Assignment::get_groupId() const {
    return groupId;
}

string Assignment::get_description() const {
    return description;
}

DateTime Assignment::get_start() const {
    return start;
}

DateTime Assignment::get_end() const {
    return end;
}

int Assignment::get_possiblePoints() const {
    return possiblePoints;
}

int Assignment::get_totalPoints() const {
    return totalPoints;
}

// Compare operator overloads
bool Assignment::operator<(Assignment& other_assign) {
    return this->description < other_assign.description;
}

bool Assignment::operator>(Assignment& other_assign) {
    return this->description > other_assign.description;
}

bool Assignment::operator==(Assignment& other) {
    return this->description == other.description;
}

// cout operator overload
ostream& operator<<(ostream& os, const Assignment& assignment) {
    //os << assignment.id << ',' << assignment.groupId << ',' << assignment.description << ',' << assignment.get_start().toString() << ',' << assignment.get_end().toString() << ',' << assignment.possiblePoints << ',' << assignment.totalPoints << endl;
    os << assignment.description << endl;
    return os;
}

string Assignment::toString() {
    return id + ',' + groupId + ',' + description + ',' + start.toString() + ',' + end.toString() + ',' + to_string(possiblePoints) + ',' + to_string(totalPoints) + '\n';
}