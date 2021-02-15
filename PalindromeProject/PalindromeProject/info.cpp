//***********************************************************************
//
//   Used for implementation of info.h
//
//***********************************************************************

#include "info.h"


//Constructor
info::info(string assignName)
{
	
	firstName = "Taylor";
	lastName = "Schuler";
	course = "Intro to Data Structures";
	assignmentName = assignName;
}


//Used to display output for info class
void info::displayInfo(string currentDate)
{
	cout << "*******************************************" << endl;
	cout << "Name          : " << firstName << " " << lastName << endl;
	cout << "Course        : " << course << endl;
	cout << "Assignment    : " << assignmentName << endl;
	cout << "Compile Date  : " << __DATE__ << endl;
	cout << "Current Date  : " << currentDate << endl;
	cout << "*******************************************" << endl;
}


