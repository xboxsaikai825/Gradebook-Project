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