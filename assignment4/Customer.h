//---------------------------------------------------------------------------
// Header File: Customer.h
// Class: Customer
// Author:  Madison Dienhart
//---------------------------------------------------------------------------
// Customer class:  Inherits and outputs values for comparison, so that
// the customer information may be sorted in to the correct order when stored.
// Interacts with Comparable class. Data is stored in a binary search tree.
// Also, retrieves information for the customer, ID and name.
//
// Includes features such as:
//	 -- Parameterized constructor for initialization.
//   -- == and != for comparison and subsequent sorting.
//   -- > and < for comparison and subsequent sorting.
//	 -- >= and <= for comparison and subsequent sorting.
//	 -- Functions to retrieve data, getID, and getName.
//   -- String and int values.
//---------------------------------------------------------------------------

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include "Comparable.h"

using namespace std;

class Customer : public Comparable {

public:

	//---------------------------  Constructor  ----------------------------------
	// Constructor with parameters to initialize ID and name of customer.
	// Preconditions: ID and name passed in.
	// Postconditions: Initialized ID and name.
	Customer(int ID, string Name);

	//------------------------------  ==  ---------------------------------------
	// Determine if two values are equal.
	// Preconditions: Two values that have not been compared.
	// Postconditions: Two values are compared, returns true when equivalent.
	virtual bool operator==(const Customer& comp) const;

	//-----------------------------  !=  ----------------------------------------
	// Determine if two values are in equal.
	// Preconditions: Two values that have not been compared.
	// Postconditions: Two values are compared, returns true when not equivalent.
	virtual bool operator!=(const Customer& comp) const;

	//------------------------------  <  ----------------------------------------
	// Determine which customer name value is less than other customer name value.
	// Preconditions: Two customer name values for comparison.
	// Postconditions: Returns the smallest customer name value.
	virtual bool operator<(const Customer& comp) const;

	//------------------------------  >  ----------------------------------------
	// Determine which customer name value is greater than other customer name
	// value.
	// Preconditions: Two customer name values for comparison.
	// Postconditions: Returns the largest customer name value.
	virtual bool operator>(const Customer& comp) const;

	//------------------------------  >=  ---------------------------------------
	// Determine which customer name value is greater than other customer name
	// value.
	// Preconditions: Two customer name values for comparison.
	// Postconditions: Returns the largest customer name value.
	virtual bool operator>=(const Customer& comp) const;

	//------------------------------  <=  ---------------------------------------
	// Determine which customer name value is less than other customer name value.
	// Preconditions: Two customer name values for comparison.
	// Postconditions: Returns the lesser customer name value.
	virtual bool operator<=(const Customer& comp) const;

	//----------------------------- getName -------------------------------------
	// The getName function retrieves the name for a customer.
	// Preconditions: None.
	// Postconditions: Returns name.
	string getName();

	//----------------------------- getID ---------------------------------------
	// The getID function retrieves the ID number for a customer.
	// Preconditions: None.
	// Postconditions: Returns ID.
	int getID();

private:
	//Class variables

	//Name
	string name;

	//ID
	int ID;

};

#endif

