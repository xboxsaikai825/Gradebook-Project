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
	cout << endl << "ASSIGNMENTS" << endl;
	cout << "**************************************************" << endl;
	assignments.print();

	cout << endl << "QUIZZES" << endl;
	cout << "**************************************************" << endl;
	quizzes.print();

	cout << endl << "LABS" << endl;
	cout << "**************************************************" << endl;
	labs.print();

	cout << endl << "MIDTERMS" << endl;
	cout << "**************************************************" << endl;
	midterm.print();

	cout << endl << "FINALS" << endl;
	cout << "**************************************************" << endl;
	final.print();
}

void GradeBookMenu::doView() { // view individual assignment and view group of assignments in rows and columns
	courses.print();
	faculty.print();
	gradingScale.print();
}

void GradeBookMenu::doAdd(){ // add to tree.
	string id, groupId, desc, start, end, possPoints, totPoints;
	int total_assignments = assignments.get_total();
	id = to_string(++total_assignments);
	cout << "Enter the type of assignment (1)Assignment (2)Quiz (3)Lab (4)Midterm (5)Final: "; cin >> groupId;
	cin.ignore();
	cout << "Enter the description of the assignment: "; getline(cin, desc);
	cout << "Enter the start date of the assignment (M/D/YYYY H:MM:SS): "; getline(cin, start);
	cout << "Enter the end date of the assignment (M/D/YYYY H:MM:SS): "; getline(cin, end);
	cout << "Enter the total points of the assignment: "; getline(cin, possPoints);
	cout << "Enter the points earned on the assignment: "; getline(cin, totPoints);
	DateTime st, en;
	st.setDate(start);
	en.setDate(end);
	Assignment new_assignment(id, groupId, desc, st, en, stoi(possPoints), stoi(totPoints));
	if (groupId == "1")
		assignments.insert(new_assignment);
	else if (groupId == "2")
		quizzes.insert(new_assignment);
	else if (groupId == "3")
		labs.insert(new_assignment);
	else if (groupId == "4")
		midterm.insert(new_assignment);
	else if (groupId == "5")
		final.insert(new_assignment);
	cout << "Assignment added." << endl;
}

void GradeBookMenu::doEdit(){ // edit any fields
	this->doRemove();
	this->doAdd();
}

void GradeBookMenu::doRemove(){ // remove a node from the tree
	string user_desc;
	cin.ignore();
	cout << "Enter the name of the assignment: "; getline(cin, user_desc);
	DateTime time;
	Assignment user_assignment("", "", user_desc, time, time, 0, 0);
	assignments.erase(user_assignment);
	quizzes.erase(user_assignment);
	labs.erase(user_assignment);
	midterm.erase(user_assignment);
	final.erase(user_assignment);
	cout << "Assignment removed." << endl;
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

void GradeBookMenu::writeAssignment() {
	ofstream outFile(ASSIGNMENT_DATA);
	outFile << "Id,GroupId,Description,Start Date,End Date,Possible Points,Points" << endl;
	outFile << 
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