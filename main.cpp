#include <iostream>
#include "input.hpp"
#include "addGrades.hpp"
#include "removeGrades.hpp"
#include "viewGrades.hpp"
#include "search.hpp"
#include "advancedFunctions.hpp"
#include "filefunctions.hpp"

using namespace std;

// This is the main function! 
int main()
{
	/* Feel free to delete this when you're testing your own functions. This is just for reference.
	 * You can also comment it out if you'd like to keep it.
	 */

	// Created an arbitrary student object named Jacquavius.
	Student Jacquavius;
	// testing readFromFile function
	readFromFile(Jacquavius);
	// For loop that prints out everything... this is a hint for one of the other functions.
	for (long long unsigned int i = 0; i < Jacquavius.records.size(); i++)
	{
		cout << Jacquavius.records.at(i).name << endl
		     << Jacquavius.records.at(i).description << endl
		     << Jacquavius.records.at(i).grade << endl
		     << Jacquavius.records.at(i).maxGrade << endl
		     << Jacquavius.records.at(i).weight << endl;
	}

  // terminate
  return 0;
}
