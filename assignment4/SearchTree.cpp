//---------------------------------------------------------------------------
// cpp File: SearchTree.cpp
// Class: SearchTree
// Author:  Madison Dienhart
//---------------------------------------------------------------------------
// SearchTree class:  Implements a binary search tree, uses the comparable
// class to add values to the tree.
//
//   Includes additional features:
//   -- Takes a deep copy of the tree, assigns one tree to another.
//   -- Compares two trees for equality/inequality.
//   -- Removes a target value.
//   -- Uses Comparable to retrieve a target value.
//
// Assumptions:
//   -- Incorporates use of pointer to the comparable data
//---------------------------------------------------------------------------

#ifndef SEARCHTREE_CPP
#define SEARCHTREE_CPP

#include "SearchTree.h"
#include <iostream>

using namespace std;

//----------------------------- << -------------------------------------
// Overloaded output operator for class SearchTree.
// Preconditions: The tree is passed into ostream to be printed out.
// Postconditions: outputs tree data in to the format necessary for
// the frequency table.
ostream& operator<<(ostream& out, const SearchTree& tree)
{
    tree.inOrderTraversal(out, tree.root);
    return out;
}

//-------------------------- Constructor ------------------------------------
// Default constructor for class SearchTree.
// Preconditions:   None
// Postconditions: None
SearchTree::SearchTree() : root{ nullptr }
{
}

//---------------------------- Copy -----------------------------------------
// Copy constructor for class Search Tree with object named tree.
// Preconditions: None
// Postconditions: Deep copies tree, using deepCopy function.
SearchTree::SearchTree(const SearchTree& tree) : root{ nullptr }
{
    if (this != &tree) {
        makeEmpty();
        deepCopy(tree.root);
    }
}

//---------------------------- Destructor -----------------------------------
// Destructor for class SearchTree.
// Preconditions: None
// Postconditions:  Clears all memory allocated for SearchTree.
SearchTree::~SearchTree()
{
    makeEmpty();
}

//-----------------------------  =  -----------------------------------------
// Overloaded assignment operator.
// Preconditions: The tree object prior to assignment.
// Postconditions: The tree deep copied via the deepCopy Method
// returns copied tree.
const SearchTree& SearchTree::operator=(const SearchTree& tree)
{
    if (this != &tree) {
        makeEmpty();
        deepCopy(tree.root);
    }
    return *this;
}

//----------------------------- deepCopy -------------------------------------
// Creates a deep copy of the tree by copying every node of previous tree.
// Preconditions: assignment operator passes in tree.pdata.
// Postconditions: Copied nodes returned.
void SearchTree::deepCopy(Node* node)
{
    if (node != nullptr)
    {
        insert(node->pdata);
        deepCopy(node->left);
        deepCopy(node->right);
    }
}

//------------------------------  ==  ---------------------------------------
// Determine if two trees are exactly equal.
// Preconditions: Two trees that have not been compared.
// Postconditions: Two trees are compared, returns true when equivalent.
bool SearchTree::operator==(const SearchTree& tree) const
{
    return compareTrees(root, tree.root);
}

//------------------------------  !=  ---------------------------------------
// Determine if two trees are in equal.
// Preconditions: Two trees that have not been compared.
// Postconditions: Two trees are compared, returns true when not equivalent.
bool SearchTree::operator!=(const SearchTree& tree) const
{
    return !compareTrees(root, tree.root);
}

bool SearchTree::compareTrees(Node* tree1, Node* tree2) const {

    if (tree1 != nullptr && tree2 != nullptr) {
        if (*tree1->pdata == *tree2->pdata && tree1->count == tree2->count
            && compareTrees(tree1->left, tree2->left)
            && compareTrees(tree1->right, tree2->right))
            return true;
    }

    if (tree1 == nullptr && tree2 == nullptr)
        return true;

    return false;
}

//----------------------------- insert -------------------------------------
// Insert a node with a specified value to the tree.
// Preconditions: A comparable value.
// Postconditions: inserts pdata to tree using helper insert method.
bool SearchTree::insert(Comparable* pdata)
{
    return insert(pdata, root);
}

//----------------------------- insert -------------------------------------
// Helper method to insert a node with a specified value to the tree.
// Preconditions: A comparable value.
// Postconditions: inserts pdata to tree.
bool SearchTree::insert(Comparable* pdata, Node*& node) {

    if (node == nullptr)
    {
        node = new Node;
        node->pdata = pdata;
        node->left = nullptr;
        node->right = nullptr;
    }
    else {
        if (*pdata == *node->pdata) {
            node->count++;
            return false;
        }

        if (*pdata < *node->pdata)
            return insert(pdata, node->left);

        else
            return insert(pdata, node->right);
    }

    return true;
}

//----------------------------- remove -------------------------------------
// Removes the target value from the tree.
// Preconditions: Comparable pdata value.
// Postconditions: pdata and root are passed in to remove helper function to
// remove value.
bool SearchTree::remove(const Comparable& pdata)
{
    return remove(pdata, root);
}

//----------------------------- remove -------------------------------------
// Remove helper function, traverses left/right side of tree until targeted
// value is found.
// Preconditions: pdata and root.
// Postconditions: node is found through == and passed to helper function for
// Node removal in the removeNode method.
bool SearchTree::remove(const Comparable& pdata, Node*& node)
{
    if (node == nullptr)
        return false;

    if (pdata == *node->pdata) {
        removeNode(node);
        return true;
    }

    if (pdata < *node->pdata)
        return remove(pdata, node->left);

    else
        return remove(pdata, node->right);
}

//----------------------------- removeNode -------------------------------------
// Remove node function, removes the target value from the tree.
// Preconditions: Node for removal.
// Postconditions: Prepares node for removal, node is deleted,
// then the findAndDeleteMostLeft is called.
void SearchTree::removeNode(Node*& node)
{
    if (node->left == nullptr && node->right == nullptr)
    {
        delete node;
        node = nullptr;
        return;
    }

    if (node->left == nullptr || node->right == nullptr) {
        Node* temp = node;
        node = node->left == nullptr ? node->right : node->left;
        delete temp;
        return;
    }

    else
        node->pdata = findAndDeleteMostLeft(node->right);
}

//--------------------------- findAndDeleteMostLeft -----------------------------
// Helps with removing the target value from the tree by assisting with
// replacement node.
// Preconditions: Comparable pdata value.
// Postconditions: Replacement node returned.
Comparable* SearchTree::findAndDeleteMostLeft(Node*& node)
{
    if (node->left == nullptr) {
        Node* tempTrash = node;
        node = node->right;
        Comparable* pdata = tempTrash->pdata;
        delete tempTrash;
        return pdata;
    }
    return findAndDeleteMostLeft(node->left);
}

//----------------------------- makeEmpty -------------------------------------
// Empties tree of all data using helper function makeEmpty.
// Preconditions: Tree with data.
// Postconditions: Emptied tree.
void SearchTree::makeEmpty()
{
    makeEmpty(root);
    root = nullptr;
}

//----------------------------- makeEmpty -------------------------------------
// Helper method that deletes tree data node by node. Empties tree of all data.
// Preconditions: Tree with data.
// Postconditions: Emptied tree.
void SearchTree::makeEmpty(Node*& node)
{
    if (node == nullptr)
        return;

    if (node->left != nullptr)
        makeEmpty(node->left);

    if (node->right != nullptr)
        makeEmpty(node->right);

    delete node;
    node = nullptr;
}

//----------------------------- retrieve -------------------------------------
// Retrieve function helps to locate the existence of a value through pdata.
// Preconditions: Target value to be found.
// Postconditions: Returns value if found.
const Comparable* SearchTree::retrieve(const Comparable& pdata) const
{
    Node* node = root;

    while (node != nullptr) {
        if (pdata == *node->pdata)
            return node->pdata;

        else if (pdata < *node->pdata)
            node = node->left;

        else
            node = node->right;
    }

    return nullptr;
}

//----------------------------- height -------------------------------------
// Finds the height of node in the tree.
// Preconditions: None
// Postconditions: Uses helper method named height to locate height.
int SearchTree::height(const Comparable& pdata) const
{
    int lheight;
    int rheight;

    if (pdata == *root->pdata)
        return 0;

    if (pdata < *root->pdata)
        lheight = 1 + heightHelper(root->left);

    else
        rheight = 1 + heightHelper(root->right);

    int height = max(lheight, rheight);

    return height;
}

//----------------------------- height -------------------------------------
// Helper method that finds the height of node in the tree.
// Preconditions: None
// Postconditions: Uses helper method named height to locate height.
int SearchTree::heightHelper(Node* node) const {
    if (node == nullptr)
        return -1;

    else
        return height(*root->pdata);
}

//----------------------------- inOrderTraversal ----------------------------
// Performs an in order traversal of the tree.
// Preconditions: None
// Postconditions: In order traversal is completed.
void SearchTree::inOrderTraversal(ostream& out, Node* node) const
{
    if (node == nullptr)
        return;

    inOrderTraversal(out, node->left);

    cout << *node->pdata << " " << node->count << endl;

    inOrderTraversal(out, node->right);
}

#endif