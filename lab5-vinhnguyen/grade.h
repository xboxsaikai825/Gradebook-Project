#pragma once
#include <string>

using namespace std;

class Grade
{
public:
	Grade();

	Grade(int id, string sect, string desc, int wei);
private:
	int groupId;
	string section;
	string description;
	int weight;
};

