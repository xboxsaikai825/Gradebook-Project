#include "grade.h"

grade::grade() {
	groupId = 0;
	section = "";
	description = "";
	weight = 0;
}

grade::grade(int id, string sect, string desc, int wei) {
	groupId = id;
	section = sect;
	description = desc;
	weight = wei;
}