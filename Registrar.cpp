#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Registrar.h"

using namespace std;

// Load information from a text file with the given filename
// THIS FUNCTION IS COMPLETE
void Registrar::readTextfile(string filename) {
	ifstream myfile(filename);

	if (myfile.is_open()) {
		cout << "Successfully opened file " << filename << endl;
		string courseName;
		string cwid;
		char grade;
		while (myfile >> courseName >> cwid >> grade) {
			// cout << cwid << " " << grade << endl;
			addLine(courseName, cwid, grade);
		}
		myfile.close();
	}
	else
		throw invalid_argument("Could not open file " + filename);
}

Registrar::Registrar() {
	allStudents = new Student[50];
	size = 0;
}

Registrar::Registrar(const Registrar &r) {
	allStudents = new Student[50];
	size = r.size; // copy
	for (int i = 0; i < size; i++) {
		allStudents[i] = r.allStudents[i];
	}
}

Registrar& Registrar::operator = (const Registrar &r) {
	size = r.size;
	for (int i = 0; i < size; i++) {
		allStudents[i] = r.allStudents[i];
	}
	return *this;
}

// process a line from the text file
void Registrar::addLine(string courseName, string cwid, char grade) {
	// TO BE COMPLETED
	try {
		// if not throw student exist
		Student &a = getStudent(cwid);
		a.addCourseGrade(courseName, grade); 
	}
	catch (exception &b) {
		// if student does not exist create new one
		allStudents[size] = Student(cwid);
		allStudents[size].addCourseGrade(courseName, grade);
		size++;
	}
}
