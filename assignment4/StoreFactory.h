//---------------------------------------------------------------------------
// Header File: StoreFactory.H
// Class: StoreFactory
// Authors: Madison Dienhart
//---------------------------------------------------------------------------
// StoreFactory class: The StoreFactory class inherits from the Transaction
// class. It acts as a central point for all information to enter from the
// Initialize Lists class, and adds customers, inventory items, and
// transactions. It also works to print all versions of lists.
//
// Includes:
//	-- addCustomers function
//	-- addItemToInventory function
//	-- removeItemFromInventory function
//	-- processTransaction function
//	-- allInventoryDisplay function
//	-- allCustomerDisplay function
//	-- singleCustomerDisplay function
//  -- Necessary class variables.
//---------------------------------------------------------------------------

#ifndef STOREFACTORY_H
#define STOREFACTORY_H

#include <iostream>
#include "Comparable.h"
#include "Customer.h"
#include "Item.h"
#include "SearchTree.h"
#include "Inventory.h"
#include "HashMap.h"

using namespace std;

class StoreFactory : public Transaction {

public:

	//----------------------------- addCustomer ----------------------------------
	// The addCustomer function adds a customer in the customer class.
	// Preconditions: ID and Name are passed in to add customer.
	// Postconditions: Customer is successfully added.
	bool addCustomers(int ID, string Name);

	//----------------------------- addItemToInventory --------------------------
	// The addItemToInventory function inserts item in to the inventory to be
	// stored in a binary search tree.
	// Preconditions: Item and marker indicating item type are passed in to be
	// inserted.
	// Postconditions: Item is successfully inserted in to the inventory.
	bool addItemToInventory(Item* item, char marker);

	//----------------------------- removeItemFromInventory ----------------------
	// The removeItemFromInventory function removes an item from inventory that's been
	// stored in a binary search tree.
	// Preconditions: Item and marker indicating item type are passed in for removal.
	// Postconditions: Item is successfully removed from the inventory.
	void removeItemFromInventory(Item* item, char marker);

	//----------------------------- processTransaction ---------------------------
	// The processTransaction function processes a transaction for a customer.
	// Preconditions: Customer Id, the item, and if the product was purchased.
	// Postconditions: Processes transaction for a customer.
	void processTransaction(int ID, Item* item, bool productPurchased);

	//----------------------------- allInventoryDisplay ---------------------------
	// The allInventoryDisplay function prints all inventory and the qty.
	// Preconditions: None.
	// Postconditions: Prints all inventory and quantity.
	void allInventoryDisplay();

	//----------------------------- allCustomerDisplay ---------------------------
	// The allCustomerDisplay function prints all customers and their history in
	// order.
	// Preconditions: None.
	// Postconditions: Prints a display of all customers and their transaction
	// history.
	void allCustomerDisplay();

	//----------------------------- singleCustomerDisplay ---------------------------
	// The singleCustomerDisplay function prints all history for a single customer.
	// Preconditions: customer ID
	// Postconditions: Prints a display of a single customers transaction history.
	void singleCustomerDisplay(int ID);

private:

	//Class Variables

	//Pointer for customer tree.
	SearchTree* Customers;

	// Pointer for inventory.
	Inventory* Inventory;

	//Pointer for transaction hash map.
	HashMap* Transactions;

	//Pointer for item.
	Item* item;
};

#endif

