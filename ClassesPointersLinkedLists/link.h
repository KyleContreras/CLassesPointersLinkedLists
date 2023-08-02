#ifndef link_H
#define link_H

#include "student.h"

class Link
{
public:
	friend class LList;
	friend class Student;

	// Default constructor
	Link()
	{
		Student studentObj;
		Link* nextLink = NULL;
		Link* prevLink = NULL;
	}

	// Constructor with parameters
	Link(Link* nextL, Link* prevL, const Student& stdnt)
		:nextLink(nextL), prevLink(prevL), studentObj(stdnt) {}

	// Set studentObj with the new Student
	void setStudent(Student theStdnt)
	{
		studentObj = theStdnt;
	}

	// Return studentObj
	Student getStudent() const
	{
		return studentObj;
	}

	// Set nextLink pointer
	void setNextLink(Link* pntr)
	{
		nextLink = pntr;
	}

	// Return nextLink pointer
	Link* getNextLink() const
	{
		return nextLink;
	}

	// Set prevLink pointer
	void setPrevLink(Link* pntr)
	{
		prevLink = pntr;
	}

	// Return prevLink pointer
	Link* getPrevLink() const 
	{
		return prevLink;
	}

private:
	Student studentObj;
	Link* nextLink = NULL;
	Link* prevLink = NULL;
};
#endif
