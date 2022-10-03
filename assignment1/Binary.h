//---------------------------------------------------------------------------
// Header File: BINARY.H
// Class: Binary
// Author:  Madison Dienhart
//---------------------------------------------------------------------------
// Binary class:  implements an abstract data type for binary numbers of arbitrary
// length by utilizing an array of bool values.
//
//   Includes additional features:
//   -- allows input of an integer and output of the integer converted to
//		array represented in binary form
//   -- allows for addition and subtraction of 2 binary numbers
//   -- allows for assignment of 2 binary numbers
//   -- allows for comparison (equal or not equal) of 2 binary numbers
//   -- getBit is a function in the class that returns a bool corresponding to the
//		correct bit
//   -- setBit is a function in the class that sets the bit to 1, which is true
//   -- clearBit is a function in the class that sets the bit to 0, which is false
//   -- toggleBit is a function in the class that returns false when bit is true and
//		true when bit is false
//
// Assumptions:
//   -- array elements are initialized to zero
//   -- user must enter valid integers (positive or negative) when using >>
//---------------------------------------------------------------------------

#ifndef BINARY_H
#define BINARY_H

using namespace std;
#include <iostream>
#include <array>

class Binary
{
	//----------------------------  <<  -----------------------------------------
	// Overloaded output operator for class Binary.
	// Preconditions: The num is passed into ostream to be printed out.
	// Postconditions: The num results are printed out.
	friend ostream& operator<<(ostream& out, const Binary& num);

	//-----------------------------  >>  ----------------------------------------
	// Overloaded input operator for class Binary.
	// Preconditions: User input received.
	// Postconditions: User input is now able to be processed.
	friend istream& operator>>(istream& in, Binary& num);

public:
	//-------------------------- Constructor ------------------------------------
	// Default constructor for class Binary.
	// Preconditions:   None
	// Postconditions: Sets size to 1, sets binaryArray, and sets binary to false.
	Binary();

	//-------------------------- Parameter Constructor --------------------------
	// Default constructor for class Binary with one parameter named number.
	// Preconditions:   None
	// Postconditions: creates Binary equal to the integer entered.
	Binary(int number);

	//---------------------------- Copy -----------------------------------------
	// Copy constructor for class Binary with object named num.
	// Preconditions: None
	// Postconditions: The num object is copied.
	Binary(const Binary& num);

	//---------------------------- Destructor -----------------------------------
	// Destructor for class Binary.
	// Preconditions: None
	// Postconditions:  Clears all memory allocated for Binary.
	~Binary();

	//-----------------------------  +  -----------------------------------------
	// Overloaded addition operator, adds two binary objects and provides the
	// resulting binary object.
	// Preconditions: Two Binary objects.
	// Postconditions: Adds two Binary objects together and returns result.
	Binary operator+(const Binary& num) const;

	//-----------------------------  -  -----------------------------------------
	// Overloaded subtraction operator, subtracts two binary objects and provides the
	// resulting binary object.
	// Preconditions: Two Binary objects.
	// Postconditions: Subtracts two Binary objects and returns result.
	Binary operator-(const Binary& num) const;

	//-----------------------------  =  -----------------------------------------
	// Overloaded assignment operator.
	// Preconditions: The num object prior to assignment.
	// Postconditions: The num object is assigned to values, and returns *this.
	const Binary& operator=(const Binary& num);

	//-----------------------------  +=  ----------------------------------------
	// Overloaded addition assignment operator.
	// Preconditions: Two Binary objects.
	// Postconditions: Adds two Binary objects together, assigns result and
	// returns result.
	Binary& operator+=(const Binary& num);

	//-----------------------------  -=  ----------------------------------------
	// Overloaded subtraction assignment operator.
	// Preconditions: Two Binary objects.
	// Postconditions: Subtracts two Binary objects from one another, assigns
	// result and returns result.
	Binary& operator-=(const Binary& num);

	//------------------------------  ==  ---------------------------------------
	// Determine if two binary objects are equal.
	// Preconditions: Two objects that have not been compared.
	// Postconditions: Two objects are compared, returns true when equivalent.
	bool operator==(const Binary& num) const;

	//--------------------------------  !=  -------------------------------------
	// Determine if two binary objects are not equal.
	// Preconditions: Two objects that have not been compared.
	// Postconditions: Two objects are compared, returns if *this is not equal to
	// object num.
	bool operator!=(const Binary& num) const;

	//--------------------------------  getBit  ---------------------------------
	// Searches range of Binary for specified bit and returns bit if found.
	// Preconditions: None.
	// Postconditions: Returns bitNumber of specified bit when found.
	bool getBit(int bitNumber) const;

	//------------------------  getSizeOfBinaryArray  ---------------------------
	// Determines size of Binary object.
	// Preconditions: None
	// Postconditions: Returns the size.
	int getSizeOfBinaryArray() const;

	//---------------------------------  setBit  --------------------------------
	// Sets bit named bitNumber to true.
	// Preconditions: None
	// Postconditions: Sets bitNumber to true if found in range.
	void setBit(int bitNumber);

	//--------------------------------  toggleBit  ------------------------------
	// Toggles bit from true to false, or from false to true.
	// Preconditions: None
	// Postconditions: The bitNumber is successfully toggled from true to false
	// or false to true.
	void toggleBit(int bitNumber);

	//--------------------------------  clearBit  ------------------------------
	// Sets bit named bitNumber to zero for false.
	// Preconditions: None
	// Postconditions: the bitNumber is successfully set to false.
	void clearBit(int bitNumber);

	//-------------------------------- isPositive  ------------------------------
	// Returns a positive value.
	// Preconditions: None
	// Postconditions: Returns a positive value successfully.
	bool isPositive() const;

	//------------------------------ convertToInt  ------------------------------
	// Converts the Binary to an integer with the help of convertToIntHelper.
	// Preconditions: Binary to be converted.
	// Postconditions: Binary is now the correct equivalent integer returned
	// as result.
	int convertToInt() const;

private:
	//----------------------------  Class Variables  ----------------------------
	bool *binaryArray;     // array
	bool posBinary = true; // positive
	int size;              // size of array

	//--Private Functions--------------------------------------------------------

	//---------------------------  prepareBinaryNumber  -------------------------
	// Prepares the binary, by checking the size and allocating the correct size
	// array.
	// Preconditions: The int num.
	// Postconditions: Returns the size of the future array.
	int prepareBinaryNumber(int num);

	//-------------------------  convertToBinaryNumber  -------------------------
	//Converts an integer in to an array that represents an equivalent binary
	// number.
	// Preconditions: The int num, yet to be converted to Binary.
	// Postconditions: Sets the new Binary named binaryArray.
	void convertToBinaryNumber(int num);

	//--------------------------- convertToIntHelper  ---------------------------
	// Performs necessary operations to assist in converting the Binary to an
	// integer.
	// Preconditions: Binary yet to be converted to integer.
	// Postconditions: Returns necessary value to assist in converting to integer.
	int convertToIntHelper(int num) const;
};

#endif