#include "Student.h"

#include <iostream>

Student::Student() {
	// TO BE COMPLETED
	string cwid;
	string courseName[size];
	char grade[]size;
	
}

Student::Student(const string &cwid) {
	// TO BE COMPLETED
	this -> cwid = cwid;
	coursecount = 0;

}

string Student::getCWID() {
	// TO BE COMPLETED
	return cwid;
}

void Student::addCourseGrade (const string &courseName, char grade) {
	// TO BE COMPLETED
	this -> courseName[courseCount] = courseName;
	this -> grade[courseCount] = grade;
	courseCount ++;	//counter; increase

}

double Student::getGPA() {
	// TO BE COMPLETED
	int cScore;
	int i;
	cScore = i;
	for(i = 0, i < courseCount; i++){
		if(grade[i] >= 'A' && grade[i] <= 'E'){
			cScore += 4 - (grade[i] <= 'E');
		}
		else if(grade[i] >= 'a' && grade[i] <= 'e'){
			cScore += 4 - (grade[i] - 'a');
		}
	}
	if(courseCount == 0){
		return 0.0;
	}
	return (double) cScore/courseCount;
}

// print transcript in this (sample) format:
// TRANSCRIPT FOR CWID=279750343
// CS 121		C
// CS 253		B
// CS 131		B
// GPA = 2.6667
void Student::printTranscript() {
	// TO BE COMPLETED
	int cScore;
	int i;
	cScore = i;
	cout << "TRANSCRIPT for CWID = " << cwid << endl;
	for(i = 0, i < courseCount; i++){
		cout << coursename[i] << " " << grade[i] << endl;
		cScore += 4 - (grade[i] - 'A');
	}
	cout << "GPA = " << getGPA() << endl;

}

