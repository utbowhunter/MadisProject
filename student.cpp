//
//  student.cpp
//  review
//
//  Created by Madison Perkins on 10/4/21.
//

#include "student.h"
#include <string>
#include <iostream>
using namespace std;


Student::Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysToComplete[], DegreeProgram degreeProgram)

//this is for 'D.1' in the ruberic. The following has each variable needed.
{
this->studentId = studentId;
this->firstName = firstName;
this->lastName = lastName;
this->age = age;
this->emailAddress = emailAddress;
this->daysToComplete = new int[NUMCOURSES];
    for (int i = 0; i < NUMCOURSES; i++) {
        this->daysToComplete[i] = daysToComplete[i];
}
this->degreeProgram = degreeProgram;
}
Student::Student()
{}

            //GETTER (2.a in the Ruberic)
string Student::GetstudentId() {
    return studentId;
}

string Student::GetfirstName() {
    return firstName;
}

string Student::GetlastName() {
    return lastName;
}

int Student::GetAge() {
    return age;
}

string Student::GetemailAddress() {
    return emailAddress;
}

int *Student::GetdaysToComplete() {
    return daysToComplete;
}
DegreeProgram Student::GetdegreeProgram() {
    return degreeProgram;
}

         //SETTER (2.b in the Ruberic)
void Student::SetstudentId(string studentId) {
    this->studentId = studentId;
    return;
}
void Student::SetfirstName(string firstName) {
    this->firstName = firstName;
    return;
}
void Student::SetlastName(string lastName) {
    this->lastName = lastName;
    return;
}

void Student::SetAge(int age) {
    this->age = age;
    return;
}

void Student::SetemailAddress(string emailAddress) {
    this->emailAddress = emailAddress;
    return;
}

void Student::SetdaysToComplete(int daysToComplete[]) {
    for (int i = 0; i < NUMCOURSES; i++)  {
        this->daysToComplete[i] = daysToComplete[i];
    }
}

void Student::SetDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
    return;
}

                //print (2.e in the Ruberic)
void Student::print(){
    cout << studentId  << '\t' << "First name: " << firstName << '\t' << "Last name: " << lastName << '\t';
    cout << "Email: " << emailAddress << '\t' << "Age: " << age << '\t' << "Days In Course: " ;
    
    cout << "{";
    
    for (int i = 0; i < NUMCOURSES; i++) {
        cout << daysToComplete[i];
        if (i != NUMCOURSES-1) {
            cout << ", ";
        }
    }
    cout << "}";
    cout << '\t';
    cout << "Degree Program: ";
    
    switch(degreeProgram) {
        case SECURITY :
            cout << "SECURITY";
            break;
        case NETWORK :
            cout << "NETWORK";
            break;
        case SOFTWARE :
            cout << "SOFTWARE";
            break;
        case INVALID :
            cout << "INVALID";
            break;
    }
    cout << endl;
    return;
}
