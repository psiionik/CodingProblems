"""
You are given an array of non-negative integers that represents a two-dimensional elevation map where each element is unit-width
wall and the integer is the height. Suppose it will rain and all spots between two walls get filled up.

Compute how many units of water remain trapped on the map in O(N) time and O(1) space.

For example, given the input [2, 1, 2], we can hold 1 unit of water in the middle.

Given the input [3, 0, 1, 3, 0, 5], we can hold 3 units in the first index, 2 in the second, and 3 in the
fourth index (we cannot hold 5 since it would run off to the left), so we can trap 8 units of water.
"""

"""
Solution 1, Use the max value as a pivot. Recurse on two sublists where left has the max value and right doesn't. Do this until
the first and the last value in the sublist are the biggest ones in the list.
Keep a variable for the second biggest maximum value in the sublists. For any
elements that are smaller than that second max in sublist, subtract the max so far with that element and add to the
total units of water.
Runtime: O(n), Space: O(1).
"""


def max_water_units_sol1(arr):
    total_units = 0
    bool_temp = False
    if(len(arr) == 2):
        max_val = max(arr)
        min_val = min(arr)
        return max_val-min_val

    for i in range(1, len(arr)-1):
        if (arr[i] > arr[-1] or arr[i] > arr[0]):
            bool_temp = True
    
    for i in range(1, len(arr)-1):
        if(bool_temp):
            index = arr.index(max(arr))
            left = arr[:index+1]
            right = arr[index+1:]
            
            max_water_units_sol1(left)
            max_water_units_sol1(right)
        else:
            smaller_max = min(arr[0], arr[-1])
            total_units += smaller_max - arr[i]
    
    return total_units
    
"""
Solution 2, Can find the largest element in the array, and then when looking to the left of it, only need to keep the running total
to the left (since we know the largest element on the array is to the right). Do the same thing from the right.
Generally:
    1. Find the maximum element in the array -- lets say index i
    2. Initialize a running maximum on the left to arr[0]
    3. Iterate from 1 to i, At each step, update the running maximum if necessary and then increment a variable counter
        with the running maximum minus the value at the array
    4. Do the same thing but from len(arr) - 2 to i backwards, keeping the running maximum on the right
"""

def max_water_units_sol2(arr):
    if not arr:
        return 0
    
    total = 0
    max_i = arr.index(max(arr))

    left_max = arr[0]
    for num in arr[1:max_i]:
        total += left_max - num
        left_max = max(left_max, num)
    
    right_max = arr[-1]
    for num in arr[-2:max_i:-1]:
        total += right_max - num
        right_max = max(right_max, num)

    return total

def main():
    
    # Test 1: Should return 1

    # arr = [2, 1, 2]

    # Test 2: Should return 8

    # arr = [3, 0, 1, 3, 0, 5]

    # Test 3: Should return 9

    # arr = [3, 0, 1, 2, 0, 5]

    # Test 4: Should return 31

    arr = [3, 20, 1, 10, 0, 5]

    print(max_water_units_sol2(arr))

main()