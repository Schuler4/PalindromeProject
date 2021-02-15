//***********************************************************************
//
// Defines methods and variable for info class
//
//***********************************************************************

#ifndef INFO_H
#define INFO_H 
#include <string>
#include <iostream>
using namespace std;

class info
{

private:
	string firstName; //Holds first name
	string lastName; //Holds last name
	string course; //Holds course name
	string assignmentName; //holds assignment name


public:
	info(string assignName); //Constrcutor. Passes in a different assignment name
	void displayInfo(string currentDate);  //Used to display output for info class

};

#endif