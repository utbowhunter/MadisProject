//
//  Roster.h
//  review
//
//  Created by Madison Perkins on 10/4/21.
//

#ifndef Roster_h
#define Roster_h
#include "student.h"
#include "degree.h"

#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using std::cout;
using std::endl;
using namespace std;

class Roster    {

private:
        int rosterSize;
        int rosterCapacity;

        // ***** Create a Array of poitners to the Array
        Student *classRosterArray[5]; 
      

public:
    Roster(int maxCapacity);

    ~Roster();
    void Parse(string data);
    
    void loadData(const string inStudentData[], int CurrentDataSize);

    string * splitStudentStringIntoArray(string inputString);

    //The following is important to define the functions that are used.
    void add(int Index, string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(string studentId);
    void printAll();
    void printAverageDaysInCourse(string studentId);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
        
};
#endif /* Roster_h */
