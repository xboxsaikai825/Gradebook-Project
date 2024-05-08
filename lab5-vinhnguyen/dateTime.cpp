/**
* Author: John Doe
* Description: Manage Tasks using Map, HashTable, and Try-Catch
* Due Date: 10/24/2024
*/

#include <string>
#include <iostream>
#include <iomanip>
#include "dateTime.h"
#include "dateType.h"
#include <sstream>

using namespace std;

/*******************************************************************/
//Constructor - also calls DateType's parameterized constructor
DateTime::DateTime(int h, int mi, int s, int mo, int d, int y)
	:DateType(mo, d, y) {
	hr = h;
	min = mi;
	sec = s;
}

//Sets the time by passing in a string in hr:min:sec format
void DateTime::setDateTime(string dateTime) {
	string sdate, stime;
	if (dateTime.length() > 10) {
		int pos = (int)dateTime.find(" ");
		sdate = dateTime.substr(0, pos);
		stime = dateTime.substr(pos + 1);
		this->setDate(sdate);
	}
	else {
		stime = dateTime;
	}
	hr = stoi(stime.substr(0, 2));
	min = stoi(stime.substr(3, 2));
	sec = stoi(stime.substr(6, 2));
}

// Return MM/DD/YYYY HH:MM:SS
string DateTime::toString() {
	string stime = !isEmpty() ? (" " + to_string(hr) + ":" + to_string(min) + ":" + to_string(sec)) : "";

	// Format the time components with leading zeros if necessary
	stringstream ss;
	ss << setw(2) << setfill('0') << hr << ":" << setw(2) << setfill('0') << min << ":" << setw(2) << setfill('0') << sec;
	string formattedTime = ss.str();

	return this->getDate().toString() + " " + formattedTime;
}