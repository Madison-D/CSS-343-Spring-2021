//---------------------------------------------------------------------------
// Header File: InitializeLists.H
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

#ifndef INITIALIZELISTS_H
#define INITIALIZELISTS_H

#include <iostream>
#include <fstream>
#include "Comparable.h"
#include "Customer.h"
#include "StoreFactory.h"
#include "Item.h"

using namespace std;

class InitializeLists : public StoreFactory {

public:
	//----------------------------- Constructor -------------------------------------
	// Constructor for InitializeLists class.
	// Preconditions: None
	// Postconditions: None
	InitializeLists() {};

	//----------------------- buildCustomers -----------------------------------
	// The buildCustomers function reads customers from the customer list and
	// adds them in the StoreFactory class.
	// Preconditions: Text file of customers passed in.
	// Postconditions: Customers added via the StoreFactory.
	void buildCustomers(ifstream& infile, InitializeLists& customers);

	//----------------------- buildInventory -----------------------------------
	// The buildInventory function reads inventory items from the inventory list
	// and adds the items to the inventory through the StoreFactory class.
	// Preconditions: Text file of inventory passed in.
	// Postconditions: Inventory items are added in the StoreFactory class.
	void buildInventory(ifstream& infile, InitializeLists& inventory);

	//----------------------- readCommands -------------------------------------
	// The readCommands function opens and reads the commands in the text file.
	// Preconditions: Text file of commands are passed in.
	// Postconditions: The file is opened and read.
	void readCommands(ifstream& infile, InitializeLists& commands);

private:
	//Class Variables

	//pointer for customer Comparable
	Comparable* customer;

	//pointer for item
	Item* item;

	// Name variable
	string name;

	// Customer ID variable
	int ID;

	//Marker for item
	char marker;
};

#endif

