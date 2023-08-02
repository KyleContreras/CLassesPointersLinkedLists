#include <iostream>
#include <fstream>

#include "llist.h"
#include "link.h"
#include "student.h"

// Begin the linked list with the first Link
void LList::startList(Link* theLink)
{
	this->head = theLink;					// Make sure all of LLists pointers point to the first Link
	this->tail = theLink;
	this->fence = theLink;
}

// Decide how we are going to add the Link
void LList::addLink(Link* theLink)
{
	if (this->head == NULL)					// If this is the beginning of the Linked List, set head and tail equal to theLink
	{
		this->startList(theLink);
	}
	else 
	{
		this->appendLink(theLink);
	}
}

void LList::appendLink(Link* theLink)
{
	this->fence->nextLink = theLink;		// Set the previous Link's nextLink pointer to point at the new Link
	this->tail = theLink;					// Point tail at theLink, so it is now pointing at the new end of the linked list
	theLink->prevLink = this->fence;		// Set the new Link's prevLink to point at the previous Link
	this->fence = theLink;					// Move fence "up" to the new Link
}

void LList::printLinkedList(string theFile)
{
	ofstream outStream;
	outStream.open(theFile, ios::out);

	this->fence = this->head;						// Make sure fence points at head of list

	while (this->fence != NULL)
	{				
		outStream << this->fence->studentObj;		// Print out Student information
		this->fence = this->fence->nextLink;		// Move fence to the next Link
	}
}

void LList::deleteAlphabetic(string lName)
{
	Link* temp1;
	Link* temp2;
	Link* temp3;
	this->fence = this->head;

	while (this->fence != NULL)
	{
		Link* temp1 = NULL;
		Link* temp2 = NULL;
		Link* temp3 = NULL;

		if (this->fence->studentObj.getLastName() == lName)
		{
			cout << "Deleted all instances of: " << this->fence->studentObj.getLastName() << endl;
			if (this->fence == this->head)
			{
				temp1 = this->head;
				this->head = this->head->getNextLink();
				this->head->setPrevLink(NULL);
				this->fence = this->head;

				delete temp1;
				temp1 = NULL;
			}
			else if (this->fence == this->tail)
			{
				this->tail = this->tail->getPrevLink();		// Set tail to prevLink, to be the new tail
				this->fence->setPrevLink(NULL);
				this->fence->setNextLink(NULL);
				temp1 = this->fence;
				this->fence = this->tail;

				this->tail->setNextLink(NULL);

				delete temp1;
				temp1 = NULL;
			}
			else
			{
				temp1 = this->fence->getPrevLink();
				temp2 = this->fence->getNextLink();

				temp1->setNextLink(this->fence->getNextLink());
				temp2->setPrevLink(this->fence->getPrevLink());

				this->fence->setNextLink(NULL);
				this->fence->setPrevLink(NULL);

				temp3 = this->fence;
				this->fence = temp1;

				temp1 = NULL;

				temp2 = NULL;

				delete temp3;
				temp3 = NULL;
			}
		}
		this->fence = this->fence->nextLink;
	}
}

void LList::deleteNumeric(int position)
{
	int counter = 0;
	this->fence = this->head;
	Link* temp1;
	Link* temp2;
	Link* temp3;

	for (int i = 0; i < position; i++)
	{
		if (this->fence->nextLink != NULL)
		{
			this->fence = this->fence->nextLink;
		}
	}

	cout << "Deleted Link at: " << position << endl;

	if (this->fence == this->tail)
	{
		this->tail = this->tail->getPrevLink();		// Set tail to prevLink, to be the new tail
		this->fence->setPrevLink(NULL);
		this->fence->setNextLink(NULL);
		temp1 = this->fence;
		this->fence = this->tail;

		this->tail->setNextLink(NULL);

		delete temp1;
		temp1 = NULL;
	}
	else
	{

		temp1 = this->fence->getPrevLink();
		temp2 = this->fence->getNextLink();

		temp1->setNextLink(this->fence->getNextLink());
		temp2->setPrevLink(this->fence->getPrevLink());

		this->fence->setNextLink(NULL);
		this->fence->setPrevLink(NULL);

		temp3 = this->fence;
		this->fence = temp1;

		//delete temp1;
		temp1 = NULL;

		//delete temp2;
		temp2 = NULL;

		delete temp3;
		temp3 = NULL;
	}
}

void LList::addClass(int position, string theClass)
{
	int counter = 0;
	this->fence = this->head;


	for (int i = 0; i < position; i++)
	{
		this->fence = this->fence->nextLink;
	}

	for (int i = 0; i < 6; i++)
	{

		if (this->fence->studentObj.classList[i] == theClass)
		{
			cout << "Error! - The class " << theClass << " is already in Link " << position << "'s classList" << endl;
			return;
		}
		else if (this->fence->studentObj.classList[i] == "")
		{
			this->fence->studentObj.classList[i] = theClass;
			
			// Just added
			//this->fence->studentObj.numClasses += 1;

			cout << "Success! - Added the class " << theClass << " to Link " << position << endl;

			return;
		}
	}

	cout << "Error! - Unable to add the class " << theClass << " to Link " << position << " . Their classList is full."  << endl;
	return;
}

void LList::deleteClass(int position, string theClass)
{
	int counter = 0;
	this->fence = this->head;

	for (int i = 0; i < position; i++)
	{
		this->fence = this->fence->nextLink;
	}

	for (int i = 0; i < 6; i++)
	{

		if (this->fence->studentObj.classList[i] == theClass)
		{
			this->fence->studentObj.classList[i] = "";

			// Just added
			//this->fence->studentObj.numClasses -= 1;

			cout << "Success! - Removed the class " << theClass << " from Link " << position << endl;

			return;
		}
	}

	cout << "Error! - The class " << theClass << " at Link " << position << " was not found in the classList." << endl;
	return;
}

