#include "filefunctions.hpp"
using namespace std;

void readFromFile(Student& student)
{
	cout << "Please input your Student ID: ";
	cin >> student.studentID;

	ifstream file;
	/* Opens file based on the student's ID. All files should be named using the student's ID.
 	 * When you open the file, you need to specify the path that the file is located in. This is not always the case, but
	 * I happened to run into an error when I didn't specify it. Replace the entire first portion with your own path directory.
	 */
	file.open("C:\\Users\\legen\\eclipse-workspace\\Student Management System\\Student-Grade-Management\\" + student.studentID + ".txt");

	// This checks if the file is opening or not. Someone put a better error message here pls :3
	if (!file.is_open())
	{
		cout << "Something happened. :c" << endl;
	}

	// Clears existing records for the student
	student.records.clear();

	/* While the file isn't corrupted and while it doesn't raise any errors,
	 * it'll continue to read from the file. It'll take in all the fields listed below,
	 * and then add it to the student's records (their assignments). This is dependent on
	 * how the data inside the .txt is formatted. Another thing to note is that this cannot
	 * take in multiple strings; it can only take in one word. How can we improve this?
	 * (HINT: We'll need to use getline, but then it gets a little complicated...)
	 */
	while (file.good())
	{
		Assignment assignment;
		file >> assignment.name
		     >> assignment.description
		     >> assignment.grade
		     >> assignment.maxGrade
		     >> assignment.weight;

		student.records.push_back(assignment);
	}

	// Feel free to delete this line.
	cout << "Read " << student.records.size() << " assignments for student " << student.studentID << endl;

	// Closes the file.
	file.close();
}

void writeToFile(Student& student)
{
	ofstream file;

}
