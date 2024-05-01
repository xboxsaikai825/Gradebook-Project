#pragma once
#include <string>
#include "dateTime.h"

using namespace std;

class assignment
{
public:
	assignment();

	assignment(string i, string gid, string desc, DateTime st, DateTime en, int poss, int tot);
private:
	string id;
	string groupId;
	string description;
	DateTime start;
	DateTime end;
	int possiblePoints;
	int totalPoints;
};

