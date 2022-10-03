//---------------------------------------------------------------------------
// Header File: Item.H
// Class: Item
// Authors: Madison Dienhart
//---------------------------------------------------------------------------
// Item class: Acts as parent class for ComicBook, Coin, SportsCards and
// includes Comparable.h. Acts as a way to sort the items as needed for all
// necessary inventory lists for the store.
//
//Includes:
//   -- == and != for comparison.
//   -- > and < for comparison.
//	 -- >= and <= for comparison.
//   -- << for item output.
//   -- String and int values.
//---------------------------------------------------------------------------

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include "Comparable.h"

using namespace std;


class Item : public Comparable {

	//----------------------------- << -------------------------------------
	// Overloaded output operator for class Item.
	// Preconditions: Compared item values.
	// Postconditions: Outputs item values.
	friend ostream& operator<<(ostream& out, const Item& comp);

public:

	//------------------------------  ==  ---------------------------------------
	// Determine if two items are equal.
	// Preconditions: Two items that have not been compared.
	// Postconditions: Two items are compared, returns true when equivalent.
	bool operator==(const Item& comp) const;

	//------------------------------  !=  ---------------------------------------
	// Determine if two items are in equal.
	// Preconditions: Two items that have not been compared.
	// Postconditions: Two items are compared, returns true when not equivalent.
	bool operator!=(const Item& comp) const;

	//------------------------------  <  ---------------------------------------
	// Determine which item is less than other item.
	// Preconditions: Two items for comparison.
	// Postconditions: Returns the smallest item.
	bool operator<(const Item& comp) const;

	//------------------------------  >  ---------------------------------------
	// Determine which item is greater than other item.
	// Preconditions: Two items for comparison.
	// Postconditions: Returns the largest item.
	bool operator>(const Item& comp) const;

	//------------------------------  >=  ---------------------------------------
	// Determine which item is greater than other item.
	// Preconditions: Two items for comparison.
	// Postconditions: Returns the largest item.
	bool operator>=(const Item& comp) const;

	//------------------------------  <=  ---------------------------------------
	// Determine which item is less than other item.
	// Preconditions: Two items for comparison.
	// Postconditions: Returns the smallest item.
	bool operator<=(const Item& comp) const;

private:
	//Class Variables

	//char value
	char key;

	//int value
	int key;

};



#endif

