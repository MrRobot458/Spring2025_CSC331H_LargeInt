/*
* Purpose:
*     This program tests the LargeInt class by performing arithmetic operations on two LargeInt values provided by the user.
*     Rules regarding the LargeInt type:
*         1. LargeInt type is non-negative (>= 0).
*         2. For subtraction, the LargeInt being subtracted must be smaller. If not, the result of the subtraction will be
*            zero in order to maintain rule #1.
*         3. For division, currently division by zero will return a result of zero (0). This is temporary and will be improved
*            later.
* 
* Input: None.
* Output: None.
*/

#ifndef LARGE_INT_H
#define LARGE_INT_H

#include "DoublyLinkedList.h"
#include <iostream>

//---- LargeInt class declaration ----//
class LargeInt {
    private:
        DoublyLinkedList<int> digits;  // Doubly linked list that stores the digits of the LargeInt

        // Removes leading zeros
        void removeLeadingZeros();

        // Normalizes the LargeInt (ensures at least one digit and no leading zeros)
        void normalize();

    public:
        // Constructor
        LargeInt();

        // Destructor
        ~LargeInt();

        // Addition operator (+)
        LargeInt operator+(const LargeInt&);

        // Subtraction operator (-)
        LargeInt operator-(const LargeInt&);

        // Multiplication operator (*)
        LargeInt operator*(const LargeInt&);

        // Division operator (/)
        LargeInt operator/(const LargeInt&);

        // Modulo operator (%)
        LargeInt operator%(const LargeInt&);

        // Equality operator (==)
        bool operator==(const LargeInt&);

        // Less than operator (<)
        bool operator<(const LargeInt&);

        // Less than or equal to operator (<=)
        bool operator<=(const LargeInt&);

        // Greater than operator operator (>)
        bool operator>(const LargeInt&);

        // Greater than or equal to operator (>=)
        bool operator>=(const LargeInt&);

        // Insertion operator (<<)
        friend std::ostream& operator<<(std::ostream&, const LargeInt&);

        // Extraction operator (>>)
        friend std::istream& operator>>(std::istream&, LargeInt&);
};

#endif
