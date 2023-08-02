#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "link.h"
#include "llist.h"
#include "student.h"

using namespace std;

// Declare sort algorithm
void sort(vector <Student>& students);

int main(int argc, char* argv[])
{
    string unsortedInFile = argv[1];           // File with Student information
    string firstSortedOutFile = argv[2];       // Sorted Student List
    string transactionsFile = argv[3];         // File with the transactions to perform on Linked List
    string listAfterTransFile = argv[4];       // Sorted file with the list after transactions
    LList studentList;                         // A linked list of Students
    vector<Student> students;                  // Push Students in a vector to be sorted
    string token;
    string line;
    int lineCount = 0;

    // Open inStream
    ifstream inStream;
    inStream.open(unsortedInFile, ios::in);

    while (inStream.peek() != EOF)
    {
        Student studentObj;                    // Create a new Student object
        inStream >> studentObj;                // Fill studentObj with info

        students.push_back(studentObj);        // Push studentObj into the vector
        lineCount++;
    }

    /*
    for (int i = 0; i < 50; i++)
    {
        Student studentObj;                    // Create a new Student object
        inStream >> studentObj;                // Fill studentObj with info

        students.push_back(studentObj);        // Push studentObj into the vector
    }
    */

    // Close inStream
    inStream.close();

    // Sort the vector
    sort(students);

    // Push each student in the vector into a Link
    for (const Student &student : students)            // Push each student in the vector into a Link
    {
        Link* studentLink = new Link(NULL, NULL, student);     // Add the Student object to an instance of Link

        studentList.addLink(studentLink);       // Add the new Link to the Linked List
    }

    // Open outStream
    ofstream outStream;
    outStream.open(firstSortedOutFile, ios::out);

    studentList.printLinkedList(firstSortedOutFile);    // Push sorted Links to "sort01.txt"

    // Close outStream
    outStream.close();

    // Open inStream
    inStream.open(transactionsFile, ios::in);

    while (inStream.peek() != EOF)
    {
        getline(inStream, line);
        stringstream s(line);
        string word;
        int count = 1;
        string trans;
        int argNum;
        string argPhrase = " ";

        while (s >> word)
        {
            if (word == "ac" || word == "dc" || word == "da" || word == "dn")
            {
                trans = word;
            }
            else if (isdigit(word[0]))
            {
                argNum = stoi(word);
            }
            else
            {
                argPhrase = word;
            }
        }

        if (trans == "ac")
        {
            studentList.addClass(argNum, argPhrase);

        }
        else if (trans == "dc")
        {
            studentList.deleteClass(argNum, argPhrase);
        }
        else if (trans == "da")
        {
            studentList.deleteAlphabetic(argPhrase);
        }
        else if (trans == "dn")
        {
            studentList.deleteNumeric(argNum);
        }

    }

    outStream.open(listAfterTransFile, ios::out);

    studentList.printLinkedList(listAfterTransFile);    // Push sorted Links to "transout01.txt"
}

// Sort algorithm with overloaded '<' operator
void sort(vector <Student> & students) {
    int i, j;
    for (i = 1; i < students.size(); i++)
        for (j = i; (j > 0) && (students[j] < students[j - 1]); j--)
            swap(students[j], students[j - 1]);
}