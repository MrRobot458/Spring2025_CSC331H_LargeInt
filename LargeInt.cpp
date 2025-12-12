/*
* Purpose:
*     This is the implementaion file for the LargeInt class. The C++ language standard is C++20.
*
* Input: None.
* Output: None.
*/

#include "LargeInt.h"
using namespace std;

//---- LargeInt class implementation ----//

// Constructor
LargeInt::LargeInt() {}

// Destructor
LargeInt::~LargeInt() {}

// Removes leading zeros
void LargeInt::removeLeadingZeros() {}

// Normalizes the LargeInt
void LargeInt::normalize() {}

// Addition operator (+)
LargeInt LargeInt::operator+(const LargeInt&) const {}

// Subtraction operator (-)
LargeInt LargeInt::operator-(const LargeInt&) const {}

// Multiplication operator (*)
LargeInt LargeInt::operator*(const LargeInt&) const {}

// Division operator (/)
LargeInt LargeInt::operator/(const LargeInt&) const {}

// Modulo operator (%)
LargeInt LargeInt::operator%(const LargeInt&) const {}

// Equality operator (==)
bool LargeInt::operator==(const LargeInt&) const {}

// Less than operator (<)
bool LargeInt::operator<(const LargeInt&) const {}

// Less than or equal to operator (<=)
bool LargeInt::operator<=(const LargeInt&) const {}

// Greater than operator operator (>)
bool LargeInt::operator>(const LargeInt&) const {}

// Greater than or equal to operator (>=)
bool LargeInt::operator>=(const LargeInt&) const {}

// Insertion operator (<<)
ostream& operator<<(ostream&, const LargeInt&) {}

// Extraction operator (>>)
istream& operator>>(istream&, LargeInt&) {}
