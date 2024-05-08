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
	cout << endl;
}

void GradeBookMenu::doView() { // view individual assignment and view group of assignments in rows and columns
	string option;
	cout << "a) View an individual assignment" << endl;
	cout << "b) view assignments by specific group" << endl;
	cin >> option;

	if (option == "a") {
		Assignment empty;
		Assignment assign;
		string input_desc;
		cin.ignore();
		cout << "Enter the assignment's name: "; getline(cin,input_desc);
		DateTime time;
		Assignment user_assignment("", "", input_desc, time, time, 0, 0);
		if (!(assignments.search(user_assignment) == empty))
			assign = assignments.search(user_assignment);
		else if (!(quizzes.search(user_assignment) == empty))
			assign = quizzes.search(user_assignment);
		else if (!(labs.search(user_assignment) == empty))
			assign = labs.search(user_assignment);
		else if (!(labs.search(user_assignment) == empty))
			assign = midterm.search(user_assignment);
		else
			assign = final.search(user_assignment);
		
		cout << endl << "ASSIGNMENT" << endl;
		cout << "**************************************************" << endl;
		cout << setw(50) << "NAME: " << assign.get_description() << endl;
		cout << setw(50) << "START: " << assign.get_start().toString() << endl;
		cout << setw(50) << "END: " << assign.get_end().toString() << endl;
		cout << setw(50) << "POINTS: " << assign.get_totalPoints() << endl;
		cout << setw(50) << "TOTAL POINTS: " << assign.get_possiblePoints() << endl;
	}
	else {
		string user_section;
		cout << "a) View assignments\nb) View quizzes\nc) View labs\nd) View midterms\ne) View finals\n"; cin >> user_section;
		if (user_section == "a") {
			cout << endl << "ASSIGNMENTS" << endl;
			cout << "**************************************************" << endl;
			assignments.print();
		}
		else if (user_section == "b") {
			cout << endl << "QUIZZES" << endl;
			cout << "**************************************************" << endl;
			quizzes.print();
		}
		else if (user_section == "c") {
			cout << endl << "LABS" << endl;
			cout << "**************************************************" << endl;
			labs.print();
		}
		else if (user_section == "d") {
			cout << endl << "MIDTERMS" << endl;
			cout << "**************************************************" << endl;
			midterm.print();
		}
		else {
			cout << endl << "FINALS" << endl;
			cout << "**************************************************" << endl;
			final.print();
		}
	}
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
	this->doSave();
}

void GradeBookMenu::doEdit(){ // edit any fields
	this->doRemove();
	this->doAdd();
	this->doSave();
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
	this->doSave();
}

void GradeBookMenu::calculateGrade() { // implement your grade and display.
	Grade assignment_scale("", "", "Assignments", 0);
	Grade quiz_scale("", "", "Quizzes", 0);
	Grade labs_scale("", "", "Labs", 0);
	Grade midterm_scale("", "", "Midterm", 0);
	Grade final_scale("", "", "Final Exam", 0);

	// finds weight for each section
	assignment_scale = gradingScale.search(assignment_scale);
	quiz_scale = gradingScale.search(quiz_scale);
	labs_scale = gradingScale.search(labs_scale);
	midterm_scale = gradingScale.search(midterm_scale);
	final_scale = gradingScale.search(final_scale);

	// calculate percentage of each group
	double assignmentPercentage = (assignmentsPoints / assignmentsTotalPoints);
	double quizPercentage = (quizzesPoints / quizzesTotalPoints);
	double labPercentage = (labsPoints / labsTotalPoints);
	double midtermPercentage = (midtermsPoints / midtermsTotalPoints);
	double finalPercentage = (finalsPoints / finalsTotalPoints);

	double weightedGrade = assignment_scale.get_weight() * assignmentPercentage + quiz_scale.get_weight() * quizPercentage + labs_scale.get_weight() * labPercentage + midterm_scale.get_weight() * midtermPercentage + final_scale.get_weight() * finalPercentage;

	cout << endl << "SECTION WEIGHTS" << endl;
	cout << "**************************************************" << endl;
	cout << setw(47) << "ASSIGNMENTS: " << assignment_scale.get_weight() << "%" << endl;
	cout << setw(47) << "QUIZZES: " << quiz_scale.get_weight() << "%" << endl;
	cout << setw(47) << "LABS: " << labs_scale.get_weight() << "%" << endl;
	cout << setw(47) << "MIDTERM: " << midterm_scale.get_weight() << "%" << endl;
	cout << setw(47) << "FINAL: " << final_scale.get_weight() << "%" << endl;

	cout << endl << "FINAL GRADE" << endl;
	cout << "**************************************************" << endl;
	cout << setw(50) << setprecision(3) << weightedGrade << "%" << endl;
}

void GradeBookMenu::doSave() { // save data to.csv file
	ofstream outFile(ASSIGNMENT_DATA);
	outFile << "Id,GroupId,Description,Start Date,End Date,Possible Points,Points" << endl;
	outFile << assignments.toString();
	outFile << quizzes.toString();
	outFile << labs.toString();
	outFile << midterm.toString();
	outFile << final.toString();
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
		if (new_assignment.get_groupId() == "1") {
			assignments.insert(new_assignment);
			assignmentsTotalPoints += new_assignment.get_possiblePoints();
			assignmentsPoints += new_assignment.get_totalPoints();
		}
		else if (new_assignment.get_groupId() == "2") {
			quizzes.insert(new_assignment);
			quizzesTotalPoints += new_assignment.get_possiblePoints();
			quizzesPoints += new_assignment.get_totalPoints();
		}
		else if (new_assignment.get_groupId() == "3") {
			labs.insert(new_assignment);
			labsTotalPoints += new_assignment.get_possiblePoints();
			labsPoints += new_assignment.get_totalPoints();
		}
		else if (new_assignment.get_groupId() == "4") {
			midterm.insert(new_assignment);
			midtermsTotalPoints += new_assignment.get_possiblePoints();
			midtermsPoints += new_assignment.get_totalPoints();
		}
		else if (new_assignment.get_groupId() == "5") {
			final.insert(new_assignment);
			finalsTotalPoints += new_assignment.get_possiblePoints();
			finalsPoints += new_assignment.get_totalPoints();
		}
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