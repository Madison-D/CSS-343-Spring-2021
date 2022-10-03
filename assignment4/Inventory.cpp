//---------------------------------------------------------------------------
// CPP File: INVENTORY.CPP
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

#include "Inventory.h"

//-------------------------- Constructor -----------------------------------
// Constructor for Inventory class.
// Preconditions: None.
// Postconditions: Creates trees for items to be sorted into.
Inventory::Inventory()
{
	for (int i = 0; i < 3; i++) {
		Items.push_back(new SearchTree);
	}
}

//-------------------------- addItem ---------------------------------------
// The addItem function adds items to the correct binary search tree.
// Preconditions: Item and char marker of item.
// Postconditions:  Sorts items by their predetermined char marker and adds
// in to the correct binary search tree for storage.
void Inventory::addItem(Item* item, char itemType)
{
	if (itemType == 'M') {
		SearchTree* coins = Items[0];

		Comparable* coin = item;
		coins->insert(coin);
	}

	if (itemType == 'C') {
		SearchTree* comics = Items[1];

		Comparable* comic = item;
		comics->insert(comic);
	}

	if (itemType == 'S') {
		SearchTree* sportscards = Items[2];

		Comparable* sportscard = item;
		sportscards->insert(sportscard);
	}
}

//-------------------------- removeItem ---------------------------------------
// The removeItem function removes items from the correct binary search tree.
// Preconditions: Item and char marker of item.
// Postconditions:  Sorts items by their predetermined char marker and removes
// item from the correct tree.
void Inventory::removeItem(Item* item, char itemType)
{
	if (itemType == 'M') {
		SearchTree* coins = Items[0];

		Comparable& coin = *item;
		coins->remove(coin);
	}

	if (itemType == 'C') {
		SearchTree* comics = Items[1];

		Comparable& comic = *item;
		comics->remove(comic);
	}

	if (itemType == 'S') {
		SearchTree* sportscards = Items[2];

		Comparable& sportscard = *item;
		sportscards->remove(sportscard);
	}
}

//----------------------------- << -------------------------------------
// Overloaded output operator for class Inventory.
// Preconditions: Items sorted in to trees.
// Postconditions: Outputs trees for all items.
ostream& operator<<(ostream& out, const Inventory& trees)
{
	for (int i = 0; i < 3; i++) {
		out << trees.Items[i];
	}
}
