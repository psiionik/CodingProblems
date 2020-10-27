"""
We can determine how "out of order" an array A is by counting the number of inversions it has.
Two elements A[i] and A[j] form an inversion if A[i] > A[j] but i < j. That is, a smaller element appears after a larger element.

Given an array, count the number of inversions it has. Do this faster than O(N^2) time.

You may assume each element in the array is distinct.

For example, a sorted list has zero inversions. The array [2, 4, 1, 3, 5] has three inversions:
(2, 1), (4, 1), and (4, 3). The array [5, 4, 3, 2, 1] has ten inversions: every distinct pair forms an inversion.
"""

"""
Solution 1, Use a divide and conquer approach.
First separate the input array into two halves A and B.
Count the number of inversions in each list recursively.
Count the inversions between A and B.
Return the sum of all three counts.

If we sort the array, we can use a technique similar to that of mergesort to merge and count the inversions between A and B.
Assuming A and B are sorted, we can construct a helper function that does the following:
    * Scan A and B left to right, with two pointers i and j
    * Compare A[i] and B[j]
        * If A[i] < B[j] then A[i] is not inverted with anything from B since it is expected that everything in A would be smaller
            * than everything in B if A + B were sorted
        * If A[i] > B[j] then B[j] is inverted with everything from A[i:] since A is sorted.
            * increment the counter by the number of elements in A[i:]
    * Append the smaller element between A[i] and B[j] to the sorted list
    * Return the sorted list
"""

def count_inversions(arr):
    count, _ = count_inversions_helper(arr)
    return count

def count_inversions_helper(arr):
    if (len(arr) <= 1):
        return 0, arr
    
    mid = len(arr) // 2
    a = arr[:mid]
    b = arr[mid:]

    left_count, left_sorted_arr  = count_inversions_helper(a)
    right_count, right_sorted_arr = count_inversions_helper(b)
    between_count, sorted_arr = merge_and_count(left_sorted_arr, right_sorted_arr)
    return left_count + right_count + between_count, sorted_arr

def merge_and_count(a, b):
    count = 0
    sorted_arr = []
    i, j = 0, 0
    while i < len(a) and j < len(b):
        if a[i] < b[j]:
            sorted_arr.append(a[i])
            i += 1
        elif a[i] > b[j]:
            sorted_arr.append(b[j])
            count += len(a) - i
            j += 1
    sorted_arr.extend(a[i:])
    sorted_arr.extend(b[j:])
    return count, sorted_arr

def main():

    # Test 1: Should return 3
    # arr = [2, 4, 1, 3, 5]

    # Test 2: Should return 10
    # arr = [5, 4, 3, 2, 1]

    # Test 3: Should return 0
    arr = [1, 2, 3, 4, 5]


    print(count_inversions(arr))


main()