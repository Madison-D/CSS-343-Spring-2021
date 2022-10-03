//---------------------------------------------------------------------------
// CPP File: ComicBook.CPP
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
#include "ComicBook.h"

//------------------------------  ==  ---------------------------------------
// Determine if two comic books are equal.
// Preconditions: Two comic books that have not been compared.
// Postconditions: Two comic books are compared, returns true when equivalent
// in the order of publisher, then title, then year and then grade.
bool ComicBook::operator==(const ComicBook& comp) const
{
    return (comp.publisher == publisher && comp.title == title && comp.year == year && comp.grade == grade);
}

//------------------------------  !=  ---------------------------------------
// Determine if two comic books are in equal.
// Preconditions: Two comic books that have not been compared.
// Postconditions: Two comic books are compared, returns true when not equivalent
// in the order of publisher, then title, then year and then grade.
bool ComicBook::operator!=(const ComicBook& comp) const
{
    return (comp.publisher != publisher && comp.title != title && comp.year != year && comp.grade != grade);
}

//------------------------------  <  ---------------------------------------
// Determine which comic book is less than other comic book.
// Preconditions: Two comic books for comparison.
// Postconditions: Returns the smallest comic book
// in the order of publisher, then title, then year and then grade.
bool ComicBook::operator<(const ComicBook& comp) const
{
    if (publisher < comp.publisher)
        return true;
    if (title < comp.title)
        return true;
    if (year < comp.year)
        return true;
    return (grade < comp.grade);
}

//------------------------------  >  ---------------------------------------
// Determine which comic book is greater than other comic book.
// Preconditions: Two comic books for comparison.
// Postconditions: Returns the largest comic book in the order of publisher,
// then title, then year and then grade.
bool ComicBook::operator>(const ComicBook& comp) const
{
    if (publisher > comp.publisher)
        return true;
    if (title > comp.title)
        return true;
    if (year > comp.year)
        return true;
    return (grade > comp.grade);
}

//------------------------------  >=  ---------------------------------------
// Determine which comic book is greater than other comic book.
// Preconditions: Two comic books for comparison.
// Postconditions: Returns the largest comic book
// in the order of publisher, then title, then year and then grade.
bool ComicBook::operator>=(const ComicBook& comp) const
{
    if (publisher >= comp.publisher)
        return true;
    if (title >= comp.title)
        return true;
    if (year >= comp.year)
        return true;
    return (grade >= comp.grade);
}

//------------------------------  <=  ---------------------------------------
// Determine which comic book is less than other comic book.
// Preconditions: Two comic books for comparison.
// Postconditions: Returns the smallest comic book
// in the order of publisher, then title, then year and then grade.
bool ComicBook::operator<=(const ComicBook& comp) const
{
    if (publisher <= comp.publisher)
        return true;
    if (title <= comp.title)
        return true;
    if (year <= comp.year)
        return true;
    return (grade <= comp.grade);
}
