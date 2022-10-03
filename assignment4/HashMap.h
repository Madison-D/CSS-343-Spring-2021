//---------------------------------------------------------------------------
// Header File: HashMap.H
// Class: HashMap
// Authors: Madison Dienhart
//---------------------------------------------------------------------------
// HashMap class: Interacts with the Transaction class to store transaction
// data. Contains a vector of customers so that their transactions may be
// stored with their information (customer ID and name.)
//
// Includes features such as:
//   -- Insert values to a hash map to store transaction data.
//   -- Retrieve values from the hash map to locate transaction data.
//---------------------------------------------------------------------------

#ifndef HASHMAP_H
#define HASHMAP_H

#include <iostream>
#include <vector>
#include "Transaction.h"

using namespace std;


class HashMap {

public:

	//----------------------------- Constructor -------------------------------------
	// Constructor for HashMap class.
	// Preconditions: None
	// Postconditions: None
	HashMap();

	//----------------------------- insert -------------------------------------
	// Insert retrieves the customer ID from the transaction class and stores
	// a transaction to that ID in the array in the hash map.
	// Preconditions: Transaction object from transaction class.
	// Postconditions: Id and transaction are successfully stored.
	void insert(Transaction* transaction);

	//---------------------------- retrieve ------------------------------------
	// Retrieves a customer ID to locate associated transactions using a vector.
	// Preconditions: Customer ID.
	// Postconditions:Returns customer ID data in the array.
	vector<Transaction*> retrieve(int ID);

private:

	//Class Variables
	//Vector where each array index represents a customer.
	vector<Transaction*> array[1000];
};

#endif

