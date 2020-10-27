"""
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.
"""


def jumpGameSol1(nums):
    max_jump = 0
    ind = 0
    while(ind <= max_jump):
        max_jump = max(max_jump, nums[ind] + ind)
        if max_jump >= len(nums) - 1:
            return True
        ind += 1

    return False

def main():

    # Test 1: Should return true

    # nums = [2, 3, 1, 1, 4]

    # Test 2: Should return false

    nums = [3, 2, 1, 0, 4]


    print(jumpGameSol1(nums))


main()