#pragma once
#include <string>
#include "dateTime.h"
#include <iostream>

using namespace std;

class Assignment
{
public:
	Assignment();

	Assignment(string i, string gid, string desc, DateTime st, DateTime en, int poss, int tot);

	// Set methods
	void set_id(string);
	void set_groupId(string);
	void set_description(string);
	void set_start(string);
	void set_end(string);
	void set_possiblePoints(int);
	void set_totalPoints(int);

	// Get methods
	string get_id() const;
	string get_groupId() const;
	string get_description() const;
	DateTime get_start() const;
	DateTime get_end() const;
	int get_possiblePoints() const;
	int get_totalPoints() const;

	// Compare operators overload
	bool operator<(Assignment& other_assign);

	bool operator>(Assignment& other_assign);

	// cout operator overload
	friend ostream& operator<<(ostream& os, const Assignment& assignment);

private:
	string id;
	string groupId;
	string description;
	DateTime start;
	DateTime end;
	int possiblePoints;
	int totalPoints;
};



