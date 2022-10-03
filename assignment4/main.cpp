//---------------------------------------------------------------------------
// Driver File: main.CPP
// Class: main
// Authors: Madison Dienhart
//---------------------------------------------------------------------------
// This is the main.cpp driver for Assignment 4 implementation.
// Assignment 4 Summary: Assignment 4 is a store simulator that uses a binary
// search tree, and a hash map to store data for pertaining to managing a
// store. It helps customers to buy and sell items that consist of comic books,
// sports cards, and coins. It keeps track of customer transactions, and
// customer information. It also tracks the entire inventory. Assignment 4
// uses inheritance and polymorphism.
//---------------------------------------------------------------------------

#include <iostream>
#include "InitializeLists.h"
#include <fstream>

int main()
{
    InitializeLists readFile;

    readFile.buildCustomers("hw4customers.txt");
    readFile.buildInventory("hw4inventory.txt");
    readFile.readCommands("hw4commands.txt");
}
