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
LargeInt LargeInt::operator+(const LargeInt& other) {
    LargeInt result;                                // Result of the addition operation
    DoublyLinkedList<int>::Iterator it1 = nullptr;  // Iterator for this LargeInt
    DoublyLinkedList<int>::Iterator it2 = nullptr;  // Iterator for the other LargeInt
    DoublyLinkedList<int>::Iterator end = nullptr;  // Iterator endpoint
    int sum = 0;                                    // Stores the current sum of two digits
    int carry = 0;                                  // Stores the carry amount

    // Set the iterators and endpoint
    it1 = this->digits.revBegin();
    it2 = const_cast<LargeInt&>(other).digits.revBegin();
    end = this->digits.revEnd();

    // Empty the result's digits 
    result.digits.deleteItem(0);

    // Iterate
    while (it1 != end || it2 != end || carry > 0) {
        // Add carry and current digits
        sum = carry;

        if (it1 != end) {
            sum += *it1;
            --it1;
        }
        if (it2 != end) {
            sum += *it2;
            --it2;
        }
        // Add digit to result and set carry
        result.digits.insertFirst(sum % 10);
        carry = sum / 10;
    }
    // Normalize the result
    result.normalize();
    return result;
}

// Subtraction operator (-)
LargeInt LargeInt::operator-(const LargeInt& other) {
    LargeInt result;                                // Result of the subtraction operation
    DoublyLinkedList<int>::Iterator it1 = nullptr;  // Iterator for this LargeInt
    DoublyLinkedList<int>::Iterator it2 = nullptr;  // Iterator for the other LargeInt
    DoublyLinkedList<int>::Iterator end = nullptr;  // Iterator endpoint
    int diff = 0;                                   // Stores the current difference of two digits
    int borrow = 0;                                 // Stores the borrow amount

    // Set the iterators and endpoint
    it1 = this->digits.revBegin();
    it2 = const_cast<LargeInt&>(other).digits.revBegin();
    end = this->digits.revEnd();

    // Empty the result's digits 
    result.digits.deleteItem(0);

    // Check if the other operand is equal or less
    if (*this >= other) {
        // Iterate
        while (it1 != end) {
            // Subtract borrow from current digit
            diff = *it1 - borrow;

            if (it2 != end) {
                diff -= *it2;
                --it2;
            }
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            }
            else borrow = 0;

            // Add digit to result
            result.digits.insertFirst(diff);
            --it1;
        }
        // Normalize the result
        result.normalize();
    }
    else result.digits.insertFirst(0);
    return result;
}

// Multiplication operator (*)
LargeInt LargeInt::operator*(const LargeInt& other) {
    LargeInt result;  // Result of the multiplication operation
    LargeInt temp;    // Stores the temporary digits of a product

    DoublyLinkedList<int>::Iterator it1 = nullptr;   // Iterator for this LargeInt
    DoublyLinkedList<int>::Iterator it2 = nullptr;   // Iterator for the other LargeInt
    DoublyLinkedList<int>::Iterator end1 = nullptr;  // Endpoint for this LargeInt
    DoublyLinkedList<int>::Iterator end2 = nullptr;  // Endpoint for the other LargeInt

    int multiplier = 0;  // Stores the current multiplier
    int product = 0;     // Stores the temporary product
    int carry = 0;       // Stores the carry amount
    int position = 0;    // Stores the current digit's position 

    // Set the initial result
    result.digits.deleteItem(0);
    result.digits.insertFirst(0);

    // Set iterator and endpoint for the other LargeInt
    it2 = const_cast<LargeInt&>(other).digits.revBegin();
    end2 = const_cast<LargeInt&>(other).digits.revEnd();

    // Iterate
    while (it2 != end2) {
        // Set the current multiplier and temporary digits
        multiplier = *it2;
        temp = LargeInt();
        temp.digits.deleteItem(0);

        // Add trailing zeros to temporary digits
        for (int i = 0; i < position; i++) {
            temp.digits.insertLast(0);
        }
        // Set the carry, and the iterator and endpoint of this LargeInt
        it1 = this->digits.revBegin();
        end1 = this->digits.revEnd();
        carry = 0;

        while (it1 != end1 || carry > 0) {
            // Set current product
            product = carry;

            if (it1 != end1) {
                product += (*it1) * multiplier;
                --it1;
            }
            // Update temporary digits and carry
            temp.digits.insertFirst(product % 10);
            carry = product / 10;
        }
        // Update the result
        result = result + temp;

        --it2;
        position++;
    }
    // Normalize the result
    result.normalize();
    return result;
}

// Division operator (/)
LargeInt LargeInt::operator/(const LargeInt& other) {
    LargeInt result;                                // Result of the division operation
    LargeInt dividend;                              // Stores the dividend's digits
    DoublyLinkedList<int>::Iterator it = nullptr;   // Iterator for this LargeInt
    DoublyLinkedList<int>::Iterator end = nullptr;  // Endpoint for this LargeInt  
    int quotientDigit = 0;                          // Stores the quotient's current digit

    // Empty the result's digits 
    result.digits.deleteItem(0);

    // Validate other LargeInt and size
    if ((other == LargeInt()) || (*this < other)) {
        result.digits.insertFirst(0);
    }
    else {
        // Empty the dividend's digits
        dividend.digits.deleteItem(0);

        // Set the iterator and endpoint
        it = this->digits.begin();
        end = this->digits.end();

        // Iterate
        while (it != end) {
            // Set current state of dividend 
            dividend.digits.insertLast(*it);
            dividend.normalize();

            // Set the quotient's digit
            quotientDigit = 0;

            while (dividend >= other) {
                dividend = dividend - other;
                quotientDigit++;
            }
            // Append digit to result
            result.digits.insertLast(quotientDigit);
            ++it;
        }
        // Normalize the result
        result.normalize();
    }
    return result;
}

// Modulo operator (%)
LargeInt LargeInt::operator%(const LargeInt& other) {
    LargeInt quotient;   // Quotient of both LargeInt's
    LargeInt product;    // Product of quotient and other LargeInt
    LargeInt remainder;  // Remainder of the modulo operation

    // Modulo
    quotient = *this / other;
    product = quotient * other;
    remainder = *this - product;
    return remainder;
}

// Equality operator (==)
bool LargeInt::operator==(const LargeInt&) {}

// Less than operator (<)
bool LargeInt::operator<(const LargeInt&) {}

// Less than or equal to operator (<=)
bool LargeInt::operator<=(const LargeInt&) {}

// Greater than operator operator (>)
bool LargeInt::operator>(const LargeInt&) {}

// Greater than or equal to operator (>=)
bool LargeInt::operator>=(const LargeInt&) {}

// Insertion operator (<<)
ostream& operator<<(ostream&, const LargeInt&) {}

// Extraction operator (>>)
istream& operator>>(istream&, LargeInt&) {}
