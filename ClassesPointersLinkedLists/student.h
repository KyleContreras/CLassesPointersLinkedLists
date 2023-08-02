#ifndef student_H
#define student_H

#include <iostream>
#include <string>

using namespace std;


class Student
{
public:
	friend class Link;
	friend class LList;

	// Default Constructor
	Student();

	// Constructor
	Student(string lName, string fName, int nClasses);

	// Overloaded >> to create a Student on the linked list
	friend istream& operator >>(istream& in, Student& record);

	// Overloaded <<
	friend ostream& operator <<(ostream& out, const Student& record);

	// Overloaded <
	friend bool operator< (const Student& student1, const Student& student2);

	// Add a class to a student's classList array
	Student* newClass(Student* student, string studentName, string theClass);

	// Remove a class from a student's classList array
	Student* removeClass(Student* student, string studentName, string theClass);

	// Set properties
	void setLastName(string lName);
	void setFirstName(string fName);
	void setNumClasses(int classNum);

	// Get properties
	string getLastName() const;
	string getFirstName() const;
	int getNumClasses() const;
	string getclassList();

private:
	string lastName;		// Student last name
	string firstName;		// Student first name
	int numClasses;			// number of classes the student is taking
	string classList[6];	// listing of classes the student is taking
};
#endif
