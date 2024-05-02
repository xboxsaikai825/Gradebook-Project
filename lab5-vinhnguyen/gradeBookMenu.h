#pragma once

#include "menu.h"
#include "binary_tree.h"

class GradeBookMenu : public Menu {
public:
	GradeBookMenu();
private:
	Binary_tree list;
};