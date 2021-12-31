//
//  Roster.cpp
//  review
//
//  Created by Madison Perkins on 10/4/21.
//
#ifndef roster_cpp
//#define roster_cpp
#include "Roster.h"
#include "student.h"
#include "degree.h"

#include <iostream>
#include <sstream>

using std::cout;
using std::endl;



int currentRosterSize = 0; 
int rosterCapacity = 0;


// ***** Constructor to create the max capacity of the roster
Roster::Roster (int maxCapacity)
 {    
    rosterCapacity = maxCapacity;      
}

// ***** Default destructor
Roster::~Roster() {
}

// ***** Split the incoming string into individual array elements
string* Roster::splitStudentStringIntoArray(string inputString)
{
    string line = inputString;
    static string arr[9];
    
    int i = 0;
    stringstream ssin(line);
    while (ssin.good()){
        string subStr; 
        getline(ssin, subStr, ',');
        arr[i] = subStr;
        ++i;
    }
    for(i = 0; i < 9; i++){
        cout << arr[i] << endl;
    }

    return arr;

}

//E.a this part is to set the instance variables from D1 (in the ruberic). Also to update the roster.
void Roster::add(int index, string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    //the int here shows the student how many days left they have to complete their course
    int daysToComplete[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
        
    Student *student = new Student(studentId, firstName, lastName, emailAddress, age, daysToComplete, degreeProgram);

    classRosterArray[index] = student;
    
}

//         //E.b in the Roster is to remove students by student ID. (If they don't exist it will print an error)
void Roster::remove(string studentId){
    bool idFound = false;
    for (int i = 0; (i < currentRosterSize) && !idFound; ++i) {
        if(classRosterArray[i]->GetstudentId() == studentId) {
            classRosterArray[i] = classRosterArray[currentRosterSize - 1];
            --rosterSize;
            idFound = true;
        }
    }
    if (idFound){
        cout << "Student ID " << studentId << " found and removed." << endl;
    }
    else {
        cout << "Error: No studen with this ID has been found." << endl;
    }
}
//         //E.c in the ruberic. THis part is to print a complete tab-separated list of student data.
void Roster::printAll(){
    for (int i = 0; i < currentRosterSize; ++i) {
        classRosterArray[i]->print();
    }
}
//         //E.d in the ruberic. This part prints out the average number of days the student has in three courses
void Roster::printAverageDaysInCourse(string studentId){
    for (int i = 0; i < currentRosterSize; ++i) {
        if (classRosterArray[i]->GetstudentId() == studentId) {
            cout << "Student ID " << classRosterArray[i]->GetstudentId() << ": ";
            int *days = classRosterArray[i]->GetdaysToComplete();
            cout << "Average number of days in courses: " << (days[0] + days[1] + days[2]) / 3 << endl;
            return;
        }
    }
}
//         //E.e in the Ruberic this part verifies student email addresses and will display invalid emails.
void Roster::printInvalidEmails() {
    for (int i = 0; i < currentRosterSize; ++i) {
        string emailAddress = classRosterArray[i]->GetemailAddress();
        size_t arroba = emailAddress.find('@');
        size_t period = emailAddress.find('.', arroba);
        if (arroba == string::npos) {
            cout << "Invalid email. Missing an @ symbol:" << emailAddress << endl;
        }
        else if (period == string::npos) {
            cout << "Invalid email. Missing a '.' : " << emailAddress << endl;
        }
        else if (emailAddress.find(' ') != string::npos) {
            cout << "Invalid email. Spaces are not allowed in emails: " << emailAddress << endl;
        }
    }
}
//     //E.f in the Ruberic this part is to print out student info for their specified degree program (specific to a set enumerated type)
void Roster::printByDegreeProgram(DegreeProgram degreeProgram){
    for (int i = 0; i < currentRosterSize; ++i) {
        
        //This if statement will double check thier degree program to make sure it matches.
        if (classRosterArray[i]->GetdegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}

// ***** Input a string of the degree and return the ENUM value
DegreeProgram getEnumfromString(string degreeProgram)
{
    if (degreeProgram == "SOFTWARE")
    {  return DegreeProgram::SOFTWARE;  }
    else if(degreeProgram == "SECURITY")
    {  return DegreeProgram::SECURITY;  }
    else if(degreeProgram == "NETWORK")
    {  return DegreeProgram::NETWORK;  }
    else
    {  return DegreeProgram::INVALID;  }        

}
// ***** Load the Data from the input array
void Roster::loadData(const string inStudentData[], int CurrentDataSize)
{

    for(int i = 0; i < CurrentDataSize; i++)
    {
        cout << inStudentData[i]  << endl;

        const string studentString = inStudentData[i];

        // ***** Split the string array element into indiviual array element, and return the array of strings to create the fields
        string *_studentArray = splitStudentStringIntoArray(studentString);
      
        // ***** Set each array field to a string for passing to the ADD function, include the index number
        string _studentId1 = _studentArray[0];
        string _firstName = *(_studentArray+1);
        string _lastName = *(_studentArray+2);
        string _emailAddress = *(_studentArray+3);
        string _age = *(_studentArray+4);
        string _daysToComplete1 = *(_studentArray+5);
        string _daysToComplete2 = *(_studentArray+6);
        string _daysToComplete3 = *(_studentArray+7);
        DegreeProgram _degreeProgram = getEnumfromString(*(_studentArray+8));

        // ***** Add student to the array
        add(i, _studentId1, _firstName, _lastName, _emailAddress, stoi(_age), stoi(_daysToComplete1),stoi(_daysToComplete2), stoi(_daysToComplete3), _degreeProgram);
 
        // ***** Increment the current class roster count
        currentRosterSize++;
    }

}

#endif
