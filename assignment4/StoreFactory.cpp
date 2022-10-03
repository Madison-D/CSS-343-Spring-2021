//---------------------------------------------------------------------------
// CPP File: StoreFactory.CPP
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
#include "StoreFactory.h"

//----------------------------- addCustomer ----------------------------------
// The addCustomer function adds a customer in the customer class.
// Preconditions: ID and Name are passed in to add customer.
// Postconditions: Customer is successfully added.
bool StoreFactory::addCustomers(int ID, string Name)
{
	Comparable* Customer = new Customer(ID, Name);

	Customers->insert(Customer);
}

//----------------------------- addItemToInventory --------------------------
// The addItemToInventory function inserts item in to the inventory to be
// stored in a binary search tree.
// Preconditions: Item and marker indicating item type are passed in to be
// inserted.
// Postconditions: Item is successfully inserted in to the inventory.
bool StoreFactory::addItemToInventory(Item* item, char marker)
{
	Inventory->addItem(item, marker);
}

//----------------------------- removeItemFromInventory ----------------------
// The removeItemFromInventory function removes an item from inventory that's been
// stored in a binary search tree.
// Preconditions: Item and marker indicating item type are passed in for removal.
// Postconditions: Item is successfully removed from the inventory.
void StoreFactory::removeItemFromInventory(Item* item, char marker)
{
	Inventory->removeItem(item, marker);
}

//----------------------------- processTransaction ---------------------------
// The processTransaction function processes a transaction for a customer.
// Preconditions: Customer Id, the item, and if the product was purchased.
// Postconditions: Processes transaction for a customer.
void StoreFactory::processTransaction(int ID, Item* item, bool productPurchased)
{
	Transaction* transaction = new Transaction(ID, item, productPurchased);

	Transactions->insert(transaction);
}

//----------------------------- allInventoryDisplay ---------------------------
// The allInventoryDisplay function prints all inventory and the qty.
// Preconditions: None.
// Postconditions: Prints all inventory and quantity.
void StoreFactory::allInventoryDisplay()
{
	cout << Inventory;
}

//----------------------------- allCustomerDisplay ---------------------------
// The allCustomerDisplay function prints all customers and their history in
// order.
// Preconditions: None.
// Postconditions: Prints a display of all customers and their transaction
// history.
void StoreFactory::allCustomerDisplay()
{
	print();
}

//----------------------------- singleCustomerDisplay ---------------------------
// The singleCustomerDisplay function prints all history for a single customer.
// Preconditions: customer ID
// Postconditions: Prints a display of a single customers transaction history.
void StoreFactory::singleCustomerDisplay(int ID)
{
		cout << Transactions;
}

