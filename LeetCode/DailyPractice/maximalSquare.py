"""
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
"""

"""
Brute Force Solution: Look at every 1 in the matrix and use BFS to traverse through every single adjacent 1 in a square fashion
to find the largest square.
"""

"""
Solution 1, Dynamic Programming. Make another matrix dj of the same size as the original matrix, initialized with all 0s.
For each cell in the dp matrix, take the min of the top, left, and top left and add 1 to it since each cell represents the max
length possible for a square to be formed there. Keep track of the max value as you go.
Just take the square of that max value found so far at the end.
"""

def maximalSquare(matrix):
    dp = [[0 for _ in range(len(matrix[0]))] for _ in range(len(matrix))]
    current_max = 0
    for row in range(0, len(matrix)):
        dp[row][0] = matrix[row][0]
    for col in range(0, len(matrix[0])):
        dp[0][col] = matrix[0][col]
    
    for row in range(1, len(matrix)):
        for col in range(1, len(matrix[0])):
            if (matrix[row][col] == 1):
                value = min(dp[row-1][col-1], dp[row-1][col], dp[row][col-1]) + 1
                if (value > current_max):
                    current_max = value
                dp[row][col] = value
    
    return current_max * current_max


def main():

    # Test 1: Should return 4
    # matrix = [[1, 0, 1, 0, 0], [1, 0, 1, 1, 1], [1, 1, 1, 1, 1], [1, 0, 0, 1, 0]]

    # Test 2: Should return 9
    matrix = [[1, 0, 1, 0, 0], [0, 0, 1, 1, 1], [1, 1, 1, 1, 1], [1, 0, 1, 1, 1]]

    print(maximalSquare(matrix))

main()
