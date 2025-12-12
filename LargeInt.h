/*
* Purpose:
*     This is the header file for the LargeInt class. The C++ language standard is C++20.
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

        // Normalizes the LargeInt
        void normalize();

    public:
        // Constructor
        LargeInt();

        // Destructor
        ~LargeInt();

        // Addition operator (+)
        LargeInt operator+(const LargeInt&) const;

        // Subtraction operator (-)
        LargeInt operator-(const LargeInt&) const;

        // Multiplication operator (*)
        LargeInt operator*(const LargeInt&) const;

        // Division operator (/)
        LargeInt operator/(const LargeInt&) const;

        // Modulo operator (%)
        LargeInt operator%(const LargeInt&) const;

        // Equality operator (==)
        bool operator==(const LargeInt&) const;

        // Less than operator (<)
        bool operator<(const LargeInt&) const;

        // Less than or equal to operator (<=)
        bool operator<=(const LargeInt&) const;

        // Greater than operator operator (>)
        bool operator>(const LargeInt&) const;

        // Greater than or equal to operator (>=)
        bool operator>=(const LargeInt&) const;

        // Insertion operator (<<)
        friend ostream& operator<<(ostream&, const LargeInt&);

        // Extraction operator (>>)
        friend istream& operator>>(istream&, LargeInt&);
};

#endif
