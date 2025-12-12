/*
* Purpose:
*     This program tests the LargeInt class by performing arithmetic operations on two LargeInt values provided by the user.
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

int main() {
    LargeInt num1;  // Stores the first LargeInt given by the user
    LargeInt num2;  // Stores the 2nd LargeInt given by the user

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
