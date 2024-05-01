#pragma once
#include <string>

using namespace std;

class course
{
public:
	course();

	course(string ter, string sec, string name, int uni, string facId);
private:
	string term;
	string section;
	string courseName;
	int units;
	string facultyId;
};

