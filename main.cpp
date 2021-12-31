//
//  main.cpp
//  review
//
//  Created by Madison Perkins on 10/4/21.
//
#ifndef main_cpp
#define main_cpp
//#include "student.h"
#include "Roster.h"
//#include "degree.h"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main () {       //F.1 in the Ruberic. This part is to print out to the screen my information I used to create this project.
    cout << "Scripting and Programming - Applications – C867" << endl;
    cout << "Using c++" << endl;
    cout << "WGU ID: 001070659" << endl;
    cout << "Madison Perkins" << endl;
            //F.3 in the ruberic. This part is to add each student to the roster.
        const string studentData[] = {
        "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Madison,Perkins,mperk75@wgu.edu,45,45,30,30,SOFTWARE"       //This is the answer for  A in the ruberic.
    };

        // ***** Set the roster size maximum
        int _rosterCapacity = 20;

        // ***** Get the current ize of the string Array
        int _currentRosterSize = sizeof(studentData)/sizeof(studentData[0]); 

        // ***** Instanciate the Roster Object, with the Roster max size
        Roster classRoster(_rosterCapacity);

        // ***** Load the current data into the roster 
        classRoster.loadData(studentData, _currentRosterSize);

        
    //     //F.4 in the ruberic
    cout << "Printing roster of all the students enrolled:" << endl;
    classRoster.printAll();
    cout << endl;


        cout << "The following emails are invalid:" << endl;
    classRoster.printInvalidEmails();
    cout << endl;

    cout << "Average days spent in courses: " << endl;

    classRoster.printAverageDaysInCourse("A1");
    classRoster.printAverageDaysInCourse("A2");
    classRoster.printAverageDaysInCourse("A3");
    classRoster.printAverageDaysInCourse("A4");
    classRoster.printAverageDaysInCourse("A5");
    cout << endl;

    //         //F.4 in the ruberic.
    cout << "Displaying roster by SOFTWARE program:" << endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl << endl;

    classRoster.remove("A3");
    
    classRoster.printAll();
    
    classRoster.remove("A3");
    cout << endl;
}

#endif
