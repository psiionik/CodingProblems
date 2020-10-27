"""
Given an array of integers where every integer occurs three times except for one integer,
which only occurs once, find and return the non-duplicated integer.

For example, given [6, 1, 3, 3, 3, 6, 6], return 1. Given [13, 19, 13, 13], return 19.

Do this in O(N) time and O(1) space.
"""

"""
Solution 1, Can find the unique number in an array of two duplicates by XORing all the numbers in the array.
This cancels all the bits that have an even number of 1s, leaving the unique (odd) bits out.

For three duplicates, we want to cancel out those that have a number of bits that are a multiple of three.
Assuming all integers fit in 32 bits, create an array that is 32 zeros long. When iterating over each number,
add up all the bits to its proper spot in the array.
Go over each bit in the array and make it equal to mod 3.
This means that any bit that has been set some multiple of 3 will be cleared, leaving the bit only from the unique number.

This runs in O(n) time and since we initialize an array of constant size, this has constant space.
"""

def find_non_dup_sol1(arr):
    result_arr = [0] * 32
    for num in arr:
        for i in range(0, 32):
            bit = num >> i & 1
            result_arr[i] = (result_arr[i] + bit) % 3

    result = 0
    for i, bit in enumerate(result_arr):
        if bit:
            result += 2 ** i
    
    return result

def main():

    # Test 1: Should return 1

    # arr = [6, 1, 3, 3, 3, 6, 6]

    # Test 2: Should return 19

    arr = [13, 13, 19, 13]

    print(find_non_dup_sol1(arr))

main()