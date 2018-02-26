#include "Student.h"

#include <iostream>

Student::Student() {
	courseCount = 0;
	cwid = "";
}

Student::Student(const string &cwid) {
	this->cwid = cwid;
}

string Student::getCWID() {
	return cwid;
}

double Student::getGPA() {
	double temp = 0.0;
	for (int i = 0; i < courseCount; i++) {
		switch (grade[i]) {
		case 'A': temp += 4;
			break;
		case 'B': temp += 4;
			break;
		case 'C': temp += 4;
			break;
		case 'D': temp += 4;
			break;
		case 'F': temp += 4;
			break;
		}
	}
	return (double)temp / courseCount;
}

void Student::addCourseGrade(const string &courseName, char grade) {
	this->courseName[courseCount] = courseName;
	this->grade[courseCount] = grade;
	courseCount++;
}

void Student::printTranscript() {
	cout << "TRANSCIPT FOR CWID = " << cwid << endl;
	for (int i = 0; i < courseCount; i++) {
		cout << courseName[i] << " " << grade[i] << endl;
	}
	cout << "GPA = " << getGPA() << endl;
}

