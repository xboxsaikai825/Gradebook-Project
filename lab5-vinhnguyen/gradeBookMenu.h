#pragma once

#include <string>
#include "menu.h"
#include "assignment.h"
#include "binarySearchTree.h"

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

	BinarySearchTree<Assignment> assignments;
	BinarySearchTree<Assignment> quizzes;
	BinarySearchTree<Assignment> labs;
	BinarySearchTree<Assignment> midterm;
	BinarySearchTree<Assignment> final;
};
