//---------------------------------------------------------------------------
// cpp File: Comparable.cpp
// Class: Comparable
// Author:  Madison Dienhart
//---------------------------------------------------------------------------
// Comparable class:  Receives and outputs values for comparison, interacts
// with the SearchTree class. Compares data and is used in the binary
// search tree.
//
//Includes features such as:
//   -- == and != for comparison.
//   -- > and < for comparison.
//   -- >> for input and << for output.
//   -- String and int values.
//---------------------------------------------------------------------------

#ifndef COMPARABLE_CPP
#define COMPARABLE_CPP

#include "Comparable.h"
#include <iostream>

using namespace std;

//----------------------------- << -------------------------------------
// Overloaded output operator for class Comparable.
// Preconditions: Compared value.
// Postconditions: Outputs values.
ostream& operator<<(ostream& out, const Comparable& comp)
{
    out << comp.key;
    return out;
}

//----------------------------- >> -------------------------------------
// Overloaded input operator for class Comparable.
// Preconditions: The values from a file in the initializing class.
// Postconditions: The data is ready for comparison.
istream& operator>>(istream& in, Comparable& comp)
{
    comp.key = in.get();
    return in;
}

//------------------------------  ==  ---------------------------------------
// Determine if two values are equal.
// Preconditions: Two values that have not been compared.
// Postconditions: Two values are compared, returns true when equivalent.
bool Comparable::operator==(const Comparable& comp) const
{
    return comp.key == key;
}

//------------------------------  !=  ---------------------------------------
// Determine if two values are in equal.
// Preconditions: Two values that have not been compared.
// Postconditions: Two values are compared, returns true when not equivalent.
bool Comparable::operator!=(const Comparable& comp) const
{
    return comp.key != key;
}

//------------------------------  <  ---------------------------------------
// Determine which value is less than other value.
// Preconditions: Two values for comparison.
// Postconditions: Returns the smallest value.
bool Comparable::operator<(const Comparable& comp) const
{
    return comp.key < key;
}

//------------------------------  >  ---------------------------------------
// Determine which value is greater than other value.
// Preconditions: Two values for comparison.
// Postconditions: Returns the largest value.
bool Comparable::operator>(const Comparable& comp) const
{
    return comp.key > key;
}
#endif