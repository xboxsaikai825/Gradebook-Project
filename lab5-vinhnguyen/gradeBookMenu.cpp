#include "gradeBookMenu.h"

const string ASSIGNMENT_DATA = "assignment-data.csv";
const string COURSE_DATA = "course-data.csv";
const string FACULTY_DATA = "faculty-data.csv";
const string GRADE_SCALE = "grade-scale.csv";

enum COMMAND { LIST = '1', VIEW = '2', ADD = '3', EDIT = '4', DELETE = '5', CALC = '6', EXIT = '7' };

GradeBookMenu::GradeBookMenu() : Menu("Grade Book") {
	addOption("1) List all grades");
	addOption("2) View an assignment");
	addOption("3) Add a grade");
	addOption("4) Edit grades");
	addOption("5) Remove a grade");
	addOption("6) Calculate final grade");
	addOption("7) Exit");

	init();
}

void GradeBookMenu::init() {
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

}

void GradeBookMenu::doView() { // view individual assignment and view group of assignments in rows and columns

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