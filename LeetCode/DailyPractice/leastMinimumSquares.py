"""
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.

"""

"""
Solution 1, Loop from 1 to n. If the index number is not a perfect square, then loop from i - 1 to 1. Subtract the n number with
that index looping down. For that space in the array, add the min count of the index count + n - index count in the array.
"""

import math 
  
def isPerfectSquare(x): 
  
    # Find floating point value of  
    # square root of x. 
    sr = math.sqrt(x) 
   
    # If square root is an integer 
    return ((sr - math.floor(sr)) == 0)

def num_squares_sol1(n):

    memory = []
    memory.append(0)

    for i in range(1, n+1):
        min_val = 99999999
        if(isPerfectSquare(i)):
            memory.append(1)
        else:
            for j in range(i -1, 0, -1):
                best_so_far = memory[j] + memory[i - j]
                if(best_so_far < min_val):
                    min_val = best_so_far
            memory.append(min_val)

    return memory[-1]


def main():

    n = 13
    print(num_squares_sol1(n))


main()