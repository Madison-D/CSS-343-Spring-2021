//---------------------------------------------------------------------------
// Vertex.cpp
// Member function definitions for class Vertex
// Author:  Madison Dienhart
//---------------------------------------------------------------------------
// Vertex class: Receives and outputs char.
// Compares data and is used in the Graph class.
//---------------------------------------------------------------------------

#include "Vertex.h"
#include <iostream>

using namespace std;


//------------------------------  ==  ---------------------------------------
// Determine if two vertices are equal.
// Preconditions: Two vertex that have not been compared.
// Postconditions: Two vertex are compared, returns true when equivalent.
bool Vertex::operator==(const Vertex& room) const {
	return roomName == room.roomName;
}


//--------------------------------  !=  -------------------------------------
// Determine if two vertices are not equal.
// Preconditions: Two vertex that have not been compared.
// Postconditions: Two vertex are compared, returns true when not equivalent.
bool Vertex::operator!=(const Vertex& room) const {
	return roomName != room.roomName;
}


//------------------------------  <  ----------------------------------------
// Determine if two vertices are equal.
// Preconditions: Two vertex for comparison.
// Postconditions: Returns the smallest vertex.
bool Vertex::operator<(const Vertex& room) const {
	return roomName < room.roomName;
}


//--------------------------------  >  --------------------------------------
// Determine if two vertices are not equal.
// Preconditions: Two vertex for comparison.
// Postconditions: Returns the largest vertex.
bool Vertex::operator>(const Vertex& room) const  {
	return roomName > room.roomName;
}

//-----------------------------  >>  ----------------------------------------
// Overloaded input operator for class Vertex
// Preconditions: Char values from a file.
// Postconditions: Char data for comparison.
istream& operator>>(istream& in, Vertex& room) {
	in.getline(room.roomName, 50);
	return in;
}

//----------------------------  <<  -----------------------------------------
// Overloaded output operator for class Vertex
// Preconditions: Char values.
// Postconditions: Outputs char values.
ostream& operator<<(ostream& out, const Vertex& room) {
	out << room.roomName;
	return out;
}

