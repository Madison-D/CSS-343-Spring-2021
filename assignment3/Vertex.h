//---------------------------------------------------------------------------
// Header File: Vertex.H
// Class: Vertex
// Authors: Madison Dienhart
//---------------------------------------------------------------------------
// Vertex class: Receives and outputs char.
// Compares data and is used in the Graph class.
//---------------------------------------------------------------------------

#ifndef Vertex_H
#define Vertex_H

#include <iostream>
using namespace std;

class Vertex {
	//----------------------------  <<  -----------------------------------------
	// Overloaded output operator for class Vertex
	// Preconditions: Char values.
	// Postconditions: Outputs char values.
	friend ostream& operator<<(ostream& out, const Vertex& room);

	//-----------------------------  >>  ----------------------------------------
	// Overloaded input operator for class Vertex
	// Preconditions: Char values from a file.
	// Postconditions: Char data for comparison.
	friend istream& operator>>(istream& in, Vertex& room);

public:

	//------------------------------  ==  ---------------------------------------
	// Determine if two vertices are equal.
	// Preconditions: Two vertex that have not been compared.
	// Postconditions: Two vertex are compared, returns true when equivalent.
	bool operator==(const Vertex& room) const;

	//--------------------------------  !=  -------------------------------------
	// Determine if two vertices are not equal.
	// Preconditions: Two vertex that have not been compared.
	// Postconditions: Two vertex are compared, returns true when not equivalent.
	bool operator!=(const Vertex& room) const;

	//------------------------------  <  ----------------------------------------
	// Determine if two vertices are equal.
	// Preconditions: Two vertex for comparison.
	// Postconditions: Returns the smallest vertex.
	bool operator<(const Vertex& room) const;

	//--------------------------------  >  --------------------------------------
	// Determine if two vertices are not equal.
	// Preconditions: Two vertex for comparison.
	// Postconditions: Returns the largest vertex.
	bool operator>(const Vertex& room) const;

private:

	//Class Variable for room names.
	char roomName[50];
};

#endif

