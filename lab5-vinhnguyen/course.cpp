#include "course.h"

course::course() {
	term = "";
	section = "";
	courseName = "";
	units = 0;
	facultyId = "";
}

course::course(string ter, string sec, string name, int uni, string facId) {
	term = ter;
	section = sec;
	courseName = name;
	units = uni;
	facultyId = facId;
}