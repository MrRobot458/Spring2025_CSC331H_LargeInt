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
LargeInt::LargeInt() { digits.insertFirst(0); }

// Destructor
LargeInt::~LargeInt() { }

// Removes leading zeros
void LargeInt::removeLeadingZeros() {
    DoublyLinkedList<int>::Iterator it = nullptr;  // Iterator for LargeInt digits

    while (digits.getLength() > 1) {
        // Set iterator to first digit
        it = digits.begin();

        if (*it == 0) digits.deleteItem(0);
        else break;
    }
    return;
}

// Normalizes the LargeInt (ensures at least one digit and no leading zeros)
void LargeInt::normalize() {
    // Remove leading zeros
    removeLeadingZeros();

    // Check if this is zero
    if (digits.isEmpty()) digits.insertFirst(0);
    return;
}

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
