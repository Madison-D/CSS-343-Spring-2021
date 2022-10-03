//---------------------------------------------------------------------------
// Header File: Comparable.h
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

#ifndef COMPARABLE_H
#define COMPARABLE_H

#pragma once
#include <iostream>
using namespace std;

class Comparable
{
	//----------------------------- << -------------------------------------
	// Overloaded output operator for class Comparable.
	// Preconditions: Compared value.
	// Postconditions: Outputs values.
	friend ostream& operator<<(ostream& out, const Comparable& comp);

	//----------------------------- >> -------------------------------------
	// Overloaded input operator for class Comparable.
	// Preconditions: The values from a file in the initializing class.
	// Postconditions: The data is ready for comparison.
	friend istream& operator>>(istream& in, Comparable& comp);

public:

	//------------------------------  ==  ---------------------------------------
	// Determine if two values are equal.
	// Preconditions: Two values that have not been compared.
	// Postconditions: Two values are compared, returns true when equivalent.
	bool operator==(const Comparable& comp) const;

	//------------------------------  !=  ---------------------------------------
	// Determine if two values are in equal.
	// Preconditions: Two values that have not been compared.
	// Postconditions: Two values are compared, returns true when not equivalent.
	bool operator!=(const Comparable& comp) const;

	//------------------------------  <  ---------------------------------------
	// Determine which value is less than other value.
	// Preconditions: Two values for comparison.
	// Postconditions: Returns the smallest value.
	bool operator<(const Comparable& comp) const;

	//------------------------------  >  ---------------------------------------
	// Determine which value is greater than other value.
	// Preconditions: Two values for comparison.
	// Postconditions: Returns the largest value.
	bool operator>(const Comparable& comp) const;

private:
//Class Variables

	//char value
	char key;

	//int value
	int key;

	//string value
	string key;
};

#endif