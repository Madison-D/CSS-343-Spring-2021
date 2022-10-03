//---------------------------------------------------------------------------
// CPP File: SportsCard.CPP
// Class: SportsCard
// Authors: Madison Dienhart
//---------------------------------------------------------------------------
// SportsCard class: A subclass to Item class, contains sorting/comparison features
// so that the sports card items can be organized into player, then year, then
// manufacturer and then grade.
//
//Includes:
//   -- == and != for comparison sorting.
//   -- > and < for comparison sorting.
//	 -- >= and <= for comparison sorting.
//   -- << for item output.
//   -- String and int values.
//---------------------------------------------------------------------------

#include "SportsCard.h"

//------------------------------  ==  ---------------------------------------
// Determine if two sports cards are equal.
// Preconditions: Two sports cards that have not been compared.
// Postconditions: Two sports cards are compared, returns true when equivalent
// in the order of player, then year, then manufacturer and then grade.
bool SportsCard::operator==(const SportsCard& comp) const
{
    return (comp.player == player && comp.year == year && comp.manufacturer == manufacturer && comp.grade == grade);
}

//------------------------------  !=  ---------------------------------------
// Determine if two sports cards are in equal.
// Preconditions: Two sports cards that have not been compared.
// Postconditions: Two sports cards are compared, returns true when not equivalent
// in the order of player, then year, then manufacturer and then grade.
bool SportsCard::operator!=(const SportsCard& comp) const
{
    return (comp.player != player && comp.year != year && comp.manufacturer != manufacturer && comp.grade != grade);
}

//------------------------------  <  ---------------------------------------
// Determine which sports card is less than other sports card.
// Preconditions: Two sports cards for comparison.
// Postconditions: Returns the smallest sports card
// in the order of player, then year, then manufacturer and then grade.
bool SportsCard::operator<(const SportsCard& comp) const
{
    if (player < comp.player)
        return true;
    if (year < comp.year)
        return true;
    if (manufacturer < comp.manufacturer)
        return true;
    return (grade < comp.grade);
}

//------------------------------  >  ---------------------------------------
// Determine which sports card is greater than other sports card.
// Preconditions: Two sports cards for comparison.
// Postconditions: Returns the largest sports card
bool SportsCard::operator>(const SportsCard& comp) const
{
    if (player > comp.player)
        return true;
    if (year > comp.year)
        return true;
    if (manufacturer > comp.manufacturer)
        return true;
    return (grade > comp.grade);
}

//------------------------------  >=  ---------------------------------------
// Determine which sports card is greater than other sports card.
// Preconditions: Two sports cards for comparison.
// Postconditions: Returns the largest sports card
// in the order of player, then year, then manufacturer and then grade.
bool SportsCard::operator>=(const SportsCard& comp) const
{
    if (player >= comp.player)
        return true;
    if (year >= comp.year)
        return true;
    if (manufacturer >= comp.manufacturer)
        return true;
    return (grade >= comp.grade);
}

//------------------------------  <=  ---------------------------------------
// Determine which sports card is less than other sports card.
// Preconditions: Two sports cards for comparison.
// Postconditions: Returns the smallest sports card
// in the order of player, then year, then manufacturer and then grade.
bool SportsCard::operator<=(const SportsCard& comp) const
{
    if (player <= comp.player)
        return true;
    if (year <= comp.year)
        return true;
    if (manufacturer <= comp.manufacturer)
        return true;
    return (grade <= comp.grade);
}
