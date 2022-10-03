//---------------------------------------------------------------------------
// Header File: ComicBook.H
// Class: ComicBook
// Authors: Madison Dienhart
//---------------------------------------------------------------------------
// ComicBook class: A subclass to Item class, contains sorting/comparison features
// so that the comic book items can be organized into publisher, then title, then
// year and then grade.
//
//Includes:
//   -- == and != for comparison sorting.
//   -- > and < for comparison sorting.
//	 -- >= and <= for comparison sorting.
//   -- << for item output.
//   -- String and int values.
//---------------------------------------------------------------------------

#ifndef COMICBOOK_H
#define COMICBOOK_H

#include <iostream>
#include "Item.h"

using namespace std;


class ComicBook : public Item {

public:

	//------------------------------  ==  ---------------------------------------
	// Determine if two comic books are equal.
	// Preconditions: Two comic books that have not been compared.
	// Postconditions: Two comic books are compared, returns true when equivalent
	// in the order of publisher, then title, then year and then grade.
	virtual bool operator==(const ComicBook& comp) const;

	//------------------------------  !=  ---------------------------------------
	// Determine if two comic books are in equal.
	// Preconditions: Two comic books that have not been compared.
	// Postconditions: Two comic books are compared, returns true when not equivalent
	// in the order of publisher, then title, then year and then grade.
	virtual bool operator!=(const ComicBook& comp) const;

	//------------------------------  <  ---------------------------------------
	// Determine which comic book is less than other comic book.
	// Preconditions: Two comic books for comparison.
	// Postconditions: Returns the smallest comic book
	// in the order of publisher, then title, then year and then grade.
	virtual bool operator<(const ComicBook& comp) const;

	//------------------------------  >  ---------------------------------------
	// Determine which comic book is greater than other comic book.
	// Preconditions: Two comic books for comparison.
	// Postconditions: Returns the largest comic book in the order of publisher,
	// then title, then year and then grade.
	virtual bool operator>(const ComicBook& comp) const;

	//------------------------------  >=  ---------------------------------------
	// Determine which comic book is greater than other comic book.
	// Preconditions: Two comic books for comparison.
	// Postconditions: Returns the largest comic book
	// in the order of publisher, then title, then year and then grade.
	virtual bool operator>=(const ComicBook& comp) const;

	//------------------------------  <=  ---------------------------------------
	// Determine which comic book is less than other comic book.
	// Preconditions: Two comic books for comparison.
	// Postconditions: Returns the smallest comic book
	// in the order of publisher, then title, then year and then grade.
	virtual bool operator<=(const ComicBook& comp) const;

private:
	//Class Variables

	//Publisher
	string publisher;

	//Title
	string title;

	//Year
	int year;

	//Grade
	string grade;

};

#endif

