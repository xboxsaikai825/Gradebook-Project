#include "course.h"

Course::Course() {
	term = "";
	section = "";
	courseName = "";
	units = 0;
	facultyId = "";
}

Course::Course(string ter, string sec, string name, int uni, string facId) {
	term = ter;
	section = sec;
	courseName = name;
	units = uni;
	facultyId = facId;
}