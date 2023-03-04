//------------------------------------------------------------------------------
// Pr15-19.cpp
// 
// demos the CsStudent class, which is derived from abstract base class Student
// 
// Author: Tony Gaddis, from Gaddis 9e pp. 945-946
// Modified by: Prof. Linda C
//------------------------------------------------------------------------------
#include "CsStudent.h"
#include "ansi_colors.h"

#include <iostream>
#include <vector>

//------------------------------------------------------------------------------
// using symbols
//------------------------------------------------------------------------------
using std::cout;
using std::vector;

//------------------------------------------------------------------------------
// allocate memory space for static member and initialize it
//------------------------------------------------------------------------------
int CsStudent::reqHours { MATH_HOURS + CS_HOURS + GEN_ED_HOURS };

//------------------------------------------------------------------------------
// globals
//------------------------------------------------------------------------------
namespace g {
    vector<CsStudent> vCsStudents;
    CsStudent aCsGrads[5];
}

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
void initApp();
void fillVector();
void displayHoursNeeded(int&);
void displayGrads(int);


//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

    // test default constructor
    //CsStudent anonymouse;

    initApp();

    // #TODO uses dummy student data
    fillVector();

    // reference parameter (why do we need this?)
    int gradCount;
    displayHoursNeeded(gradCount);

    // pass number of grad array elements
    displayGrads(gradCount);

    return 0;
}

//------------------------------------------------------------------------------
// app banner and info
//------------------------------------------------------------------------------
void initApp() {
    cout << FG_CYAN << "\nCS Students at HiTech U\n";
    cout << FG_YELLOW;
    cout << "\nHours needed to graduate with a CS degree: "
        << CsStudent::reqHours << '\n';
    cout << "\tCS hours: " << CS_HOURS << '\n';
    cout << "\tMath hours: " << MATH_HOURS << '\n';
    cout << "\tGen Ed hours: " << GEN_ED_HOURS << "\n\n";
    cout << RESET;
}

//------------------------------------------------------------------------------
// fill global vector with dummy data
//------------------------------------------------------------------------------
void fillVector() {
    // create a CsStudent object for each student, set hours taken
    g::vCsStudents.push_back(CsStudent("Boo Radley", "167R98337", 2021));
    g::vCsStudents.back().setCsHours(20);
    g::vCsStudents.back().setMathHours(20);
    g::vCsStudents.back().setGenEdHours(40);

    g::vCsStudents.push_back(CsStudent("Susie Qubit", "167Q44222", 2020));
    g::vCsStudents.back().setCsHours(16);
    g::vCsStudents.back().setMathHours(20);
    g::vCsStudents.back().setGenEdHours(52);

    g::vCsStudents.push_back(CsStudent("Guitar Hero", "167H53100", 2019));
    g::vCsStudents.back().setCsHours(CS_HOURS);
    g::vCsStudents.back().setMathHours(MATH_HOURS);
    g::vCsStudents.back().setGenEdHours(GEN_ED_HOURS);

    // how could you make less function calls and get the same info?
}

//------------------------------------------------------------------------------
// - display how many hours each student needs to graduate
// - return number of students added to aCsGrads[] array in reference parameter
//------------------------------------------------------------------------------
void displayHoursNeeded(int& gradIndex) {
    gradIndex = 0;

    for (CsStudent& stu : g::vCsStudents) {

        // reference parameters
        int cs, math, ge;
        // get all hours needed to graduate
        int needsHours = stu.getRemainingHours(cs, math, ge);

        // display how many hours this student needs to graduate
        cout << "CS student " << FG_CYAN << stu.getName() << RESET
            << " was admitted in " << stu.getYearAdmitted() << '\n';

        cout << "\tCS hours taken/still needed: " 
            << stu.getCsHours() << " / " << cs << '\n';
        cout << "\tMath hours taken/still needed: "
            << stu.getMathHours() << " / " << math << '\n';
        cout << "\tGen Ed hours taken/still needed: "
            << stu.getGenEdHours() << " / " << ge << '\n';

        cout << FG_CYAN
            << "\tTotal hours needed to graduate: " << needsHours << "\n\n"
            << RESET;

        // if all requirements fulfilled, add student to grads array
        if (needsHours <= 0) {
            g::aCsGrads[gradIndex++] = stu;
        }
    }
}

//------------------------------------------------------------------------------
// display list of new CS graduates
//------------------------------------------------------------------------------
void displayGrads(int gradCount) {

    cout << FG_YELLOW;
    for (int i = 0; i < gradCount; ++i) {
        cout << '\n' << g::aCsGrads[i].getName() << " gets to graduate!\n";
    }
    cout << RESET << '\n';
}