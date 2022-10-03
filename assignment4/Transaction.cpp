//---------------------------------------------------------------------------
// CPP File: Transaction.CPP
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

#include "Transaction.h"

//-------------------------- Constructor -----------------------------------
// Parameterized constructor to initialize all necessary values for transaction.
// Preconditions: None.
// Postconditions: Initialized variables.
Transaction::Transaction(Item* item, int ID, bool productPurchased)
{
	this->item = item;
	this->ID = ID;
	this->productPurchased = productPurchased;
}

//----------------------------- getID -------------------------------------
// The getID function retrieves ID.
// Preconditions: None.
// Postconditions: Returns ID.
int Transaction::getID()
{
	return ID;
}

//----------------------------- print -------------------------------------
// The print function for class Transaction.
// Preconditions: None.
// Postconditions: Prints output with information necessary for a
// transaction.
void Transaction::print()
{
	if (productPurchased) {
		cout << "Purchased: " << endl;
		cout << ID << " " << item;
	}
}