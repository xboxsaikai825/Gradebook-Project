#include "gradeBookMenu.h"

GradeBookMenu::GradeBookMenu() : Menu("Main Menu") {
	AddOption("1) List all grades");
	AddOption("2) View an assignment");
	AddOption("3) Add a grade");
	AddOption("4) Edit grades");
	AddOption("5) Remove a grade");
	AddOption("6) Calculate final grade");
	AddOption("7) Exit");
}