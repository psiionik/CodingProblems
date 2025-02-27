"""
A builder is looking to build a row of N houses that can be of K different colors. He has a goal of minimizing cost while ensuring that
no two neighboring houses are of the same color.

Given an N by K matrix where the nth row and kth column represents the cost to build the nth house with kth color, return the minimum
cost which achieves this goal.
"""

"""
Solution 1, Use dynamic programming to keep track of the smallest cost so far and the color of the n houses. Going to loop through the
n houses with k colors. Keep a separate 2d array of the same size that keeps tracks of the min cost of coloring that house with
color k. For example, at cell [3][5], this cell will hold the min sum of the cost to color house 3 with color 5 + the minimum cost
in house 2 not including the the cost to color house 2 with color 5. At the end, the last row should contain the min sum cost and just
pick the smallest number in the last row. This runs in O(N * K^2) time and O(N*K) space.
"""

from math import inf

def n_houses_of_k_color_sol1(matrix):
    memory = [[0 for i in range(len(matrix[0]))] for j in range(len(matrix))]
    
    for row in range(len(matrix)):
        for col in range(len(matrix[0])):
            if(row == 0):
                memory[row][col] = matrix[row][col]
            else:
                minVal = 99999999
                currentKth = col
                for color in range(len(matrix[0])):
                    if color == currentKth:
                        continue
                    else:
                        if memory[row-1][color] < minVal:
                            minVal = memory[row-1][color]
                memory[row][col] = minVal + matrix[row][col]
    
    return min(memory[-1])

"""
Solution 2, Do the same as above, just optimize it so that we don't use an N*K size matrix. Since we only ever look at the last row
every time we iterate, we can just keep one array the size of k.
"""

"""
Solution 3, Do the same as above, just optimize it to keep track of the lowest cost of the current row, the index of the lowest cost,
and the second lowest cost. Then when looking at the value of each row, only need to:

1. Check if the index is the index of the lowest cost in the previous row, if it is then we can't use this color and can only use
the second lowest cost color instead.

2. Calculate the minimum cost if we painted this house this particular color

3. Update our new lowest cost index or second lowest cost if appropriate

Always have the lowest cost in a variable, and once we've gone through the matrix, we can just return that.

Runtime is O(N*K) and the space complexity is O(1) - constant for the variables.
"""


def n_houses_of_k_color_sol3(matrix):
    lowest_cost, lowest_cost_index = 0, -1
    second_lowest_cost = 0

    for r, row in enumerate(matrix):
        new_lowest_cost, new_lowest_cost_index = inf, -1
        new_second_lowest_cost = inf
        for c, val in enumerate(row):
            prev_lowest_cost = second_lowest_cost if c == lowest_cost_index else lowest_cost
            cost = prev_lowest_cost + val
            if cost < new_lowest_cost:
                new_second_lowest_cost = new_lowest_cost
                new_lowest_cost, new_lowest_cost_index = cost, c
            elif cost < new_second_lowest_cost:
                new_second_lowest_cost = cost
        lowest_cost = new_lowest_cost
        lowest_cost_index = new_lowest_cost_index
        second_lowest_cost = new_second_lowest_cost

    return lowest_cost

def main():
    """
    Test 1: Should return 22
    """

    # matrix = [[10, 20, 40], [14, 10, 3], [35, 9, 6]]

    """
    Test 2: Should return 17
    """

    matrix = [[10, 20, 40, 5], [14, 10, 3, 1], [35, 10, 6, 45]]

    print(n_houses_of_k_color_sol3(matrix))

main()