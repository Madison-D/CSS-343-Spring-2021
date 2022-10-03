//---------------------------------------------------------------------------
// Header File: Coin.H
// Class: Coin
// Authors: Madison Dienhart
//---------------------------------------------------------------------------
// Coin class: A subclass to Item class, contains sorting/comparison features
// so that the coin items can be organized into type, then year, then grade.
//
//Includes:
//   -- == and != for comparison sorting.
//   -- > and < for comparison sorting.
//	 -- >= and <= for comparison sorting.
//   -- << for item output.
//   -- String and int values.
//---------------------------------------------------------------------------

#ifndef COIN_H
#define COIN_H

#include <iostream>
#include "Item.h"

using namespace std;

class Coin : public Item {

public:

	//------------------------------  ==  ---------------------------------------
	// Determine if two coins are equal.
	// Preconditions: Two coins that have not been compared.
	// Postconditions: Two coins are compared, returns true when equivalent
	// in the order of type, then year, and then grade.
	virtual bool operator==(const Coin& comp) const;

	//------------------------------  !=  ---------------------------------------
	// Determine if two coins are in equal.
	// Preconditions: Two coins that have not been compared.
	// Postconditions: Two coins are compared, returns true when not equivalent
	// in the order of type, then year, and then grade.
	virtual bool operator!=(const Coin& comp) const;

	//------------------------------  <  ---------------------------------------
	// Determine which coin is less than other coin.
	// Preconditions: Two coins for comparison.
	// Postconditions: Returns the smallest coin
	// in the order of type, then year, and then grade.
	virtual bool operator<(const Coin& comp) const;

	//------------------------------  >  ---------------------------------------
	// Determine which coin is greater than other coin.
	// Preconditions: Two coins for comparison.
	// Postconditions: Returns the largest coin
	// in the order of type, then year, and then grade.
	virtual bool operator>(const Coin& comp) const;

	//------------------------------  >=  ---------------------------------------
	// Determine which coin is greater than other coin.
	// Preconditions: Two coins for comparison.
	// Postconditions: Returns the largest coin
	// in the order of type, then year, and then grade.
	virtual bool operator>=(const Coin& comp) const;

	//------------------------------  <=  ---------------------------------------
	// Determine which coin is less than other coin.
	// Preconditions: Two coins for comparison.
	// Postconditions: Returns the smallest coin
	// in the order of type, then year, and then grade.
	virtual bool operator<=(const Coin& comp) const;

private:
	//Class Variables

	//Type
	string type;

	//Year
	int year;

	//Grade
	int grade;
};

#endif

