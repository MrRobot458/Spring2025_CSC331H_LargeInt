/*
* Purpose:
*     This program tests the LargeInt class by performing arithmetic operations on two LargeInt values provided by the user.
*     Rules regarding the LargeInt type:
*         1. LargeInt type is unsigned and non-negative (>= 0).
*         2. In subtraction, the LargeInt being subtracted from must be greater. If not, the result of the subtraction will be
*            zero in order to maintain rule #1. This is temporary and will be improved later.
*         3. Currently, division by zero will return a result of zero (0) instead of appropriately throwing an error. This will
*            also be improved later.
* 
* Input:
*     1. First LargeInt value provided by the user.
*     2. Second LargeInt value provided by the user.
*
* Output:
*     1. The results of each arithmetic operation performed on the large integers.
*/

#include "LargeInt.h"
#include <iostream>

using namespace std;

//---- Main program ----//
int main() {
    LargeInt num1;  // First LargeInt given by the user
    LargeInt num2;  // Second LargeInt given by the user

    // Get the LargeInt values from the user
    cout << "\nEnter the first large integer: ";
    cin >> num1;

    cout << "\nEnter the second large integer: ";
    cin >> num2;

    // Compare the two LargeInt values
    if (num1 == num2)
        cout << "\n\nThe two large integers are the same";
    else if (num1 > num2)
        cout << "\n\nThe first large integer is greater";
    else if (num1 < num2)
        cout << "\n\nThe first large integer is smaller";

    // Output the results of the arithmetic operations
    cout << "\n\n" << num1 << " + " << num2 << " = " << (num1 + num2);

    cout << "\n\n" << num1 << " - " << num2 << " = " << (num1 - num2);

    cout << "\n\n" << num1 << " * " << num2 << " = " << (num1 * num2);

    cout << "\n\n" << num1 << " / " << num2 << " = " << (num1 / num2);

    cout << "\n\n" << num1 << " % " << num2 << " = " << (num1 % num2);
    
    return 0;
}
