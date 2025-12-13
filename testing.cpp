/*
* Purpose:
*     Test case file for the LargeInt project.
*
*     PASS = successful evaluation of expression
*     FAIL = failed evaluation of expression
*
* Input: None.
* Output: None.
*/

//---- Main menu test cases ----//

// Test Set 1: Basic Functionality (Small Numbers)
/*
Input: 5, 3
Expected Output:
    1. Comparison: first is greater
    2. 5 + 3 = 8
    3. 5 - 3 = 2
    4. 5 * 3 = 15
    5. 5 / 3 = 1
    6. 5 % 3 = 2
*/

// Test Set 2: Equal Numbers
/*
Input: 42, 42
Expected Output:
    1. Comparison: same
    2. 42 + 42 = 84
    3. 42 - 42 = 0
    4. 42 * 42 = 1764
    5. 42 / 42 = 1
    6. 42 % 42 = 0
*/

// Test Set 3: Subtraction Resulting in 0 (Negative Guard)
/*
Input: 15, 20
Expected Output:
    1. Comparison: first is smaller
    2. 15 + 20 = 35
    3. 15 - 20 = 0  (can't be negative)
    4. 15 * 20 = 300
    5. 15 / 20 = 0
    6. 15 % 20 = 15
*/

// Test Set 4: Leading Zeros
/*
Input: 0007, 003
Expected Output:
    1. Comparison: first is greater
    2. 7 + 3 = 10
    3. 7 - 3 = 4
    4. 7 * 3 = 21
    5. 7 / 3 = 2
    6. 7 % 3 = 1
*/

// Test Set 5: Operations with Zero
/*
Input: 100, 0
Expected Output:
    1. Comparison: first is greater
    2. 100 + 0 = 100
    3. 100 - 0 = 100
    4. 100 * 0 = 0
    5. 100 / 0 = 0  (division by zero returns 0)
    6. 100 % 0 = 0  (modulo by zero returns 0)
*/

// Test Set 6: Multi-Digit with Carrying/Borrowing
/*
Input: 999, 1
Expected Output:
    1. Comparison: first is greater
    2. 999 + 1 = 1000
    3. 999 - 1 = 998
    4. 999 * 1 = 999
    5. 999 / 1 = 999
    6. 999 % 1 = 0
*/

// Test Set 7: Large Numbers (3-4 digits)
/*
Input: 1234, 567
Expected Output:
    1. Comparison: first is greater
    2. 1234 + 567 = 1801
    3. 1234 - 567 = 667
    4. 1234 * 567 = 699678
    5. 1234 / 567 = 2
    6. 1234 % 567 = 100
*/

// Test Set 8: Very Large Numbers (10+ digits)
/*
Input: 12345678901234, 98765432109876
Expected Output:
    1. Comparison: first is smaller
    2. 12345678901234 + 98765432109876 = 111111111011110
    3. 12345678901234 - 98765432109876 = 0
    4. 12345678901234 * 98765432109876 = 1219326311248285057237501384
    5. 12345678901234 / 98765432109876 = 0
    6. 12345678901234 % 98765432109876 = 12345678901234
*/

// Test Set 9: Stress Test (Really Large)
/*
Input: 99999999999999999999, 1
Expected Output:
    1. Comparison: first is greater
    2. 99999999999999999999 + 1 = 100000000000000000000
    3. 99999999999999999999 - 1 = 99999999999999999998
    4. 99999999999999999999 * 1 = 99999999999999999999
    5. 99999999999999999999 / 1 = 99999999999999999999
    6. 99999999999999999999 % 1 = 0
*/
