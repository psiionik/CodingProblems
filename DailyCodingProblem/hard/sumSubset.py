"""
Given a list of integers S and a target number k, write a function that returns a subset of S that adds up to k.
If such a subset cannot be made, then return null.

Integers can appear more than once in the list. You may assume all numbers in the list are positive.

For example, given S = [12, 1, 61, 5, 9, 2] and k = 24, return [12, 9, 2, 1] since it sums up to 24.
"""

"""
Solution 1, Brute Force through all possibilities using backtracking.
Can implicitly compute the sum by choose whether to pick based on looking recursively for k - last in the remaining part
of the list, or exclude the element and keep on looking for k in the remaining part of the list recursively.
"""

def sum_subset_sol1(arr, k):
    if k == 0:
        return []
    if not arr and k != 0:
        return None
    
    nums_copy = arr[:]
    last = nums_copy.pop()

    with_last = sum_subset_sol1(nums_copy, k - last)
    without_last = sum_subset_sol1(nums_copy, k)
    if with_last is not None:
        return with_last + [last]
    if without_last is not None:
        return without_last

"""
Solution 2, Use dynamic programming by building it bottom-up.

Construct a table A that is size len(nums) + 1 by k + 1.
At each index A[i][j], keep a subset of the list from 0..i (including lower, excluding upper bound) that can add up to j
or null if no list can be made.
Then we can fill the table with pre-computed values and once we're done, we should be able to return the value A[-1][-1].

To begin, we can initialize each element of the first row (A[i][0]) with the empty list since any subset of the list can
make 0.

Each element of the first column (A[0][j]) should be None since we can't make anything other than 0 with the empty set.

Now can start populating the table. Iterate over row = 1 to end and col = 1 to end.
Use the following formula to compute A[i][j]:
    1. Consider the last element being looked at (nums[i - 1]) called last
    2. If last is > j, then we can't make j with nums[:i] including last since it would go over. So just copy over what
        was in A[i-1][j] to that cell.
    3. If last is <= j then we might be able to make j with last
        - If we can make j without last, we can look up value in A[i-1][j] and if not null, we can use that
        - Else, if we can't make j without last, check if we can make it with last by looking up the value at A[i-1][j-last]
            If we can, then copy over the list from there and append the last element to it
        - Else, we can't make it with or without j, so set it to None
"""

def sum_subset_sol2(nums, k):
    A = [[None for _ in range(k + 1)] for _ in range(len(nums) + 1)]

    for i in range(len(nums) + 1):
        A[i][0] = []

    for i in range(1, len(nums) + 1):
        for j in range(1, k + 1):
            last = nums[i - 1]
            if last > j:
                A[i][j] = A[i-1][j]
            else:
                if A[i-1][j] is not None:
                    A[i][j] = A[i-1][j]
                elif A[i-1][j-last] is not None:
                    A[i][j] = A[i-1][j-last] + [last]
                else:
                    A[i][j] = None
    print(to_string(A))
    return A[-1][-1]

def to_string(given_array):
    list_rows = []
    for row in given_array:
        list_rows.append(str(row))
    return '[' + ',\n '.join(list_rows) + ']'

def main():

    # Test 1: Should return [12, 9, 2, 1]

    arr = [12, 1, 61, 5, 9, 2]

    k = 13

    print(sum_subset_sol2(arr, k))

main()