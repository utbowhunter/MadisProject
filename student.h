//
//  student.h
//  review
//
//  Created by Madison Perkins on 10/5/21.
//

#ifndef student_h
#define student_h
#include "degree.h"
#include <string>
#include <iostream>

using namespace std;

#define NUMCOURSES 3
// what's listed below is what each student has filled out in the roster.
class Student {
private:
    string studentId;
    string firstName;
    string lastName;
    int age;
    string emailAddress;
    int *daysToComplete;
    DegreeProgram degreeProgram;

public:
    Student(string StudentId, string firstName, string lastName, string emailAddress, int age, int daysToComplete[], DegreeProgram degreeProgram);
    Student();

    string GetstudentId();
    string GetfirstName();
    string GetlastName();
    string GetemailAddress();
    int GetAge();
    int *GetdaysToComplete();
    DegreeProgram GetdegreeProgram();

    void SetstudentId(string studentId);
    void SetfirstName(string firstName);
    void SetlastName(string lastName);
    void SetAge(int age);
    void SetemailAddress(string emailAddress);
    void SetdaysToComplete(int daysToComplete[]);
    void SetDegreeProgram(DegreeProgram degreeProgram);
    void print();
};


#endif /* student_h */


