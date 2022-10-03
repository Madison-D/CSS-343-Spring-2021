//---------------------------------------------------------------------------
// Header File: SearchTree.h
// Class: SearchTree
// Author:  Madison Dienhart
//---------------------------------------------------------------------------
// SearchTree class:  Implements a binary search tree, uses the comparable
//class to add char values to the tree.
//---------------------------------------------------------------------------

#ifndef SEARCHTREE_H
#define SEARCHTREE_H

#include "Comparable.h"
#include <iostream>
using namespace std;

class SearchTree
{
	//----------------------------- << -------------------------------------
	// Overloaded output operator for class SearchTree.
	// Preconditions: The tree is passed into ostream to be printed out.
	// Postconditions: outputs tree data in to the format necessary for
	// the frequency table.
	friend ostream& operator<<(ostream& out, const SearchTree& tree);

public:

	//----------------------------- struct Node -------------------------------------
	// Node class
	// Preconditions: none
	// Postconditions: Node class for search tree.
	struct Node {
		//comparable pointer named pdata
		Comparable* pdata;

		//count variable
		int count = 0;

		//left pointer node
		Node* left = nullptr;

		//right pointer node
		Node* right = nullptr;
	};

	//-------------------------- Constructor ------------------------------------
	// Default constructor for class SearchTree.
	// Preconditions:   None
	// Postconditions: None
	SearchTree();

	//---------------------------- Copy -----------------------------------------
	// Copy constructor for class Search Tree with object named tree.
	// Preconditions: None
	// Postconditions: Deep copies tree, using deepCopy function.
	SearchTree(const SearchTree& tree);

	//---------------------------- Destructor -----------------------------------
	// Destructor for class SearchTree.
	// Preconditions: None
	// Postconditions:  Clears all memory allocated for SearchTree.
	~SearchTree();

	//-----------------------------  =  -----------------------------------------
	// Overloaded assignment operator.
	// Preconditions: The tree object prior to assignment.
	// Postconditions: The tree deep copied via the deepCopy Method
	// returns copied tree.
	const SearchTree& operator=(const SearchTree& tree);

	//------------------------------  ==  ---------------------------------------
	// Determine if two trees are exactly equal.
	// Preconditions: Two trees that have not been compared.
	// Postconditions: Two trees are compared, returns true when equivalent.
	bool operator==(const SearchTree& tree) const;

	//------------------------------  !=  ---------------------------------------
	// Determine if two trees are in equal.
	// Preconditions: Two trees that have not been compared.
	// Postconditions: Two trees are compared, returns true when not equivalent.
	bool operator!=(const SearchTree& tree) const;

	//----------------------------- insert -------------------------------------
	// Insert a node with a specified value to the tree.
	// Preconditions: A comparable value.
	// Postconditions: inserts pdata to tree using helper insert method.
	bool insert(Comparable* pdata);

	//----------------------------- remove -------------------------------------
	// Removes the target value from the tree.
	// Preconditions: Comparable pdata value.
	// Postconditions: pdata and root are passed in to remove helper function to
	// remove value.
	bool remove(const Comparable& pdata);

	//----------------------------- makeEmpty -------------------------------------
	// Empties tree of all data using helper function makeEmpty.
	// Preconditions: Tree with data.
	// Postconditions: Emptied tree.
	void makeEmpty();

	//----------------------------- retrieve -------------------------------------
	// Retrieve function helps to locate the existence of a value through pdata.
	// Preconditions: Target value to be found.
	// Postconditions: Returns value if found.
	const Comparable* retrieve(const Comparable& pdata) const;

	//----------------------------- height -------------------------------------
	// Finds the height of node in the tree.
	// Preconditions: None
	// Postconditions: Uses helper method named height to locate height.
	int height(const Comparable& pdata) const;

private:

	Node* root;

	//----------------------------- insert -------------------------------------
	// Helper method to insert a node with a specified value to the tree.
	// Preconditions: A comparable value.
	// Postconditions: inserts pdata to tree.
	bool insert(Comparable* pdata, Node*& node);

	//----------------------------- remove -------------------------------------
	// Remove helper function, traverses left/right side of tree until targeted
	// value is found.
	// Preconditions: pdata and root.
	// Postconditions: node is found through == and passed to helper function for
	// Node removal in the removeNode method.
	bool remove(const Comparable& pdata, Node*& node);

	//----------------------------- removeNode -------------------------------------
	// Remove node function, removes the target value from the tree.
	// Preconditions: Node for removal.
	// Postconditions: Prepares node for removal, node is deleted,
	// then the findAndDeleteMostLeft is called.
	void removeNode(Node*& node);

	//--------------------------- findAndDeleteMostLeft -----------------------------
	// Helps with removing the target value from the tree by assisting with
	// replacement node.
	// Preconditions: Comparable pdata value.
	// Postconditions: Replacement node returned.
	Comparable* findAndDeleteMostLeft(Node*& node);

	//----------------------------- makeEmpty -------------------------------------
	// Helper method that deletes tree data node by node. Empties tree of all data.
	// Preconditions: Tree with data.
	// Postconditions: Emptied tree.
	void makeEmpty(Node*& node);

	//----------------------------- height -------------------------------------
	// Helper method that finds the height of node in the tree.
	// Preconditions: None
	// Postconditions: Uses helper method named height to locate height.
	int height(Node* node) const;

	//----------------------------- inOrderTraversal ----------------------------
	// Peforms an in order traversal of the tree.
	// Preconditions: None
	// Postconditions: In order traversal is completed.
	void inOrderTraversal(Node* node) const;

	//----------------------------- deepCopy -------------------------------------
	// Creates a deep copy of the tree by copying every node of previous tree.
	// Preconditions: assignment operator passes in tree.pdata.
	// Postconditions: Copied nodes returned.
	void deepCopy(Node* node);
};

#endif