#include "assignment.h"

assignment::assignment() {
	id = "";
	groupId = "";
	description = "";
	int possiblePoints = 0;
	int totalPoints = 0;
}

assignment::assignment(string i, string gid, string desc, DateTime st, DateTime en, int poss, int tot) {
	id = i;
	groupId = gid;
	description = desc;
	start = st;
	end = en;
	possiblePoints = poss;
	totalPoints = tot;
}