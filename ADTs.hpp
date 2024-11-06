// This file is for all the structs.

# include <iostream>
# include <vector>
using namespace std;

struct Assignment
{
	string name;
	string description;
	double grade = 0.0;
	double maxGrade = 0.0;
	double weight = 0.0;
};

struct Student
{
	string studentID;
	vector<Assignment> records;

};


