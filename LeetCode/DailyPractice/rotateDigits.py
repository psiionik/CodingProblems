"""
X is a good number if after rotating each digit individually by 180 degrees,
we get a valid number that is different from X.  Each digit must be rotated - we cannot choose to leave it alone.

A number is valid if each digit remains a digit after rotation. 0, 1, and 8 rotate to
themselves; 2 and 5 rotate to each other; 6 and 9 rotate to each other, and the rest of the
numbers do not rotate to any other number and become invalid.

Now given a positive number N, how many numbers X from 1 to N are good?

Example:
Input: 10
Output: 4
Explanation: 
There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.
"""

def rotatedDigits(N):
    count = 0
    for num in range(1, N + 1):
        valid = True
        isDifferent = False
        num_str = str(num)
        for char in num_str:
            if char == "3" or char =="4" or char =="7":
                valid = False
            if char == "2" or char == "5" or char == "6" or char == "9":
                isDifferent = True
        
        if valid and isDifferent:
            count += 1

    return count

def main():

    # Test 1: Should return 4
    # N = 10

    # Test 2: Should return 247
    N = 857

    print(rotatedDigits(N))

main()