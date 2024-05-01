#include "faculty.h"

faculty::faculty() {
	facultyId = 0;
	firstName = "";
	lastName = "";
	department = "";
	address = "";
	city = "";
	state = "";
	zip = "";
	email = "";
	phone = "";
}

faculty::faculty(int id, string first, string last, string depart, string add, string ci, string st, string zi, string em, string ph) {
	facultyId = id;
	firstName = first;
	lastName = last;
	department = depart;
	address = add;
	city = ci;
	state = st;
	zip = zi;
	email = em;
	phone = ph;
}