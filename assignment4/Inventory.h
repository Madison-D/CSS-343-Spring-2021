//---------------------------------------------------------------------------
// Header File: INVENTORY.H
// Class: Inventory
// Authors: Madison Dienhart
//---------------------------------------------------------------------------
// Inventory class: Inherits items from the Item class and then utilizes comparable
// and SearchTree class to sort each specific type of item in to its own search tree
// for storage. This allows for the inventory to be managed.
//
//Includes:
//   -- Constructor to create new trees.
//   -- > and < for comparison.
//   -- << for output.
//   -- Class variables.
//---------------------------------------------------------------------------

#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include "SearchTree.h"
#include "Comparable.h"
#include "Item.h"
#include <vector>

using namespace std;

class Inventory : public Item {

	//----------------------------- << -------------------------------------
	// Overloaded output operator for class Inventory.
	// Preconditions: Items sorted in to trees.
	// Postconditions: Outputs trees for all items.
	friend ostream& operator<<(ostream& out, const Inventory& tree);

public:

	//-------------------------- Constructor -----------------------------------
	// Constructor for Inventory class.
	// Preconditions: None.
	// Postconditions: Creates trees for items to be sorted into.
	Inventory();

	//-------------------------- addItem ---------------------------------------
	// The addItem function adds items to the correct binary search tree.
	// Preconditions: Item and char marker of item.
	// Postconditions:  Sorts items by their predetermined char marker and adds
	// in to the correct binary search tree for storage.
	void addItem(Item* item, char itemType);

	//-------------------------- removeItem ---------------------------------------
	// The removeItem function removes items from the correct binary search tree.
	// Preconditions: Item and char marker of item.
	// Postconditions:  Sorts items by their predetermined char marker and removes
	// item from the correct tree.
	void removeItem(Item* item, char itemType);

private:
	//Class Variables

	//vector to store trees
	vector <SearchTree*> Items;

	//pointer to Item class
	Item* item;
};

#endif

