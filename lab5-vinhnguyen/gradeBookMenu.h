#pragma once

#include <string>
#include <sstream>
#include "menu.h"
#include "fstream"
#include <iomanip>
#include "binarySearchTree.h"
#include "assignment.h"
#include "grade.h"
#include "faculty.h"
#include "course.h"

using namespace std;

class GradeBookMenu : public Menu {
public:
	GradeBookMenu();

	void init();
private:
	// Menu operations
	void doList(); // display all data from the root of the tree.

	void doView(); // view individual assignment and view group of assignments in rows and columns

	void doAdd(); // add to tree.

	void doEdit(); // edit any fields

	void doRemove(); // remove a node from the tree

	void calculateGrade(); // implement your grade and display.

	void doSave(); // save data to.csv file

	// Read csv operations
	void readAssignment(); // reads assignment-data.csv

	void readCourse(); // reads course-data.csv

	void readFaculty(); // reads faculty-data.csv

	void readGrade(); // reads grade-data.csv

	BinarySearchTree<Assignment> assignments;

	BinarySearchTree<Assignment> quizzes;

	BinarySearchTree<Assignment> labs;

	BinarySearchTree<Assignment> midterm;

	BinarySearchTree<Assignment> final;

	BinarySearchTree<Grade> gradingScale;

	BinarySearchTree<Course> courses;

	BinarySearchTree<Faculty> faculty;

	double assignmentsTotalPoints;
	double quizzesTotalPoints;
	double labsTotalPoints;
	double midtermsTotalPoints;
	double finalsTotalPoints;

	int assignmentsPoints;
	int quizzesPoints;
	int labsPoints;
	int midtermsPoints;
	int finalsPoints;
};
