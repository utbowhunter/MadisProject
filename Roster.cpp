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

classRosterArray = new Student[rosterCapacity]; 

Roster::Roster (int maxCapacity)
 {    
    rosterCapacity = maxCapacity;      
}


DegreeProgram getEnumfromString(string degreeProgram)
{
    if (degreeProgram == "SOFTWARE")
    {  return DegreeProgram::SOFTWARE;  }
    else if(degreeProgram == "SECURITY")
    {  return DegreeProgram::SECURITY;  }
    else if(degreeProgram == "SECURITY")
    {  return DegreeProgram::SECURITY;  }
    else
    {  return DegreeProgram::INVALID;  }        

}
// ***** Split the incoming string into individual array elements
string * Roster::splitStudentStringIntoArray(string inputString)
{
    string line = inputString;
    string arr[8];
    
    int i = 0;
    stringstream ssin(line);
    while (ssin.good() && i < 4){
        ssin >> arr[i];
        ++i;
    }
    for(i = 0; i < 4; i++){
        cout << arr[i] << endl;
    }

    return arr;

}

//E.a this part is to set the instance variables from D1 (in the ruberic). Also to update the roster.
void Roster::add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    //the int here shows the student how many days left they have to complete their course
    int daysToComplete[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    
    classRosterArray[currentRosterSize] = Student(studentId, firstName, lastName, emailAddress, age, daysToComplete, degreeProgram);

    currentRosterSize++;
}


void Roster::loadData(const string inStudentData[], int CurrentDataSize)
{
    for(int i = 0; i < CurrentDataSize - 1; i++)
    {
        cout << inStudentData[i]  << endl;

        const string studentString = inStudentData[i];

        string * _studentArray = splitStudentStringIntoArray(studentString);

        string _studentId = _studentArray[0];
        string _firstName = _studentArray[1];
        string _lastName = _studentArray[2];
        string _emailAddress = _studentArray[3];
        string _age = _studentArray[4];
        string _daysToComplete1 = _studentArray[5];
        string _daysToComplete2 = _studentArray[6];
        string _daysToComplete3 = _studentArray[7];
        DegreeProgram _degreeProgram = getEnumfromString(_studentArray[6]);

        // ***** Add student to the array
        add(_studentId, _firstName, _lastName, _emailAddress, stoi(_age), stoi(_daysToComplete1),stoi(_daysToComplete2), stoi(_daysToComplete3), _degreeProgram);
         //add_(_studentId, firstName, lastName, emailAddress, _age, _daysToComplete1, _daysToComplete2, _daysToComplete3, _degreeProgram)
        //Student _student = new Student(inStudentData[i]);
        // classRosterArray[i] =  inStudentData[i];
        //currentRosterSize++;
    }

}

//         //E.b in the Roster is to remove students by student ID. (If they don't exist it will print an error)
// void Roster::remove(string studentId){
//     bool idFound = false;
//     for (int i = 0; (i < rosterSize) && !idFound; ++i) {
//         if(classRosterArray[i]->GetstudentId() == studentId) {
//             classRosterArray[i] = classRosterArray[rosterSize - 1];
//             --rosterSize;
//             idFound = true;
//         }
//     }
//     if (idFound){
//         cout << "Student ID " << studentId << " found and removed." << endl;
//     }
//     else {
//         cout << "Error: No studen with this ID has been found." << endl;
//     }
// }
//         //E.c in the ruberic. THis part is to print a complete tab-separated list of student data.
// void Roster::printAll(){
//     for (int i = 0; i < rosterSize; ++i) {
//         classRosterArray[i]->print();
//     }
// }
//         //E.d in the ruberic. This part prints out the average number of days the student has in three courses
// void Roster::printAverageDaysInCourse(string studentId){
//     for (int i = 0; i < rosterSize; ++i) {
//         if (classRosterArray[i]->GetstudentId() == studentId) {
//             cout << "Student ID " << classRosterArray[i]->GetstudentId() << ": ";
//             int *days = classRosterArray[i]->GetdaysToComplete();
//             cout << "Average number of days in courses: " << (days[0] + days[1] + days[2]) / 3 << endl;
//             return;
//         }
//     }
// }
//         //E.e in the Ruberic this part verifies student email addresses and will display invalid emails.
// void Roster::printInvalidEmails() {
//     for (int i = 0; i < rosterSize; ++i) {
//         string emailAddress = classRosterArray[i]->GetemailAddress();
//         u_long arroba = emailAddress.find('@');
//         u_long period = emailAddress.find('.', arroba);
//         if (arroba == string::npos) {
//             cout << "Invalid email. Missing an @ symbol:" << emailAddress << endl;
//         }
//         else if (period == string::npos) {
//             cout << "Invalid email. Missing a '.' : " << emailAddress << endl;
//         }
//         else if (emailAddress.find(' ') != string::npos) {
//             cout << "Invalid email. Spaces are not allowed in emails: " << emailAddress << endl;
//         }
//     }
// }
//     //E.f in the Ruberic this part is to print out student info for their specified degree program (specific to a set enumerated type)
// void Roster::printByDegreeProgram(DegreeProgram degreeProgram){
//     for (int i = 0; i < rosterSize; ++i) {
        
//         //This if statement will double check thier degree program to make sure it matches.
//         if (classRosterArray[i]->GetdegreeProgram() == degreeProgram) {
//             classRosterArray[i]->print();
//         }
//     }
//}
#endif
