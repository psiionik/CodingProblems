"""
Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.

For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.

Can this be done in O(n) time and constant space?
"""

"""
Solution 1, Make a running sum array and use Dynamic programming to remember the best last thing. After the first two elements, will
choose between running_sum[n] = max(running_sum[n-1], running_sum[n-2] + elements[n].
"""

def find_largest_sum_non_adjacent_sol_1(numbers):
    running_sum = [0]*len(numbers)
    
    # Omitted checks for when array is length 0, 1, or 2 since that is trivial

    running_sum[0] = numbers[0]
    running_sum[1] = numbers[1]

    for i in range(2, len(numbers)):
        new_max = max(running_sum[i-1], running_sum[i-2] + numbers[i])
        if(i > 2):
            new_max = max(new_max, running_sum[i-3] + numbers[i])
        running_sum[i] = new_max

    return max(running_sum[-1], running_sum[-2])

"""
Solution 2, Look at the problem recursively. If there is a function that already returns the largest sum of non-adjacent integers on smaller
inputs, we can use that function from numbers[1:] and numbers[2:]. Use dynamic programming to store in the array, the largest sum
of non-adjacent numbers from index 0 up to that point. In this, we ever only use the last two elements of the cache when iterating through
the array. This suggests that we can get rid of most of the array and just store them as variables.
"""

def find_largest_sum_non_adjacent_sol_2(numbers):
    if len(numbers) <= 2:
        return max(0, max(numbers))

    max_excluding_last = max(0, numbers[0])
    max_including_last = max(max_excluding_last, numbers[1])

    for num in numbers[2:]:
        prev_max_including_last = max_including_last

        max_including_last = max(max_including_last, max_excluding_last + num)
        max_excluding_last = prev_max_including_last
    
    return max(max_including_last, max_excluding_last)

def main():
    """
    Test 1: Should return 13
    [2, 4, 6, 2, 5]
    """

    # numbers = [2, 4, 6, 2, 5]

    """
    Test 2: Should return 10
    [5, 1, 1, 5]
    """

    numbers = [5, 1, 1, 5]

    print(find_largest_sum_non_adjacent_sol_2(numbers))

main()