//------------------------------------------------------------------------------
// Student.h : abstract class declaration and definition
//------------------------------------------------------------------------------
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using std::string;

//------------------------------------------------------------------------------
// Student : abstract class
//------------------------------------------------------------------------------
class Student {
protected:
    string name;			// Student name
    string idNumber;		// Student ID
    int yearAdmitted;	    // Year student was admitted

public:
    // default constructor
    Student() 
        : Student("student", "", 0) { }

    // overload constructor
    Student(string _name, string _id, int _year)
        : name(_name), idNumber(_id), yearAdmitted(_year) {
    }

    // accessor functions
    const string getName() const { return name; }

    const string getIdNum() const { return idNumber; }

    // force static binding to derived class version
    virtual int getYearAdmitted() const { return yearAdmitted; }

    // pure virtual function, derived classes must override
    virtual int getRemainingHours() const = 0;
};
#endif 