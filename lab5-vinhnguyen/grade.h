#pragma once
#include <string>
#include <iostream>

using namespace std;

class Grade
{
public:
	Grade();

	Grade(string id, string sect, string desc, int wei);

    // Set methods
    void set_groupId(string id);
    void set_section(string sect);
    void set_description(string desc);
    void set_weight(int wei);

    // Get methods
    string get_groupId() const;
    string get_section() const;
    string get_description() const;
    int get_weight() const;

    // Compare operators overload
    bool operator<(Grade& other_grade);

    bool operator>(Grade& other_grade);

    // cout operator overload
    friend ostream& operator<<(ostream& os, const Grade& grade);
private:
	string groupId;
	string section;
	string description;
	int weight;
};

