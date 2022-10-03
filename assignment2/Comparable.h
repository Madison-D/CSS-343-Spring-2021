//---------------------------------------------------------------------------
// Header File: Comparable.h
// Class: Comparable
// Author:  Madison Dienhart
//---------------------------------------------------------------------------
// Comparable class:  Receives and outputs char.
// Compares data and is used in the binary search tree..
//---------------------------------------------------------------------------

#ifndef COMPARABLE_H
#define COMPARABLE_H

#pragma once
#include <iostream>
using namespace std;

class Comparable
{
	//----------------------------- << -------------------------------------
	// Overloaded output operator for class Comparable.
	// Preconditions: Compared char values.
	// Postconditions: Outputs char values.
	friend ostream& operator<<(ostream& out, const Comparable& comp);

	//----------------------------- >> -------------------------------------
	// Overloaded output operator for class Comparable.
	// Preconditions: Char values from a file in the driver.
	// Postconditions: Char data for comparison.
	friend istream& operator>>(istream& in, const Comparable& comp);

public:

	//------------------------------  ==  ---------------------------------------
	// Determine if two chars are equal.
	// Preconditions: Two chars that have not been compared.
	// Postconditions: Two chars are compared, returns true when equivalent.
	bool operator==(const Comparable& comp) const;

	//------------------------------  !=  ---------------------------------------
	// Determine if two chars are in equal.
	// Preconditions: Two chars that have not been compared.
	// Postconditions: Two chars are compared, returns true when not equivalent.
	bool operator!=(const Comparable& comp) const;

	//------------------------------  <  ---------------------------------------
	// Determine which char is less than other char.
	// Preconditions: Two chars for comparison.
	// Postconditions: Returns the smallest char.
	bool operator<(const Comparable& comp) const;

	//------------------------------  >  ---------------------------------------
	// Determine which char is greater than other char.
	// Preconditions: Two chars for comparison.
	// Postconditions: Returns the largest char.
	bool operator>(const Comparable& comp) const;

	//char value
	char key = ' ';

};

#endif