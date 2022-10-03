//---------------------------------------------------------------------------
// CPP File: InitializeLists.CPP
// Class: InitializeLists
// Authors: Madison Dienhart
//---------------------------------------------------------------------------
// InitializeLists class: Reads in all text files needed for the program to
// input the customer inventory, and transactions. InitializeLists inherits
// from StoreFactory.
//
// Includes:
//	-- buildCustomers function
//  -- buildInventory function
//  -- readCommands function
//  -- All necessary class variables
//---------------------------------------------------------------------------

#include "InitializeLists.h"

//----------------------- buildCustomers -----------------------------------
// The buildCustomers function reads customers from the customer list and
// adds them in the StoreFactory class.
// Preconditions: Text file of customers passed in.
// Postconditions: Customers added via the StoreFactory.
void InitializeLists::buildCustomers(ifstream& infile, InitializeLists& customers)
{
	Comparable* customer = new Comparable;
	infile >> *customer;
	if (infile.eof()) {
		delete customer;
		customer = nullptr;
		return;
	}

	bool success = customers.addCustomers(ID, name);
	if (!success) {
		delete customer;
	}
}

//----------------------- buildInventory -----------------------------------
// The buildInventory function reads inventory items from the inventory list
// and adds the items to the inventory through the StoreFactory class.
// Preconditions: Text file of inventory passed in.
// Postconditions: Inventory items are added in the StoreFactory class.
void InitializeLists::buildInventory(ifstream& infile, InitializeLists& inventory)
{
	Comparable* Inventory = new Comparable;
	infile >> *Inventory;
	if (infile.eof()) {
		delete Inventory;
		Inventory = nullptr;
		return;
	}

	bool success = inventory.addItemToInventory(item, marker);
	if (!success) {
		delete Inventory;
	}
}

//----------------------- readCommands -------------------------------------
// The readCommands function opens and reads the commands in the text file.
// Preconditions: Text file of commands are passed in.
// Postconditions: The file is opened and read.
void InitializeLists::readCommands(ifstream& infile, InitializeLists& commands)
{

}
