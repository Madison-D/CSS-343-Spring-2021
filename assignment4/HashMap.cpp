//---------------------------------------------------------------------------
// CPP File: HashMap.CPP
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
#include "HashMap.h"

//----------------------------- Constructor -------------------------------------
// Constructor for HashMap class.
// Preconditions: None
// Postconditions: None
HashMap::HashMap() {}

//----------------------------- insert -------------------------------------
// Insert retrieves the customer ID from the transaction class and stores
// a transaction to that ID in the array in the hash map.
// Preconditions: Transaction object from transaction class.
// Postconditions: Id and transaction are successfully stored.
void HashMap::insert(Transaction* transaction)
{
	int ID = transaction->getID();

	vector<Transaction*> transactions = array[ID];
	transactions.push_back(transaction);
}

//---------------------------- retrieve ------------------------------------
// Retrieves a customer ID to locate associated transactions using a vector.
// Preconditions: Customer ID.
// Postconditions:Returns customer ID data in the array.
vector<Transaction*> HashMap::retrieve(int ID)
{
	return array[ID];
}

