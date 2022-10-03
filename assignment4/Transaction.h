//---------------------------------------------------------------------------
// Header File: Transaction.H
// Class: Transaction
// Authors: Madison Dienhart
//---------------------------------------------------------------------------
// Transaction class: Handles the buying/selling of items, inherits from
// the Item class. Determines if an item from the item class has
// been purchased using a boolean, outputs transaction with ID and item.
//
//Includes features such as:
//   -- Constructor for initialization.
//   -- getID function.
//   -- Print function for output.
//   -- Item pointer, bool, and int value.
//---------------------------------------------------------------------------

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include "Item.h"
#include "StoreFactory.h"
#include "Customer.h"

using namespace std;


class Transaction : public Item {

public:

	//-------------------------- Constructor -----------------------------------
	// Parameterized constructor to initialize all necessary values for transaction.
	// Preconditions: None.
	// Postconditions: Initialized variables.
	Transaction(Item* item, int ID, bool productPurchased);

	//----------------------------- getID -------------------------------------
	// The getID function retrieves ID.
	// Preconditions: None.
	// Postconditions: Returns ID.
	int getID();

	//----------------------------- print -------------------------------------
	// The print function for class Transaction.
	// Preconditions: None.
	// Postconditions: Prints output with information necessary for a
	// transaction.
	void print();

private:
	//Class Variables

	//Item pointer
	Item* item;

	//ID
	int ID;

	//product was purchased
	bool productPurchased;
};

#endif

