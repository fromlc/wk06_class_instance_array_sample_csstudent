//------------------------------------------------------------------------------
// CsStudent.cpp : definition file
//------------------------------------------------------------------------------
#include "CsStudent.h"

//------------------------------------------------------------------------------
// default constructor inherits Student default constructor
//------------------------------------------------------------------------------
CsStudent::CsStudent() : CsStudent("csstudent", "", 0) { }

//------------------------------------------------------------------------------
// overload constructor inherits Student overload constructor
//------------------------------------------------------------------------------
CsStudent::CsStudent(string _name, string _id, int _year)
    : Student(_name, _id, _year) {

    mathHours = 0;
    csHours = 0;
    genEdHours = 0;
}

//------------------------------------------------------------------------------
// mutators
//------------------------------------------------------------------------------
void CsStudent::setCsHours(int csh) { csHours = csh; }

//------------------------------------------------------------------------------
void CsStudent::setMathHours(int mh) { mathHours = mh; }

//------------------------------------------------------------------------------
void CsStudent::setGenEdHours(int geh) { genEdHours = geh; }

//------------------------------------------------------------------------------
void CsStudent::setHours(int _csHours, int _mathHours, int _genEdHours) {
    csHours = _csHours;
    mathHours = _mathHours;
    genEdHours = _genEdHours;
}

//------------------------------------------------------------------------------
// accessors
//------------------------------------------------------------------------------
int CsStudent::getMathHours() const { return mathHours; }

//------------------------------------------------------------------------------
int CsStudent::getCsHours() const { return csHours; }

//------------------------------------------------------------------------------
int CsStudent::getGenEdHours() { return genEdHours; }

//------------------------------------------------------------------------------
// - returns number of hours needed to graduate
//------------------------------------------------------------------------------
int CsStudent::getRemainingHours() const {

    // return total hours needed
    return reqHours - (mathHours + csHours + genEdHours);
}

//------------------------------------------------------------------------------
// - returns number of hours needed to graduate
// - returns number of hours in each category
//------------------------------------------------------------------------------
int CsStudent::getRemainingHours(int& needCs, int& needMath, int& needGe) const {

    // return specific area hours in reference parameters
    needCs = CS_HOURS - csHours;
    needMath = MATH_HOURS - mathHours;
    needGe = GEN_ED_HOURS - genEdHours;

    // return total hours needed
    return reqHours - (mathHours + csHours + genEdHours);
}

//------------------------------------------------------------------------------
// static function returns number of hours 
// all CS students need to graduate
//------------------------------------------------------------------------------
int CsStudent::getReqHours() { return CsStudent::reqHours; }
