//---------------------------------------------------------------------------
// CPP File: Coin.CPP
// Class: Coin
// Authors: Madison Dienhart
//---------------------------------------------------------------------------
// Coin class: A subclass to Item class, contains sorting/comparison features
// so that the coin items can be organized into type, then year, then grade.
//
//Includes:
//   -- == and != for comparison sorting.
//   -- > and < for comparison sorting.
//	 -- >= and <= for comparison sorting.
//   -- << for item output.
//   -- String and int values.
//---------------------------------------------------------------------------

#include "Coin.h"

//------------------------------  ==  ---------------------------------------
// Determine if two coins are equal.
// Preconditions: Two coins that have not been compared.
// Postconditions: Two coins are compared, returns true when equivalent
// in the order of type, then year, and then grade.
bool Coin::operator==(const Coin& comp) const
{
    return (comp.type == type && comp.year == year && comp.grade == grade);
}

//------------------------------  !=  ---------------------------------------
// Determine if two coins are in equal.
// Preconditions: Two coins that have not been compared.
// Postconditions: Two coins are compared, returns true when not equivalent
// in the order of type, then year, and then grade.
bool Coin::operator!=(const Coin& comp) const
{
    return (comp.type != type && comp.year != year && comp.grade != grade);
}

//------------------------------  <  ---------------------------------------
// Determine which coin is less than other coin.
// Preconditions: Two coins for comparison.
// Postconditions: Returns the smallest coin
// in the order of type, then year, and then grade.
bool Coin::operator<(const Coin& comp) const
{
   if (type < comp.type)
        return true;
   if (year < comp.year)
        return true;
   return (grade < comp.grade);
}

//------------------------------  >  ---------------------------------------
// Determine which coin is greater than other coin.
// Preconditions: Two coins for comparison.
// Postconditions: Returns the largest coin.
bool Coin::operator>(const Coin& comp) const
{
    if (type > comp.type)
        return true;
    if (year > comp.year)
        return true;
    return (grade > comp.grade);

}

//------------------------------  >=  ---------------------------------------
// Determine which coin is greater than other coin.
// Preconditions: Two coins for comparison.
// Postconditions: Returns the largest coin
// in the order of type, then year, and then grade.
bool Coin::operator>=(const Coin& comp) const
{
    if (type >= comp.type)
        return true;
    if (year >= comp.year)
        return true;
    return (grade >= comp.grade);
}

//------------------------------  <=  ---------------------------------------
// Determine which coin is less than other coin.
// Preconditions: Two coins for comparison.
// Postconditions: Returns the smallest coin
// in the order of type, then year, and then grade.
bool Coin::operator<=(const Coin& comp) const
{
    if (type <= comp.type)
        return true;
    if (year <= comp.year)
        return true;
    return (grade <= comp.grade);
}
