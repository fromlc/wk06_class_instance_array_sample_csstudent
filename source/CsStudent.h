//------------------------------------------------------------------------------
// CsStudent.h : declaration file
//------------------------------------------------------------------------------
#ifndef CSSTUDENT_H
#define CSSTUDENT_H

#include "Student.h"

//------------------------------------------------------------------------------
// constants for required hours to graduate with a CS degree
//------------------------------------------------------------------------------
constexpr int CS_HOURS = 40;
constexpr int MATH_HOURS = 20;
constexpr int GEN_ED_HOURS = 60;

class CsStudent : public Student {
private:
    int mathHours;           // Hours of math taken
    int csHours;             // Hours of Computer Science taken
    int genEdHours;          // Hours of general education taken
    static int reqHours;     // All students need the same number of hours

public:

    // default constructor
    CsStudent();

    // overload constructor
    CsStudent(string n, string id, int year);

    // mutator functions
    void setCsHours(int);
    void setMathHours(int);
    void setGenEdHours(int);
    void setHours(int _csHours, int _mathHours, int _genHours);

    // accessor functions
    int getMathHours() const;
    int getCsHours() const;
    int getGenEdHours();

    // override abstract Student's pure virtual function
    int getRemainingHours() const;

    // get all types of remaining hours
    int getRemainingHours(int&, int&, int&) const;

    // access private static data from outside the class
    static int getReqHours() { return reqHours; }
};
#endif