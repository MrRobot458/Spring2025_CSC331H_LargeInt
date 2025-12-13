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
    1. Comparison: first is greater  PASS
    2. 5 + 3 = 8                     PASS
    3. 5 - 3 = 2                     PASS
    4. 5 * 3 = 15                    PASS
    5. 5 / 3 = 1                     PASS
    6. 5 % 3 = 2                     PASS
*/

// Test Set 2: Equal Numbers
/*
Input: 42, 42
Expected Output:
    1. Comparison: same  PASS
    2. 42 + 42 = 84      PASS
    3. 42 - 42 = 0       PASS
    4. 42 * 42 = 1764    PASS
    5. 42 / 42 = 1       PASS
    6. 42 % 42 = 0       PASS
*/

// Test Set 3: Subtraction Resulting in 0 (Negative Guard)
/*
Input: 15, 20
Expected Output:
    1. Comparison: first is smaller      PASS
    2. 15 + 20 = 35                      PASS
    3. 15 - 20 = 0  (can't be negative)  PASS
    4. 15 * 20 = 300                     PASS
    5. 15 / 20 = 0                       PASS
    6. 15 % 20 = 15                      PASS
*/

// Test Set 4: Leading Zeros
/*
Input: 0007, 003
Expected Output:
    1. Comparison: first is greater  PASS
    2. 7 + 3 = 10                    PASS
    3. 7 - 3 = 4                     PASS
    4. 7 * 3 = 21                    PASS
    5. 7 / 3 = 2                     PASS
    6. 7 % 3 = 1                     PASS
*/

// Test Set 5: Operations with Zero
/*
Input: 100, 0
Expected Output:
    1. Comparison: first is greater               PASS
    2. 100 + 0 = 100                              PASS
    3. 100 - 0 = 100                              PASS
    4. 100 * 0 = 0                                PASS
    5. 100 / 0 = 0  (division by zero returns 0)  PASS
    6. 100 % 0 = 0  (modulo by zero returns 0)    PASS
*/

// Test Set 6: Multi-Digit with Carrying/Borrowing
/*
Input: 999, 1
Expected Output:
    1. Comparison: first is greater  PASS
    2. 999 + 1 = 1000                PASS
    3. 999 - 1 = 998                 PASS
    4. 999 * 1 = 999                 PASS
    5. 999 / 1 = 999                 PASS
    6. 999 % 1 = 0                   PASS
*/

// Test Set 7: Large Numbers (3-4 digits)
/*
Input: 1234, 567
Expected Output:
    1. Comparison: first is greater  PASS
    2. 1234 + 567 = 1801             PASS
    3. 1234 - 567 = 667              PASS
    4. 1234 * 567 = 699678           PASS
    5. 1234 / 567 = 2                PASS
    6. 1234 % 567 = 100              PASS
*/

// Test Set 8: Very Large Numbers (10+ digits)
/*
Input: 12345678901234, 98765432109876
Expected Output:
    1. Comparison: first is smaller                                    PASS
    2. 12345678901234 + 98765432109876 = 111111111011110               PASS
    3. 12345678901234 - 98765432109876 = 0                             PASS
    4. 12345678901234 * 98765432109876 = 1219326311370155158039986984  PASS
    5. 12345678901234 / 98765432109876 = 0                             PASS
    6. 12345678901234 % 98765432109876 = 12345678901234                PASS
*/

// Test Set 9: Stress Test (Really Large)
/*
Input: 99999999999999999999, 1
Expected Output:
    1. Comparison: first is greater                      PASS
    2. 99999999999999999999 + 1 = 100000000000000000000  PASS
    3. 99999999999999999999 - 1 = 99999999999999999998   PASS
    4. 99999999999999999999 * 1 = 99999999999999999999   PASS
    5. 99999999999999999999 / 1 = 99999999999999999999   PASS
    6. 99999999999999999999 % 1 = 0                      PASS
*/

// Test Set 10: 2nd Stress Test
/*
Input: 99999999999999999999, 12345678901234567890
Expected Output:
    1. Comparison: first is greater  PASS
    
    2. 99999999999999999999 + 12345678901234567890 = 112345678901234567889                     PASS
    3. 99999999999999999999 - 12345678901234567890 = 87654321098765432109                      PASS
    4. 99999999999999999999 * 12345678901234567890 = 1234567890123456788987654321098765432110  PASS
    5. 99999999999999999999 / 12345678901234567890 = 8                                         PASS
    6. 99999999999999999999 % 12345678901234567890 = 1234568790123456879                       PASS
*/
