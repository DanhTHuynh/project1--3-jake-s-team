#pragma once
#include <string>
#include <stdexcept>
#include "Student.h"

using namespace std;

class Registrar {
public:

	void readTextfile(string filename); // Load information from a text file with the given filename: THIS IS COMPLETE
	void addLine(string courseName, string cwid, char grade); // process a line from the text file
	Student& getStudent(string cwid) const; // return the Student object corresponding to a given CWID
	// getStudent must throw an exception if cwid is invalid
	// add constructors, destructors, assignment operators if needed
	Registrar(); //counstructor, allocate memory and initializes to 0
	Registrar(const Registrar &r); // copy
	Registrar& operator = (const Registrar &r);

private:
	// Add private member variables for your class along with any 
	// other variables required to implement the public member functions

	  Student* allStudents; // pointer
    int size; // the population
    int index; // the CWID

};
