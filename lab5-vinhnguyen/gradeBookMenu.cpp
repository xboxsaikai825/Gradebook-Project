#include "gradeBookMenu.h"

const string ASSIGNMENT_DATA = "assignment-data.csv";
const string COURSE_DATA = "course-data.csv";
const string FACULTY_DATA = "faculty-data.csv";
const string GRADE_SCALE = "grade-scale.csv";

enum COMMAND { LIST = 'a', VIEW = 'b', ADD = 'c', EDIT = 'd', DELETE = 'e', CALC = 'f', EXIT = 'x' };

GradeBookMenu::GradeBookMenu() : Menu("Grade Book") {
	addOption("a) List all grades");
	addOption("b) View an assignment");
	addOption("c) Add a grade");
	addOption("d) Edit grades");
	addOption("e) Remove a grade");
	addOption("f) Calculate final grade");
	addOption("x) Exit");

	init();
}

void GradeBookMenu::init() {

	readAssignment();
	readCourse();
	readFaculty();
	readGrade();

	char command = COMMAND::ADD;
	while (command != EXIT) {
		command = doMenuOption();
		switch (command) {
		case LIST:
			doList();
			break;
		case VIEW:
			doView();
			break;
		case ADD:
			doAdd();
			break;
		case EDIT:
			doEdit();
			break;
		case DELETE:
			doRemove();
			break;
		case CALC:
			calculateGrade();
			break;
		case EXIT:
			cout << "Bye!" << endl;
			break;
		default:
			cout << "Not a valid command. Please try again." << endl << endl;
			break;
		}
	}
}

// Menu operations
void GradeBookMenu::doList() { // display all data from the root of the tree.
	cout << "ASSIGNMENTS" << endl;
	assignments.print();

	cout << "QUIZZES" << endl;
	quizzes.print();

	cout << "LABS" << endl;
	labs.print();

	cout << "MIDTERMS" << endl;
	midterm.print();

	cout << "FINALS" << endl;
	final.print();
}

void GradeBookMenu::doView() { // view individual assignment and view group of assignments in rows and columns
	courses.print();
	faculty.print();
	gradingScale.print();
}

void GradeBookMenu::doAdd(){ // add to tree.

}

void GradeBookMenu::doEdit(){ // edit any fields

}

void GradeBookMenu::doRemove(){ // remove a node from the tree

}

void GradeBookMenu::calculateGrade() { // implement your grade and display.

}

void GradeBookMenu::doSave() { // save data to.csv file

}

void GradeBookMenu::readAssignment() { // reads assignment-data.csv
	string text;
	string line = "";
	ifstream inFile(ASSIGNMENT_DATA);
	bool firstRow = true;
	while (getline(inFile, line)) {
		// Skip the first row
		if (firstRow) {
			firstRow = false;
			continue;
		}
		Assignment new_assignment;
		stringstream ss(line);
		getline(ss, text, ',');
		new_assignment.set_id(text);
		getline(ss, text, ',');
		new_assignment.set_groupId(text);
		getline(ss, text, ',');
		new_assignment.set_description(text);
		getline(ss, text, ',');
		new_assignment.set_start(text);
		getline(ss, text, ',');
		new_assignment.set_end(text);
		getline(ss, text, ',');
		new_assignment.set_possiblePoints(stoi(text));
		getline(ss, text, ',');
		new_assignment.set_totalPoints(stoi(text));
		if (new_assignment.get_groupId() == "1")
			assignments.insert(new_assignment);
		else if (new_assignment.get_groupId() == "2")
			quizzes.insert(new_assignment);
		else if (new_assignment.get_groupId() == "3")
			labs.insert(new_assignment);
		else if (new_assignment.get_groupId() == "4")
			midterm.insert(new_assignment);
		else if (new_assignment.get_groupId() == "5")
			final.insert(new_assignment);
	}
	inFile.close();
}

void GradeBookMenu::readCourse() { // reads course-data.csv
	string text;
	string line = "";
	ifstream inFile(COURSE_DATA);
	bool firstRow = true;
	while (getline(inFile, line)) {
		// Skip the first row
		if (firstRow) {
			firstRow = false;
			continue;
		}
		Course new_course;
		stringstream ss(line);
		getline(ss, text, ',');
		new_course.set_term(text);
		getline(ss, text, ',');
		new_course.set_section(text);
		getline(ss, text, ',');
		new_course.set_courseName(text);
		getline(ss, text, ',');
		new_course.set_units(stoi(text));
		getline(ss, text, ',');
		new_course.set_facultyId(text);

		courses.insert(new_course);
	}
	inFile.close();
}

void GradeBookMenu::readFaculty() { // reads faculty-data.csv
	string text;
	string line = "";
	ifstream inFile(FACULTY_DATA);
	bool firstRow = true;
	while (getline(inFile, line)) {
		// Skip the first row
		if (firstRow) {
			firstRow = false;
			continue;
		}
		Faculty new_faculty;
		stringstream ss(line);
		getline(ss, text, ',');
		new_faculty.set_facultyId(text);
		getline(ss, text, ',');
		new_faculty.set_firstName(text);
		getline(ss, text, ',');
		new_faculty.set_lastName(text);
		getline(ss, text, ',');
		new_faculty.set_department(text);
		getline(ss, text, ',');
		new_faculty.set_address(text);
		getline(ss, text, ',');
		new_faculty.set_city(text);
		getline(ss, text, ',');
		new_faculty.set_state(text);
		getline(ss, text, ',');
		new_faculty.set_zip(text);
		getline(ss, text, ',');
		new_faculty.set_email(text);
		getline(ss, text, ',');
		new_faculty.set_phone(text);

		faculty.insert(new_faculty);
	}
}

void GradeBookMenu::readGrade() { // reads grade-data.csv
	string text;
	string line = "";
	ifstream inFile(GRADE_SCALE);
	bool firstRow = true;
	while (getline(inFile, line)) {
		// Skip the first row
		if (firstRow) {
			firstRow = false;
			continue;
		}
		Grade new_grade;
		stringstream ss(line);
		getline(ss, text, ',');
		new_grade.set_groupId(text);
		getline(ss, text, ',');
		new_grade.set_section(text);
		getline(ss, text, ',');
		new_grade.set_description(text);
		getline(ss, text, ',');
		new_grade.set_weight(stoi(text));

		gradingScale.insert(new_grade);
	}
}