//---------------------------------------------------------------------------
// Header File: SportsCard.H
// Class: SportsCard
// Authors: Madison Dienhart
//---------------------------------------------------------------------------
// SportsCard class: A subclass to Item class, contains sorting/comparison features
// so that the sports card items can be organized into player, then year, then
// manufacturer and then grade.
//
//Includes:
//   -- == and != for comparison sorting.
//   -- > and < for comparison sorting.
//	 -- >= and <= for comparison sorting.
//   -- << for item output.
//   -- String and int values.
//---------------------------------------------------------------------------

#ifndef SPORTSCARD_H
#define SPORTSCARD_H

#include <iostream>
#include "Item.h"

using namespace std;

class SportsCard : public Item {

public:

	//------------------------------  ==  ---------------------------------------
	// Determine if two sports cards are equal.
	// Preconditions: Two sports cards that have not been compared.
	// Postconditions: Two sports cards are compared, returns true when equivalent
	// in the order of player, then year, then manufacturer and then grade.
	virtual bool operator==(const SportsCard& comp) const;

	//------------------------------  !=  ---------------------------------------
	// Determine if two sports cards are in equal.
	// Preconditions: Two sports cards that have not been compared.
	// Postconditions: Two sports cards are compared, returns true when not equivalent
	// in the order of player, then year, then manufacturer and then grade.
	virtual bool operator!=(const SportsCard& comp) const;

	//------------------------------  <  ---------------------------------------
	// Determine which sports card is less than other sports card.
	// Preconditions: Two sports cards for comparison.
	// Postconditions: Returns the smallest sports card
	// in the order of player, then year, then manufacturer and then grade.
	virtual bool operator<(const SportsCard& comp) const;

	//------------------------------  >  ---------------------------------------
	// Determine which sports card is greater than other sports card.
	// Preconditions: Two sports cards for comparison.
	// Postconditions: Returns the largest sports card
	//in the order of player, then year, then manufacturer and then grade.
	virtual bool operator>(const SportsCard& comp) const;

	//------------------------------  >=  ---------------------------------------
	// Determine which sports card is greater than other sports card.
	// Preconditions: Two sports cards for comparison.
	// Postconditions: Returns the largest sports card
	// in the order of player, then year, then manufacturer and then grade.
	virtual bool operator>=(const SportsCard& comp) const;

	//------------------------------  <=  ---------------------------------------
	// Determine which sports card is less than other sports card.
	// Preconditions: Two sports cards for comparison.
	// Postconditions: Returns the smallest sports card
	// in the order of player, then year, then manufacturer and then grade.
	virtual bool operator<=(const SportsCard& comp) const;

private:
	//Class Variables

	//Player
	string player;

	//Year
	int year;

	//Manufacturer
	string manufacturer;

	//Grade
	string grade;

};

#endif

