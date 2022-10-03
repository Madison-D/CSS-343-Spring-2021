//---------------------------------------------------------------------------
// cpp File: Comparable.cpp
// Class: Comparable
// Author:  Madison Dienhart
//---------------------------------------------------------------------------
// Comparable class:  Receives and outputs char.
// Compares data and is used in the binary search tree..
//---------------------------------------------------------------------------

#ifndef COMPARABLE_CPP
#define COMPARABLE_CPP

#include "Comparable.h"
#include <iostream>

using namespace std;

//----------------------------- << -------------------------------------
// Overloaded output operator for class Comparable.
// Preconditions: Compared char values.
// Postconditions: Outputs char values.
ostream& operator<<(ostream& out, const Comparable& comp)
{
    out << comp.key;
    return out;
}

//----------------------------- >> -------------------------------------
// Overloaded output operator for class Comparable.
// Preconditions: Char values from a file in the driver.
// Postconditions: Char data for comparison.
istream& operator>>(istream& in,Comparable& comp)
{
    comp.key = in.get();
    return in;
}

//------------------------------  ==  ---------------------------------------
// Determine if two chars are equal.
// Preconditions: Two chars that have not been compared.
// Postconditions: Two chars are compared, returns true when equivalent.
bool Comparable::operator==(const Comparable& comp) const
{
    return comp.key == key;
}

//------------------------------  !=  ---------------------------------------
// Determine if two chars are in equal.
// Preconditions: Two chars that have not been compared.
// Postconditions: Two chars are compared, returns true when not equivalent.
bool Comparable::operator!=(const Comparable& comp) const
{
    return comp.key != key;
}

//------------------------------  <  ---------------------------------------
// Determine which char is less than other char.
// Preconditions: Two chars for comparison.
// Postconditions: Returns the smallest char.
bool Comparable::operator<(const Comparable& comp) const
{
    return comp.key < key;
}

//------------------------------  >  ---------------------------------------
// Determine which char is greater than other char.
// Preconditions: Two chars for comparison.
// Postconditions: Returns the largest char.
bool Comparable::operator>(const Comparable& comp) const
{
    return comp.key > key;
}
#endif