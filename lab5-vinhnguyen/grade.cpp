#include "grade.h"

Grade::Grade() {
	groupId = 0;
	section = "";
	description = "";
	weight = 0;
}

Grade::Grade(int id, string sect, string desc, int wei) {
	groupId = id;
	section = sect;
	description = desc;
	weight = wei;
}