//---------------------------------------------------------------------------
// Binary.cpp
// Member function definitions for class Binary
// Author:  Madison Dienhart
//---------------------------------------------------------------------------
// Binary class:  implements an abstract data type for binary numbers of arbitrary
// length by utilizing an array of bool values.
//
//   includes additional features:
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
#include "Binary.h"
#include <iostream>
using namespace std;

//-------------------------- Constructor ------------------------------------
// Default constructor for class Binary.
// Preconditions:   None
// Postconditions: Sets size to 1, sets binaryArray, and sets binary to false.
Binary::Binary() {

	size = 1;
	binaryArray = new bool[size];
	binaryArray[0] = false;
}

//-------------------------- Parameter Constructor --------------------------
// Default constructor for class Binary with one parameter named number.
// Preconditions:   None
// Postconditions:	Creates Binary equal to the integer entered.
Binary::Binary(int number)
{
	if (number < 0) {
		number = abs(number);
		posBinary = false;
	}

	convertToBinaryNumber(number);
}

//---------------------------- Copy -----------------------------------------
// Copy constructor for class Binary with object named num.
// Preconditions: None
// Postconditions: The num object is copied.
Binary::Binary(const Binary& num) {

	size = num.size;
	binaryArray = new bool[size];
	posBinary = num.isPositive();

	for (int i = 0; i < size; i++)
		binaryArray[i] = num.getBit(i);
}

//---------------------------- Destructor -----------------------------------
// Destructor for class Binary.
// Preconditions: None
// Postconditions:  Clears all memory allocated for Binary.
Binary::~Binary() {
	size = 0;
	delete[] binaryArray;
}

//-----------------------------  +  -----------------------------------------
// Overloaded addition operator, adds two binary objects and provides the
// resulting binary object.
// Preconditions: Two Binary objects.
// Postconditions: Adds two Binary objects together and returns result.
Binary Binary::operator+(const Binary& num) const
{
	int addedArrays = convertToInt() + num.convertToInt();

	return(Binary(addedArrays));
}

//-----------------------------  -  -----------------------------------------
// Overloaded subtraction operator, subtracts two binary objects and provides the
// resulting binary object.
// Preconditions: Two Binary objects.
// Postconditions: Subtracts two Binary objects and returns result.
Binary Binary::operator-(const Binary& num) const
{
	int subtractedArrays = convertToInt() - num.convertToInt();

	return(Binary(subtractedArrays));
}

//-----------------------------  =  -----------------------------------------
// Overloaded assignment operator.
// Preconditions: The num object prior to assignment.
// Postconditions: The num object is assigned to values, and returns *this.
const Binary& Binary::operator=(const Binary& num)
{
	if (&num != this) {

		delete[] binaryArray;
		size = num.getSizeOfBinaryArray();
		posBinary = num.isPositive();
		binaryArray = new bool[size];

		for (int i = 0; i < size; i++)
			binaryArray[i] = num.getBit(i);
	}

	return *this;
}

//-----------------------------  +=  ----------------------------------------
// Overloaded addition assignment operator.
// Preconditions: Two Binary objects.
// Postconditions: Adds two Binary objects together, assigns result and returns
// result.
Binary& Binary::operator+=(const Binary& num)
{
	*this = *this + num;

	return *this;
}

//-----------------------------  -=  ----------------------------------------
// Overloaded subtraction assignment operator.
// Preconditions: Two Binary objects.
// Postconditions: Subtracts two Binary objects from one another, assigns
// result and returns result.
Binary& Binary::operator-=(const Binary& num)
{
	*this = *this - num;

	return *this;
}

//------------------------------  ==  ---------------------------------------
// Determine if two binary objects are equal.
// Preconditions: Two objects that have not been compared.
// Postconditions: Two objects are compared, returns true when equivalent.
bool Binary::operator==(const Binary& num) const
{
	if (size != num.size)
		return false;

	for (int i = 0; i < size; i++)
		if (binaryArray[i] != num.getBit(i))
			return false;

	return true;
}

//--------------------------------  !=  -------------------------------------
// Determine if two binary objects are not equal.
// Preconditions: Two objects that have not been compared.
// Postconditions: Two objects are compared, returns if *this is not equal to
// object num.
bool Binary::operator!=(const Binary& num) const
{
	return !(*this == num);
}

//--------------------------------  getBit  ---------------------------------
// Searches range of Binary for specified bit and returns bit if found.
// Preconditions: None.
// Postconditions: Returns bitNumber of specified bit when found.
bool Binary::getBit(int bitNumber) const
{
	if (bitNumber >= size || bitNumber < 0)
		return false;

	return binaryArray[bitNumber];
}

//--------------------------------  toggleBit  ------------------------------
// Toggles bit from true to false, or from false to true.
// Preconditions: None
// Postconditions: The bitNumber is successfully toggled from true to false
// or false to true.
void Binary::toggleBit(int bitNumber)
{
	if (bitNumber >= 0 && bitNumber < size)
		binaryArray[bitNumber] != binaryArray[bitNumber];
}

//---------------------------------  setBit  --------------------------------
// Sets bit named bitNumber to true.
// Preconditions: None
// Postconditions: Sets bitNumber to true if found in range.
void Binary::setBit(int bitNumber)
{
	if (bitNumber >= 0 && bitNumber < size)
		binaryArray[bitNumber] = true;
}

//--------------------------------  clearBit  ------------------------------
// Sets bit named bitNumber to zero for false.
// Preconditions: None
// Postconditions: the bitNumber is successfully set to false.
void  Binary::clearBit(int bitNumber)
{
	if (bitNumber >= 0 && bitNumber < size)
		binaryArray[bitNumber] = false;
}

//-------------------------  convertToBinaryNumber  --------------------------
//Converts an integer in to an array that represents an equivalent binary
// number.
// Preconditions: The int num, yet to be converted to Binary.
// Postconditions: Sets the new Binary named binaryArray.
void Binary::convertToBinaryNumber(int num) {

	int index = 0;

	if (num < 0) {
		posBinary = false;
		num = abs(num);
	}

	size = prepareBinaryNumber(num);
	binaryArray = new bool[size];

	if (num == 0) {
		binaryArray[0] = false;
	}

	while (num > 0) {
		binaryArray[index] = (num % 2 == 1);
		num = num / 2;
		index++;
	}
}

//---------------------------  prepareBinaryNumber  -------------------------
// Prepares the binary, by checking the size and allocating the correct size
// array.
// Preconditions: The int num.
// Postconditions: Returns the size of the future array.
int Binary::prepareBinaryNumber(int num)
{
	int sizeOfTheFutureArray = 0;

	if (num == 0)
		return 1;

	while (num > 0) {
		num = num / 2;
		sizeOfTheFutureArray++;
	}

	return sizeOfTheFutureArray;
}

//------------------------  getSizeOfBinaryArray  ----------------------------
// Determines size of Binary object.
// Preconditions: None
// Postconditions: Returns the size.
int Binary::getSizeOfBinaryArray() const {
	return size;
}

//------------------------------ convertToInt  ------------------------------
// Converts the Binary to an integer with the help of convertToIntHelper.
// Preconditions: Binary to be converted.
// Postconditions: Binary is now the correct equivalent integer returned
// as result.
int Binary::convertToInt() const {

	int result = 0;

	for (int i = size - 1; i >= 0; i--) {
		if (binaryArray[i])
			result += convertToIntHelper(i);
	}

	if (binaryArray >= 0)
		result = -result;

	if (posBinary)
		result = abs(result);

	return(result);
}

//--------------------------- convertToIntHelper  ---------------------------
// Performs necessary operations to assist in converting the Binary to an
// integer.
// Preconditions: Binary yet to be converted to integer.
// Postconditions: Returns necessary value to assist in converting to integer.
int Binary::convertToIntHelper(int num) const {

	if (0 >= num)
		return(1);

	return(convertToIntHelper(num - 1) * 2);
}

//-------------------------------- isPositive  -------------------------------
// Returns a positive value.
// Preconditions: None
// Postconditions: Returns a positive value successfully.
bool Binary::isPositive() const {

	return posBinary;
}

//-----------------------------  <<  ----------------------------------------
// Overloaded output operator for class Binary.
// Preconditions: The num is passed into ostream to be printed out.
// Postconditions: The num results are printed out.
ostream& operator<<(ostream& out, const Binary& num)
{
	if (!num.isPositive())
		out << "-";

	for (int i = num.size - 1; i >= 0 ; i--) {
		out << num.binaryArray[i];
	}

	return out;
}

//----------------------------  >>  -----------------------------------------
// Overloaded input operator for class Binary.
// Preconditions: User input received.
// Postconditions: User input is now able to be processed.
istream& operator>>(istream& in, Binary& num)
{
	int newNum = 0;

	in >> newNum;
	num.convertToBinaryNumber(newNum);

	return in;
}