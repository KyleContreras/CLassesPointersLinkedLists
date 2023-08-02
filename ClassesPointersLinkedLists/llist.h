#ifndef llist_H
#define llist_H

#include "link.h"
#include "student.h"

class LList
{
public:

	friend class Link;
	friend class Student;

	// Start the Linked list by adding the first Link
	void startList(Link* theLink);

	// Add a link to end of linked list
	void addLink(Link* theLink);

	// Add Link to the end of the linked list
	void appendLink(Link* theLink);

	// Prints the Links on the Linked List
	void printLinkedList(string theFile);

	// Delete all students that have a certain last name
	void deleteAlphabetic(string lName);

	// Delete a student at the numeric position on the List
	void deleteNumeric(int position);

	// Add a class to a Student's classList, at a certain position on the list
	void addClass(int position, string theClass);

	// Delete a class from a Student's classList, at a certain position on the list
	void deleteClass(int position, string theClass);

	// Move fence to beginning of list
	//void moveFenceStart();

	// Move fence to end of list
	//void moveFenceEnd();

	// Moves fence one to the right 
	//void moveFenceNext();

	// Moves fence one to the left
	//void moveFencePrev();

	// Number of links to the left of the fence
	//int countLeftOfFence() const;

	// Number of Links to the right of the fence
	//int countRightOfFence() const;

	// Set fence to a particular spot on the Linked List
	//bool setFencePosition(int pos);

	// Returns the value of what the fence points at
	//bool getValue(int& it) const;

	// Prints the Links on the Linked List
	//void printLinkedList() const;

	// Deletes all Links from the Linked List
	//void deleteAllLinks();

	// Insert a link just after the current fence position
	//bool insertLink(const int);

	// Removes a Link just after the current fence position
	//bool removeLink(int&);


private:
	Link* head = NULL;		// Pointer to head of list
	Link* tail = NULL;		// Pointer to the last element in the list
	Link* fence = NULL;		// Last element on the left side
	//int leftCount;			// size of left side of the fence
	//int rightCount;			// size of the right side of the fence

	//void startList();		// Initializes list. Creates new Link and points are var pointers to it

	//void removeAllLinks();	
};
#endif
