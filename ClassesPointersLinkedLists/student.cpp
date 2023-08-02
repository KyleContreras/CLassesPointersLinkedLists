#include<iostream>
#include <string>
#include "student.h"

using namespace std;

// Default Constructor
Student::Student()
{
	this->setLastName(" ");
	this->setFirstName(" ");
	this->setNumClasses(0);
	//this->classList = NULL;
}

// Student Constructor
Student::Student(string lName, string fName, int nClasses)
{
	this->lastName = lName;
	this->firstName = fName;
	this->numClasses = numClasses;
}

// Overloaded >> to fill studentObj with the correct information
istream& operator >>(istream& in, Student& record)
{
	string lName;	// Last name from 'input.txt'
	string fName;	// First name from 'output.txt'
	int classNum = 6;	// Number of classes each student is taking

	in >> lName;
	record.setLastName(lName);

	in >> fName;
	record.setFirstName(fName);

	in >> classNum;
	record.setNumClasses(classNum);

	//record.classList = new string[6];

	// Enter the student's classes. Add them to classList
	for (int i = 0; i < classNum; i++)
	{
		string theClass;
		in >> theClass;
		record.classList[i] = theClass;
	}

	return in;
}

// Overloaded << to print studentObj to files
ostream& operator<<(ostream& out, const Student& record)
{
	int classNum = record.getNumClasses();
	//string* classes = record.classList;

	out << record.getLastName() << " " << record.getFirstName() << " " << classNum << " ";

	if (record.classList != NULL)
	{
		for (int i = 0; i < 6; i++)
		{
			out << record.classList[i] << " ";
		}
		out << endl;
	}

	return out;
}

// Overloaded < to order the students by name
bool operator< (const Student& student1, const Student& student2)
{
	string student1Name = student1.getLastName() + " " + student1.getFirstName();
	string student2Name = student2.getLastName() + " " + student2.getFirstName();

	return student1Name < student2Name;
}

// ********** Set student properties **********
void Student::setLastName(string lName)
{
	this->lastName = lName;
}

void Student::setFirstName(string fName)
{
	this->firstName = fName;
}

void Student::setNumClasses(int classNum)
{
	this->numClasses = classNum;
}

// ********** Get student properties **********
string Student::getLastName() const
{
	return this->lastName;
}

string Student::getFirstName() const
{
	return this->firstName;
}

int Student::getNumClasses() const
{
	return this->numClasses;
}


string Student::getclassList()
{
	return string();
}
